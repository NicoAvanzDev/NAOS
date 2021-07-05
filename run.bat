docker run --name buildenv-x86_64 --rm -it -d -v %cd%:/root/env naosbuildenv
docker exec -it buildenv-x86_64 sh -c "make clean"
docker exec -it buildenv-x86_64 sh -c "make"
qemu-system-x86_64 ./os-image.bin