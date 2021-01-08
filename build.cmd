docker run --rm --name viewify_debug_x86_builder -w C:\viewify -v %CD%:C:\viewify ms-build-tools msbuild C:\viewify\viewify\viewify.sln /p:Configuration=Debug /p:Platform=x86
docker run --rm --name viewify_debug_x64_builder -w C:\viewify -v %CD%:C:\viewify ms-build-tools msbuild C:\viewify\viewify\viewify.sln /p:Configuration=Debug /p:Platform=x64
docker run --rm --name viewify_release_x86_builder -w C:\viewify -v %CD%:C:\viewify ms-build-tools msbuild C:\viewify\viewify\viewify.sln /p:Configuration=Release /p:Platform=x86
docker run --rm --name viewify_release_x64_builder -w C:\viewify -v %CD%:C:\viewify ms-build-tools msbuild C:\viewify\viewify\viewify.sln /p:Configuration=Release /p:Platform=x64
