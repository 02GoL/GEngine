#include"AppWindow.h"

AppWindow::AppWindow(int xResolution, int yResolution){
    this->xResolution = xResolution;
    this->yResolution = yResolution;
    this->displayFPS = false;
}

void AppWindow::eventHandler(){
    Window::windowsEventHandler();
    inputHandler.update();
    CoreEngine::getCoreEngine()->update();
}

void AppWindow::onCreate(){
    Window::setResolution(xResolution,yResolution);
    
    if(Window::init()){
        CoreEngine::getCoreEngine()->init(renderer);
        CoreEngine::getCoreEngine()->load("../ObjFiles/teapot.txt");

        inputHandler.addInputListener(CoreEngine::getCoreEngine());

        Uint32 frameStart;
        Uint32 frameEnd;
        int frameTime;

        const int FPS = 60;
        const int frameDelay = 1000/FPS;

        Uint32 countedFrames = 0;
        Uint32 totalFrames = 0;
        float currentFPS = 0;

        while(isRunning()){
            frameStart = SDL_GetTicks();
            totalFrames++;

            eventHandler();
            
            frameTime = SDL_GetTicks()-frameStart;
            if(frameDelay > frameTime){
                SDL_Delay(frameDelay-frameTime);    
            }
            
            frameEnd = SDL_GetTicks();
            
            currentFPS = (frameEnd-frameStart)/1000.0f;
            countedFrames += frameEnd-frameStart;
            if(displayFPS){
                cout << "Current FPS: " << to_string(1.0f/currentFPS) << " | ";
                cout << "Average FPS: " << to_string(1000.0f/((float)countedFrames/totalFrames)) << "\n";
            }
        }
    }else{
        cout << "Something went wrong...\n";
    }
    onDestroy();
}

void AppWindow::onDestroy(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "System Quit...\n";
}