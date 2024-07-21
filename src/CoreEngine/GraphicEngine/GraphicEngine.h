#include"../Util.h"
#include"GraphicBuffers/VectorBuffer.h"
#include"GraphicBuffers/IndexBuffer.h"
#include"GraphicShaders/VertexShader.h"

class GraphicEngine{
    private:
        int xResolution;
        int yResolution;
        int scale;

        VectorBuffer* vectorBuffer;
        IndexBuffer* indexBuffer;

        VertexShader* vertexShader;
    public:
        GraphicEngine(){};
        ~GraphicEngine(){};
        void init(); 
        void render(SDL_Renderer* renderWindow);
        void compileShaders(Vec3D worldCamPos, int rotAngleX, int rotAngleY);
        void setWorldSpace(Vec3D worldSpace);
        VectorBuffer* getVectorBuffer(){
            return vectorBuffer;
        }
        IndexBuffer* getIndexBuffer(){
            return indexBuffer;
        }

};