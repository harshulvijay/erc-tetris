game:
	mkdir -p ./build
	gcc -O3 `pkg-config --cflags gtk4` -o ./build/game ./src/*.c `pkg-config --libs gtk4`

