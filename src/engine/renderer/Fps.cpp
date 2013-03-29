#include <SDL/SDL.h>
#include "Fps.h"

Fps Fps::fpsControl;

Fps::Fps() {
    oldTime = 0;
    lastTime = 0;
    speedFactor = 0;
    frames = 0;
    numFrames = 0;
}

void Fps::loop() {
    if(oldTime + 1000 < SDL_GetTicks()) {
        oldTime = SDL_GetTicks();
        numFrames = frames;
        frames = 0;
    }

    speedFactor = ((SDL_GetTicks() - lastTime) / 1000.0f) * 32.0f;
    lastTime = SDL_GetTicks();
    frames++;
}

int Fps::getFps() {
    return numFrames;
}

float Fps::getSpeedFactor() {
    return speedFactor;
}

