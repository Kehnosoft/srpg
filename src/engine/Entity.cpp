#include <SDL/SDL.h>
#include <vector>

#include "Entity.h"
#include "renderer/Surface.h"

std::vector<Entity*> Entity::entityList;

Entity::Entity(){
    entitySurface = NULL;

    canMove = true;
    moveLeft = false;
    moveRight = false;
    moveUp = false;
    moveDown = false;

    x = 0;
    y = 0;

    gridPos = 0;
    width = 0;
    height = 0;

    colX = 0;
    colY = 0;
    colWidth = 0;
    colHeight = 0;

}

Entity::~Entity(){
}

bool Entity::load(char* file, int width, int height){
    //load the surface (that's a texture) for our entity, and set the entity size
    if((entitySurface = Surface::load(file)) == NULL) {
        return false;
    }

    this->width = width;
    this->height = height;

    return true;
}

void Entity::loop() {
}

void Entity::draw(SDL_Surface* display){
    if(display == NULL || entitySurface == NULL) {
        return;
    }

    Surface::draw(display, entitySurface, x, y);

}

void Entity::cleanup(){
    if(entitySurface) {
        SDL_FreeSurface(entitySurface);
    }
    entitySurface = NULL;
}

void Entity::move(direction_t direction) {
    //move if we can and then prevent us from moving until we have released the key
    if(canMove){
        switch (direction) {
            case MOVE_LEFT: {
                this->x -= 200;
                this->canMove = false;
                break;
            }
            case MOVE_RIGHT: {
                this->x += 200;
                this->canMove = false;
                break;
            }
            case MOVE_UP: {
                this->y -= 200;
                this->canMove = false;
                break;
            }
            case MOVE_DOWN: {
                this->y += 200;
                this->canMove = false;
                break;
            }
            default: {
            }
        }                
    }
}

