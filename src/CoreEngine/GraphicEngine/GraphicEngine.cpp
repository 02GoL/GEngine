#include"GraphicEngine.h"

void GraphicEngine::init(){
    xResolution = 800;
    yResolution = 600;
    scale = 100;
    vectorBuffer = new VectorBuffer();
    indexBuffer = new IndexBuffer();
    vertexShader = new VertexShader();
}

bool GraphicEngine::load(string dataPath){
    FileParser* fileParser = new FileParser();
    if(fileParser->loadData(dataPath)){
        vectorBuffer->load(fileParser->getVectorData());
        indexBuffer->load(fileParser->getTriMesh());
        delete fileParser;
        return true;
    }else{
        delete fileParser;
        return false;
    }
}

void GraphicEngine::compileShaders(Vec3D worldCamPos, int rotAngleX, int rotAngleY){
    vertexShader->compileVectorShader(&vectorBuffer->getVectors(),worldCamPos,rotAngleX,rotAngleY);
    //pixel shader
}

void GraphicEngine::render(SDL_Renderer* renderWindow){
    SDL_RenderClear(renderWindow);
    SDL_SetRenderDrawColor(renderWindow,255,255,255,255);

    vector<Vec3D> points = vectorBuffer->getVectors();
    //vertexBuffer.load(VectorShader.transformVectors(vertexBuffer.getVectors(),rotationAxis,angle,xOffset,yOffset));

    for(TriMesh mesh:indexBuffer->getTriMesh()){
        Vec3D v2(points.at(mesh.vectors[1]).x-points.at(mesh.vectors[0]).x,
                    points.at(mesh.vectors[1]).y-points.at(mesh.vectors[0]).y,
                    points.at(mesh.vectors[1]).z-points.at(mesh.vectors[0]).z);

        Vec3D v3(points.at(mesh.vectors[2]).x-points.at(mesh.vectors[0]).x,
                    points.at(mesh.vectors[2]).y-points.at(mesh.vectors[0]).y,
                    points.at(mesh.vectors[2]).z-points.at(mesh.vectors[0]).z);
        Vec3D crossProduct = getCross(v2,v3);

        if(crossProduct.z > 0){
            SDL_Vertex v[3];
            for(int i = 0; i < 3; i++){
                v[i].position.x = (xResolution/2)+points.at(mesh.vectors[i]).x*scale;
                v[i].position.y = (yResolution/2)+points.at(mesh.vectors[i]).y*scale;
                v[i].color.r = 255;
                v[i].color.g = 0;
                v[i].color.b = 0;
                v[i].color.a = 1;
            }
            SDL_RenderGeometry(renderWindow, NULL, v, 3, NULL, 0);
            if(1){
                SDL_SetRenderDrawColor(renderWindow,255,255,255,255);
                SDL_RenderDrawLineF(renderWindow,(xResolution/2)+points.at(mesh.vectors[0]).x*scale,(yResolution/2)+points.at(mesh.vectors[0]).y*scale,
                                (xResolution/2)+points.at(mesh.vectors[1]).x*scale,(yResolution/2)+points.at(mesh.vectors[1]).y*scale);
                SDL_RenderDrawLineF(renderWindow,(xResolution/2)+points.at(mesh.vectors[1]).x*scale,(yResolution/2)+points.at(mesh.vectors[1]).y*scale,
                                (xResolution/2)+points.at(mesh.vectors[2]).x*scale,(yResolution/2)+points.at(mesh.vectors[2]).y*scale);
                SDL_RenderDrawLineF(renderWindow,(xResolution/2)+points.at(mesh.vectors[2]).x*scale,(yResolution/2)+points.at(mesh.vectors[2]).y*scale,
                                (xResolution/2)+points.at(mesh.vectors[0]).x*scale,(yResolution/2)+points.at(mesh.vectors[0]).y*scale);
            }
        }
        
    }
    SDL_SetRenderDrawColor(renderWindow,0,0,0,255);
    SDL_RenderPresent(renderWindow);
}

/*
void GraphicEngine::onInput(set<SDL_Keycode> keyboardInputs){
    if(!keyboardInputs.count(SDLK_e) && !keyboardInputs.count(SDLK_q) ||
        (keyboardInputs.count(SDLK_e) && keyboardInputs.count(SDLK_q))){
        setRotation(0);
    }else{
        if(keyboardInputs.count(SDLK_e)){
            setRotation(1);
        }
        if(keyboardInputs.count(SDLK_q)){
            setRotation(-1);
        }
    }
    if(!keyboardInputs.count(SDLK_w) && !keyboardInputs.count(SDLK_s) ||
        (keyboardInputs.count(SDLK_w) && keyboardInputs.count(SDLK_s))){
        setTranslationY(0);
    }else{
        if(keyboardInputs.count(SDLK_w)){
            setTranslationY(-1);
        }
        if(keyboardInputs.count(SDLK_s)){
            setTranslationY(1);
        }
    }
    if(!keyboardInputs.count(SDLK_d) && !keyboardInputs.count(SDLK_a) ||
        (keyboardInputs.count(SDLK_d) && keyboardInputs.count(SDLK_a))){
        setTranslationX(0);
    }else{
        if(keyboardInputs.count(SDLK_d)){
            setTranslationX(1);
        }
        if(keyboardInputs.count(SDLK_a)){
            setTranslationX(-1);
        }
    }
    if(keyboardInputs.count(SDLK_r)){
        setRotationAxisX(1);
    }
    if(keyboardInputs.count(SDLK_t)){
        setRotationAxisY(1);
    }
    if(keyboardInputs.count(SDLK_y)){
        setRotationAxisZ(1);
    }
    if(keyboardInputs.count(SDLK_f)){
        setRotationAxisX(0);
    }
    if(keyboardInputs.count(SDLK_g)){
        setRotationAxisY(0);
    }
    if(keyboardInputs.count(SDLK_h)){
        setRotationAxisZ(0);
    }
}

void GraphicEngine::onInputRelease(set<SDL_Keycode> keyboardInputs){
    if(!keyboardInputs.count(SDLK_q) && keyboardInputs.count(SDLK_e)){
        setRotation(1);
    }else if(keyboardInputs.count(SDLK_q) && !keyboardInputs.count(SDLK_e)){
        setRotation(-1);
    }else if(!keyboardInputs.count(SDLK_q) && !keyboardInputs.count(SDLK_e)){
        setRotation(0);
    }
    if(!keyboardInputs.count(SDLK_w) && keyboardInputs.count(SDLK_s)){
        setTranslationY(1);
    }else if(keyboardInputs.count(SDLK_w) && !keyboardInputs.count(SDLK_s)){
        setTranslationY(-1);
    }else if(!keyboardInputs.count(SDLK_w) && !keyboardInputs.count(SDLK_s)){
        setTranslationY(0);
    }
    if(!keyboardInputs.count(SDLK_a) && keyboardInputs.count(SDLK_d)){
        setTranslationX(1);
    }else if(keyboardInputs.count(SDLK_a) && !keyboardInputs.count(SDLK_d)){
        setTranslationX(-1);
    }else if(!keyboardInputs.count(SDLK_a) && !keyboardInputs.count(SDLK_d)){
        setTranslationX(0);
    }
}

void GraphicEngine::onMouseInput(int mouseInput){
    setScale(mouseInput);
}
*/