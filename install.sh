python -m pip install virtualenv
virtualenv env
source env/bin/activate && python -m pip install cpplint && source env/bin/deactivate && docker run --rm --name viewify_installer -w C:/viewify -v $PWD:C:/viewify viewify-custom-node ncu.cmd -u && npm.cmd install
