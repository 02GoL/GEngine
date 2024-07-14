#include"window.h"

void Window::setResolution(int xResolution, int yResolution){
    this->xResolution = xResolution;
    this->yResolution = yResolution;
}

bool Window::init(){
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        cout << "Initializing...\n";
        window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,xResolution,yResolution,SDL_WINDOW_SHOWN);
        if(window){
            cout << "Window Created...\n";
        }
        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer){
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer,0,0,0,255);
            cout << "Render Created...\n";
        }
        SDL_WarpMouseInWindow(window,xResolution/2,yResolution/2);
        SDL_SetRelativeMouseMode(SDL_TRUE);
        running = true;
    }else{
        running = false;
    }
    return running;
}

void Window::windowsEventHandler(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            running = false;
        }
        SDL_PushEvent(&event);
    }
}

bool Window::isRunning(){
    return running;
}

SDL_Renderer* Window::getRenderWindow(){
    return renderer;
};
