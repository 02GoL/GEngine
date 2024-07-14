#include<iostream>
#include<SDL2/SDL.h>
#include<set>
#include"../CoreEngine/Util.h"
#include"InputListener.h"

using namespace std;

class InputHandler{
    private:
        vector<InputListener*> inputListeners;
        set<SDL_Keycode> keyboardInputs;
    public:  
        void update();
        void setKeyDown(SDL_Keycode key);
        void setKeyUp(SDL_Keycode key);
        void addInputListener(InputListener* inputListener);
        bool isPressed(SDL_Keycode input);
        bool hasKeyEvent();
};