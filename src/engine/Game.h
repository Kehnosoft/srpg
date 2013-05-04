#ifndef GAME_H
    #define GAME_H

#include "Character.h"
#include "Entity.h"
#include "Event.h"

class Game : public Event {

    public:
        Game();
        int run();
        bool init();
        void endTurn();
        void onEvent(SDL_Event* event);
        void draw();
        void loop();
        void shutdown();

        void OnKeyDown(SDLKey key, SDLMod mod, Uint16 unicode);
        void OnKeyUp(SDLKey key, SDLMod mod, Uint16 unicode);
        void OnExit();

    private:
        bool running;
        std::vector<Entity*>::iterator currentPlayer;
        SDL_Surface* display;
        Character player1;
        Character player2;

        int windowWidth;
        int windowHeight;

};

#endif
