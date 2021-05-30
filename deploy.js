'use strict'

import fsExtra from 'fs-extra'
import archiver from 'archiver'
import octokitRequest from '@octokit/request'

const { ensureDirSync, createWriteStream, copy, remove, readFile } = fsExtra
const { request } = octokitRequest

const version = process.argv[2]
const accessToken = process.argv[3]

async function bundleInclude() {
  ensureDirSync(`libs/viewify-${version}/include/viewify/`)
  return copy('viewify/src/main/', `libs/viewify-${version}/include/viewify/`, { recursive: true, filter: (src, dest) => {
    return !src.endsWith('.cpp')
  } })
}

async function bundleX86Debug() {
  ensureDirSync(`libs/viewify-${version}/lib/x86/Debug/`)
  return copy('viewify/Debug/viewify.lib', `libs/viewify-${version}/lib/x86/Debug/viewify.lib`)
}

async function bundleX86Release() {
  ensureDirSync(`libs/viewify-${version}/lib/x86/Release/`)
  return copy('viewify/Release/viewify.lib', `libs/viewify-${version}/lib/x86/Release/viewify.lib`)
}

async function bundleX64Debug() {
  ensureDirSync(`libs/viewify-${version}/lib/x64/Debug/`)
  return copy('viewify/x64/Debug/viewify.lib', `libs/viewify-${version}/lib/x64/Debug/viewify.lib`)
}

async function bundleX64Release() {
  ensureDirSync(`libs/viewify-${version}/lib/x64/Release/`)
  return copy('viewify/x64/Release/viewify.lib', `libs/viewify-${version}/lib/x64/Release/viewify.lib`)
}

async function bundleX86() {
  return Promise.all([
    bundleX86Debug(),
    bundleX86Release()
  ])
}

async function bundleX64() {
  return Promise.all([
    bundleX64Debug(),
    bundleX64Release()
  ])
}

async function bundleLib() {
  return Promise.all([
    bundleX86(),
    bundleX64()
  ])
}

async function bundle() {
  return Promise.all([
    bundleInclude(),
    bundleLib()
  ])
}

async function zip() {
  const archive = archiver('zip', { zlib: { level: 9 } })
  archive.on('warning', err => {
    if (err.code == 'ENOENT') console.log(err)
    else throw err
  }).on('error', err => {
    throw err
  }).pipe(createWriteStream(`libs/viewify-${version}.zip`))
  return archive.directory(`libs/viewify-${version}/`, `viewify-${version}/`).finalize()
}

async function publish() {
  const result = await request('POST /repos/{owner}/{repo}/releases', {
    headers: {
      authorization: `token ${accessToken}`
    },
    owner: 'ii887522',
    repo: 'viewify',
    tag_name: `v${version}`,
    name: `${version}`
  })
  return request('POST /repos/{owner}/{repo}/releases/{release_id}/assets{?name,label}', {
    headers: {
      authorization: `token ${accessToken}`,
      'content-type': 'application/zip'
    },
    baseUrl: 'https://uploads.github.com',
    owner: 'ii887522',
    repo: 'viewify',
    release_id: result.data.id,
    name: `viewify-${version}.zip`,
    data: await readFile(`libs/viewify-${version}.zip`)
  })
}

function clean() {
  remove(`libs/viewify-${version}`)
  remove(`libs/viewify-${version}.zip`)
}

(async () => {
  await bundle()
  await zip()
  await publish()
  clean()
})()
