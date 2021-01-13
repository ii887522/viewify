python -m pip install virtualenv
virtualenv env
env\Scripts\activate && python -m pip install cpplint && env\Scripts\deactivate && docker run --rm --name viewify_installer -w C:\viewify -v %CD%:C:\viewify viewify-custom-node ncu.cmd -u && npm.cmd install
