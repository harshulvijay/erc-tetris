game:
	mkdir -p ./build
# python scripts/img2matrix.py res/tetrominoes src/app/gen/tetrominoes.h src/color.h
#	python scripts/img2matrix.py res/text src/app/gen/text.h src/color.h
#	python scripts/img2matrix.py res/screens src/app/gen/screens.h src/color.h
# python scripts/img2pymatrix.py res/text src/app/gen/text.py
	gcc -O3 `pkg-config --cflags gtk4` -g -o ./build/game ./src/*.c ./src/app/*.c ./src/app/gen/*.c `pkg-config --libs gtk4`
