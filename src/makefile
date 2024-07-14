CC = g++
CFLAGS = -Wall


run: main
	./run

main: compile
	$(CC) *.o -lmingw32 -lSDL2main -lSDL2 -o run 

compile: *.cpp
	$(CC) -c main.cpp \
			AppWindow/*.cpp CoreEngine/*.cpp \
			InputHandler/*.cpp CoreEngine/GraphicEngine/*.cpp \
			CoreEngine/GraphicEngine/GraphicBuffers/*.cpp \
			CoreEngine/GraphicEngine/GraphicShaders/*.cpp \
			CoreEngine/Camera/*.cpp \
			FileHandler/*.cpp Window/*.cpp 

cl:
	rm *.o run