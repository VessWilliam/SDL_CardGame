all:
	g++ -I include -I include/SDL2 -I include/Headers  -L lib -o main src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer