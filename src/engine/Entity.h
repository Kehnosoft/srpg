#ifndef ENTITY_H
    #define ENTITY_H
#include <SDL/SDL.h>
#include <vector>

typedef enum {
    MOVE_LEFT,
    MOVE_RIGHT,
    MOVE_UP,
    MOVE_DOWN
} direction_t;

class Entity {

    public:
        Entity();
        virtual ~Entity();

        static std::vector<Entity*> entityList;

        bool canMove;
        bool moveLeft;
        bool moveRight;
        bool moveUp;
        bool moveDown;

        float x;
        float y;

        int gridPos;
        int width;
        int height;

        virtual bool load(char* file, int width, int height);
        virtual void loop();
        virtual void draw(SDL_Surface* display);
        virtual void cleanup();

        virtual void move(direction_t direction);

    private:

    protected:
        SDL_Surface* entitySurface;
        
        int colX;
        int colY;
        int colWidth;
        int colHeight;
};

#endif
