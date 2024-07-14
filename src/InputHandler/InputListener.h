#pragma once
#include<SDL2/SDL.h>
#include<set>

using namespace std;

class InputListener{
    public:
        virtual void onKeyDown(set<SDL_Keycode> keyboardInputs, SDL_Keycode key) = 0;
        virtual void onKeyUp(set<SDL_Keycode> keyboardInputst, SDL_Keycode key) = 0;
        virtual void onMouseInput(int mouseInput) = 0;
        virtual void onMouseMotion(int mouseX, int mouseY) = 0;
};