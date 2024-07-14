#include<iostream>
#include<SDL2/SDL.h>
#include"GraphicEngine/GraphicEngine.h"
#include"../InputHandler/InputListener.h"
#include"Camera/Camera.h"

using namespace std;

class CoreEngine: public InputListener{
    private:
        SDL_Renderer* renderWindow;
        GraphicEngine graphicEngine;
        Camera camera;
    public:
        CoreEngine(){};
        ~CoreEngine(){};
        static CoreEngine* getCoreEngine();
        void init(SDL_Renderer* renderWindow);
        bool load(string dataPath);
        void update();   
        
        void onKeyDown(set<SDL_Keycode> keyboardInputs, SDL_Keycode key) override;
        void onKeyUp(set<SDL_Keycode> keyboardInputst, SDL_Keycode key) override;
        void onMouseInput(int mouseInput) override;
        void onMouseMotion(int mouseX, int mouseY) override;
};