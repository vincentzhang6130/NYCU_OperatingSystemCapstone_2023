
clean:
	rm -rf *.o *.img

a.o:
	aarch64-linux-gnu-gcc -g -c a.S -o a.o

main.c:
	aarch64-linux-gnu-gcc -g -c main.c -o main.o

kernel8.elf: a.o
	aarch64-linux-gnu-ld -T linker.ld a.o -o kernel8.elf

kernel8.img: kernel8.elf
	aarch64-linux-gnu-objcopy kernel8.elf -O binary kernel8.img

run: kernel8.img
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -display none -serial null -serial stdio

debug: kernel8.elf
	qemu-system-aarch64 -M raspi3b -kernel kernel8.elf -display none -S -s -serial null -serial stdio