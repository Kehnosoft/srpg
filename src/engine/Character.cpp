#include <SDL/SDL.h>
#include <vector>
#include "Character.h"

Character::Character() {
}

bool Character::load(char* file, int width, int height) {
    if(Entity::load(file, width, height) ==  false) {
        return false;
    }
    return true;
}

void Character::loop() {
    Entity::loop();
}

void Character::draw(SDL_Surface* display) {
    Entity::draw(display);
}

void Character::cleanup() {
    Entity::cleanup();
}

bool Character::collide(Entity* entity) {
    return true;
}
