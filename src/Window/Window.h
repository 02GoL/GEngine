#include<iostream>
#include<SDL2/SDL.h>

using namespace std;

class Window{
    protected:
        SDL_Window* window;
        SDL_Renderer* renderer;
        int xResolution;
        int yResolution;
        bool running;
        const char* title = "Engine Window";
    public: 
        Window(){};
        ~Window(){};
        void setResolution(int xResolution, int yResolution);
        bool init();

        void windowsEventHandler();
        bool isRunning();
        SDL_Renderer* getRenderWindow();

        virtual void onCreate() = 0;
        virtual void onDestroy() = 0;
};