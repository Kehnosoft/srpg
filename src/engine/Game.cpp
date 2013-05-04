#include <SDL/SDL.h>

#include "Game.h"
#include "Event.h"
#include "Character.h"
#include "Entity.h"
#include "renderer/Fps.h"

Game::Game(){
    display = NULL;
    running = true;
    windowWidth = 1440;
    windowHeight = 900;
}

int Game::run(){
    if(init() == false){
        return -1;
    }

    SDL_Event event;

    //the main loop: poll events, calculate stuff and draw shit
    while(running){
        while(SDL_PollEvent(&event)){
            onEvent(&event);
        }

        loop();
        draw();
    }

    //clean our leftovers before we leave the game
    shutdown();
    return 0;
}

bool Game::init(){

    //Init sdl stuff & setup the display surface
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

    if((display = SDL_SetVideoMode(windowWidth, windowHeight, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    //end of init sdl stuff. Now init rest of the stuff like players
    if(player1.load("resources/1.bmp", 200, 200) == false) {
        return false;
    }

    if(player2.load("resources/2.bmp", 200, 200) == false) {
        return false;
    }

    player1.x = 200;
    player1.y = 300;

    player2.x = 1040;
    player2.y = 300;

    Entity::entityList.push_back(&player1);
    Entity::entityList.push_back(&player2);

    currentPlayer = Entity::entityList.begin();

    return true;
}

void Game::endTurn(){
    if(currentPlayer != Entity::entityList.end()-1){
        ++currentPlayer;
    }
    else{
        currentPlayer = Entity::entityList.begin();
    }
}

void Game::onEvent(SDL_Event* event){
    Event::OnEvent(event);
}

void Game::OnExit(){
    running = false;
}

void Game::draw(){

    //define a fill rectangle
    SDL_Rect screen;
    screen.x = 0;
    screen.y = 0;
    screen.w = windowWidth;
    screen.h = windowHeight;

    //draw that to clear the screen every loop
    SDL_FillRect(display, &screen, 0);

    //draw entities & flip the buffer
    for(int i = 0; i < Entity::entityList.size(); i++) {
        Entity::entityList[i]->draw(display);
    }

    SDL_Flip(display);
}

void Game::loop(){
    //do the ticky things
    Fps::fpsControl.loop();
}

void Game::shutdown(){
    SDL_FreeSurface(display);
    SDL_Quit();
}

void Game::OnKeyDown(SDLKey key, SDLMod mod, Uint16 unicode){
    switch(key) {
        case SDLK_LEFT: {
            (*currentPlayer)->move(MOVE_LEFT);
            break;
        }
        case SDLK_RIGHT: {
             (*currentPlayer)->move(MOVE_RIGHT);
            break;
         }
        
        case SDLK_UP: {
            (*currentPlayer)->move(MOVE_UP);
            break;
        }

        case SDLK_DOWN: {
            (*currentPlayer)->move(MOVE_DOWN);
            break;
        }

        default: {
        }
    }
}

void Game::OnKeyUp(SDLKey key, SDLMod mod, Uint16 unicode){
    switch(key) {

        case SDLK_LEFT: {
            //let the player move again
            (*currentPlayer)->canMove = true;
            endTurn();
            break;
        }

        case SDLK_RIGHT: {
            //..again..
            (*currentPlayer)->canMove = true;
            endTurn();
            break;
         }
        
        case SDLK_UP: {
            //..and again..
            (*currentPlayer)->canMove = true;
            endTurn();
            break;
        }

        case SDLK_DOWN: {
            //until the end of the directions
            (*currentPlayer)->canMove = true;
            endTurn();
            break;
        }
        default: {
        }
    }
}


