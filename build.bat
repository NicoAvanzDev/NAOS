docker run --name naos-buildenv-i386 --rm -it -d -v %cd%:/root/env buildenv-i386
docker exec -it naos-buildenv-i386 sh -c "make clean"
docker exec -it naos-buildenv-i386 sh -c "make"
