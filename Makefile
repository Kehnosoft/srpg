CC = g++
BUILD = bin/srpg.exe
CFLAGS = -c -g 
IDIR = src 
LIBS = -lmingw32 -lSDLmain -lSDL -lSDL_image -mwindows -static-libgcc -static-libstdc++ 

all: Fps.o Surface.o Entity.o Character.o Event.o Game.o main.o
	$(CC) main.o Game.o Event.o Entity.o Character.o Surface.o Fps.o -o $(BUILD) $(LIBS)

Game.o: src/engine/Game.cpp src/engine/Game.h
	$(CC) $(CFLAGS) src/engine/Game.cpp

Event.o: src/engine/Event.cpp src/engine/Event.h
	$(CC) $(CFLAGS) src/engine/Event.cpp

Entity.o: src/engine/Entity.cpp src/engine/Entity.h
	$(CC) $(CFLAGS) src/engine/Entity.cpp

Character.o: src/engine/Character.cpp src/engine/Character.h
	$(CC) $(CFLAGS) src/engine/Character.cpp

Surface.o: src/engine/renderer/Surface.cpp src/engine/renderer/Surface.h
	$(CC) $(CFLAGS) src/engine/renderer/Surface.cpp

Fps.o: src/engine/renderer/Fps.cpp src/engine/renderer/Fps.h
	$(CC) $(CFLAGS) src/engine/renderer/Fps.cpp

main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp

clean:
	del *.o
