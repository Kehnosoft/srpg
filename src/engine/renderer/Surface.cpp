#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Surface.h"

Surface::Surface(){
}

SDL_Surface* Surface::load(char* file){
    SDL_Surface* tempSurface = NULL;
    SDL_Surface* surface = NULL;

    if((tempSurface = IMG_Load(file)) == NULL) {
        return NULL;
    }

    //set transparencies, make the proper surface from temp, and then we returns it
    setTransparency(tempSurface, 255, 0, 255);
    surface = SDL_DisplayFormatAlpha(tempSurface);
    SDL_FreeSurface(tempSurface);

    return surface;
}

bool Surface::draw(SDL_Surface* destination, SDL_Surface* source, int x, int y) {
    if(destination == NULL || source == NULL) {
        return false;
    }

    //make a rectangle, blit our surface to that, and draw it to the screen
    SDL_Rect destinationRect;
    destinationRect.x = x;
    destinationRect.y = y;

    SDL_BlitSurface(source, NULL, destination, &destinationRect);

    return true;
}

bool Surface::setTransparency(SDL_Surface* destination, int red, int green, int blue) {
    if(destination == NULL) {
        return false;
    }

    SDL_SetColorKey(destination, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(destination->format, red, green, blue));

    return true;
}
