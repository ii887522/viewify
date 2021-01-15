if !docker image inspect ms-build-tools; then
  docker build -t ms-build-tools:latest .
fi
