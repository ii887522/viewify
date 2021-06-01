'use strict'

import fsExtra from 'fs-extra'
import archiver from 'archiver'
import octokitRequest from '@octokit/request'

const { ensureDirSync, createWriteStream, copy, remove, readFile } = fsExtra
const { request } = octokitRequest

const version = process.argv[2]
const accessToken = process.argv[3]
const projectName = 'viewify'
const staticLibExtensionName = '.lib'
const bundleOutDirPath = 'libs/'
const archiveExtensionName = 'zip'

async function bundleInclude() {
  const includeDirPath = `${bundleOutDirPath}${projectName}-${version}/include/`
  ensureDirSync(`${includeDirPath}${projectName}/`)
  return copy(`${projectName}/src/main/`, `${includeDirPath}${projectName}/`, { recursive: true, filter: (src, dest) => {
    return !src.endsWith('.cpp')
  } })
}

async function bundleX86Debug() {
  const x86DebugDirPath = `${bundleOutDirPath}${projectName}-${version}/lib/x86/Debug/`
  ensureDirSync(x86DebugDirPath)
  return copy(`${projectName}/Debug/${projectName}${staticLibExtensionName}`, `${x86DebugDirPath}${projectName}${staticLibExtensionName}`)
}

async function bundleX86Release() {
  const x86ReleaseDirPath = `${bundleOutDirPath}${projectName}-${version}/lib/x86/Release/`
  ensureDirSync(x86ReleaseDirPath)
  return copy(`${projectName}/Release/${projectName}${staticLibExtensionName}`, `${x86ReleaseDirPath}${projectName}${staticLibExtensionName}`)
}

async function bundleX64Debug() {
  const x64DebugDirPath = `${bundleOutDirPath}${projectName}-${version}/lib/x64/Debug/`
  ensureDirSync(x64DebugDirPath)
  return copy(`${projectName}/x64/Debug/${projectName}${staticLibExtensionName}`, `${x64DebugDirPath}${projectName}${staticLibExtensionName}`)
}

async function bundleX64Release() {
  const x64ReleaseDirPath = `${bundleOutDirPath}${projectName}-${version}/lib/x64/Release/`
  ensureDirSync(x64ReleaseDirPath)
  return copy(`${projectName}/x64/Release/${projectName}${staticLibExtensionName}`, `${x64ReleaseDirPath}${projectName}${staticLibExtensionName}`)
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
  const archive = archiver(archiveExtensionName, { zlib: { level: 9 } })
  archive.on('warning', err => {
    if (err.code == 'ENOENT') console.log(err)
    else throw err
  }).on('error', err => {
    throw err
  }).pipe(createWriteStream(`${bundleOutDirPath}${projectName}-${version}.${archiveExtensionName}`))
  return archive.directory(`${bundleOutDirPath}${projectName}-${version}/`, `${projectName}-${version}/`).finalize()
}

async function publish() {
  const owner = 'ii887522'
  const result = await request('POST /repos/{owner}/{repo}/releases', {
    headers: {
      authorization: `token ${accessToken}`
    },
    owner,
    repo: projectName,
    tag_name: `v${version}`,
    name: version
  })
  return request('POST /repos/{owner}/{repo}/releases/{release_id}/assets{?name,label}', {
    headers: {
      authorization: `token ${accessToken}`,
      'content-type': 'application/zip'
    },
    baseUrl: 'https://uploads.github.com',
    owner,
    repo: projectName,
    release_id: result.data.id,
    name: `${projectName}-${version}.${archiveExtensionName}`,
    data: await readFile(`${bundleOutDirPath}${projectName}-${version}.${archiveExtensionName}`)
  })
}

(async () => {
  await bundle()
  await zip()
  await publish()
  remove(bundleOutDirPath)
})()
