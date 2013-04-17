#ifndef CHARACTER_H
    #define CHARACTER_H
#include <SDL/SDL.h>
#include "Entity.h"

class Character : public Entity {

    public:

        Character();
        bool load(char* file, int width, int height);
        void loop();
        void draw(SDL_Surface* display);
        void cleanup();
        bool collide(Entity* entity);
};
#endif
