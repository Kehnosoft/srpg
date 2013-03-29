#ifndef SURFACE_H
    #define SURFACE_H

class Surface {
    public:
        Surface();
        static SDL_Surface* load(char* file);
        static bool draw(SDL_Surface* destination, SDL_Surface* source, int x, int y);
        static bool setTransparency(SDL_Surface* destination, int red, int green, int blue);
};

#endif

