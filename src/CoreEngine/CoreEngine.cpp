#include"CoreEngine.h"

CoreEngine* CoreEngine::getCoreEngine(){
    static CoreEngine coreEngine;
    return &coreEngine;
}
        
void CoreEngine::init(SDL_Renderer* renderWindow){
    this->renderWindow = renderWindow;
    graphicEngine.init();
}

bool CoreEngine::load(string dataPath){
    FileParser* fileParser = new FileParser();
    if(fileParser->loadData(dataPath)){
        graphicEngine.getVectorBuffer()->load(fileParser->getVectorData());
        graphicEngine.getIndexBuffer()->load(fileParser->getTriMesh());
        //graphicEngine.setWorldSpace(Vec3D(0,0,-2));
        delete fileParser;
        return true;
    }else{
        delete fileParser;
        return false;
    }
}

void CoreEngine::update(){
    graphicEngine.compileShaders(camera.getCamVel(),camera.getCamRotX(),camera.getCamRotY());
    graphicEngine.render(renderWindow);
    //camera.update();
}

void CoreEngine::onKeyDown(set<SDL_Keycode> keyboardInputs, SDL_Keycode key){
    if(key == SDLK_a || key == SDLK_d){
        if(keyboardInputs.count(SDLK_d) && keyboardInputs.count(SDLK_a)){
            camera.setX(0);
        }else{
            if(keyboardInputs.count(SDLK_d)){
                camera.setX(1);
            }
            if(keyboardInputs.count(SDLK_a)){
                camera.setX(-1);
            }
        }
    }
    if(key == SDLK_w || key == SDLK_s){
        if(keyboardInputs.count(SDLK_w) && keyboardInputs.count(SDLK_s)){
            camera.setZ(0);
        }else{
            if(keyboardInputs.count(SDLK_w)){
                camera.setZ(-1);
            }
            if(keyboardInputs.count(SDLK_s)){
                camera.setZ(1);
            }
        }
    }
    if(key == SDLK_UP){
        camera.setXRot(-1);
    }
    if(key == SDLK_DOWN){
        camera.setXRot(1);
    }
    if(key == SDLK_RIGHT){
        camera.setYRot(-1);
    }
    if(key == SDLK_LEFT){
        camera.setYRot(1);
    }
}

void CoreEngine::onKeyUp(set<SDL_Keycode> keyboardInputs, SDL_Keycode key){
    if(key == SDLK_UP){
        camera.setXRot(0);
    }
    if(key == SDLK_DOWN){
        camera.setXRot(0);
    }
    if(key == SDLK_RIGHT){
        camera.setYRot(0);
    }
    if(key == SDLK_LEFT){
        camera.setYRot(0);
    }
    if(key == SDLK_a || key == SDLK_d){
        if(!keyboardInputs.count(SDLK_a) && keyboardInputs.count(SDLK_d)){
            camera.setX(1);
        }else if(keyboardInputs.count(SDLK_a) && !keyboardInputs.count(SDLK_d)){
            camera.setX(-1);
        }else if(!keyboardInputs.count(SDLK_a) && !keyboardInputs.count(SDLK_d)){
            camera.setX(0);
        }
    }
    if(key == SDLK_w || key == SDLK_s){
       if(!keyboardInputs.count(SDLK_w) && keyboardInputs.count(SDLK_s)){
            camera.setZ(1);
        }else if(keyboardInputs.count(SDLK_w) && !keyboardInputs.count(SDLK_s)){
            camera.setZ(-1);
        }else if(!keyboardInputs.count(SDLK_w) && !keyboardInputs.count(SDLK_s)){
            camera.setZ(0);
        } 
    }
}

void CoreEngine::onMouseInput(int mouseInput){
    //graphicEngine->setScale(mouseInput);
}

void CoreEngine::onMouseMotion(int mouseX, int mouseY){
    //camera.setXRot(-mouseY);
    //camera.setYRot(-mouseX);
    /*
    graphicEngine.getVertexShader().compileVectorShader
        (&graphicEngine.getVectorBuffer().getVectors(),Vec3D(1,0,0),-mouseY*0.01);
    graphicEngine.getVertexShader()->compileVectorShader
        (&graphicEngine->getVectorBuffer()->getVectors(),Vec3D(0,1,0),-mouseX*0.01);
    */
}