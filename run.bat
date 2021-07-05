docker run --name buildenv-i386 --rm -it -d -v %cd%:/root/env naosbuildenv
docker exec -it buildenv-i386 sh -c "make clean"
docker exec -it buildenv-i386 sh -c "make"
qemu-system-i386 -drive file=os-image.bin,format=raw,media=disk