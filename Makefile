C_SOURCES = $(wildcard drivers/*.c)
HEADERS = $(wildcard drivers/*.h)

OBJ = ${C_SOURCES:.c=.o} 

GCC_FLAGS = -ffreestanding -Wall -Wextra -m32 -masm=intel

all: naos.iso
	cp build/naos.bin build/boot/naos.bin

build/bootsect.o: boot/bootsect.asm
	nasm -f elf32 boot/bootsect.asm -o build/bootsect.o

build/kernel.o: kernel/kernel.c
	gcc -c kernel/kernel.c -o build/kernel.o ${GCC_FLAGS}

kernel.bin: build/kernel.o build/bootsect.o ${OBJ}
	gcc -T boot/linker.ld -o build/naos.bin -ffreestanding -nostdlib $^ -m32 

naos.iso: kernel.bin
	grub-mkrescue -o naos.iso build

# Generic rules for wildcards
# To make an object, always compile from its .c
%.o: %.c ${HEADERS}
	gcc ${CFLAGS} -c $< -o $@

clean:
	rm -rf naos.iso
	rm -rf drivers/*.o build/*.o build/*.bin