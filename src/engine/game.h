#ifndef GAME_H
    #define GAME_H

#include "Entity.h"
#include "Event.h"

class Game : public Event {

    public:
        Game();
        int run();
        bool init();
        void onEvent(SDL_Event* event);
        void draw();
        void loop();
        void shutdown();

        void OnKeyDown(SDLKey key, SDLMod mod, Uint16 unicode);
        void OnKeyUp(SDLKey key, SDLMod mod, Uint16 unicode);
        void OnExit();

    private:
        bool running;
        SDL_Surface* display;
        Entity player1;

        int windowWidth;
        int windowHeight;
        int currentPlayer;

};

#endif
