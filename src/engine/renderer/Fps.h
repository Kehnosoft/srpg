#ifndef FPS_H
    #define FPS_H

class Fps {
    public:
        Fps();
        static Fps fpsControl;
        
        int getFps();
        float getSpeedFactor();

        void loop();

    private:
        int oldTime;
        int lastTime;
        int numFrames;
        int frames;

        float speedFactor;
};

#endif

