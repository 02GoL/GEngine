#include"InputHandler.h"

void InputHandler::update(){
    SDL_Event input;
    while(SDL_PollEvent(&input)){
        const Uint8* currentKeyState = SDL_GetKeyboardState(NULL);
        switch(input.type){
            case SDL_KEYDOWN:
                setKeyDown(input.key.keysym.sym);
                break;
            case SDL_KEYUP:
                setKeyUp(input.key.keysym.sym);
                break;
            case SDL_MOUSEWHEEL:
                for(InputListener* inputListener:inputListeners){
                    inputListener->onMouseInput(input.wheel.y);
                }
                break;
            case SDL_MOUSEMOTION:
                for(InputListener* inputListener:inputListeners){
                    inputListener->onMouseMotion(input.motion.xrel,input.motion.yrel);
                }
                break;
        }
    }
}

void InputHandler::setKeyDown(SDL_Keycode key){
    if(!isPressed(key)){
        keyboardInputs.insert(key);
        for(InputListener* inputListener:inputListeners){
            inputListener->onKeyDown(keyboardInputs,key);
        }
    }
}

void InputHandler::setKeyUp(SDL_Keycode key){
    if(isPressed(key)){
        keyboardInputs.erase(key);
        for(InputListener* inputListener:inputListeners){
            inputListener->onKeyUp(keyboardInputs,key);
        }
    }
}

void InputHandler::addInputListener(InputListener* inputListener){
    inputListeners.push_back(inputListener);
}

bool InputHandler::isPressed(SDL_Keycode input){
    return keyboardInputs.count(input);
}

bool InputHandler::hasKeyEvent(){
    return keyboardInputs.empty();
} 