#include"../Util.h"

class Camera{
    private:
        Vec3D cVel;
        int cXRot;
        int cYRot;
    public:
        Camera();
        void setX(int x){
            this->cVel.x = x;
        }
        void setY(int y){
            this->cVel.y = y;
        }
        void setZ(int z){
            this->cVel.z = z;
        }
        int getCamRotX(){
            return cXRot;
        }
        int getCamRotY(){
            return cYRot;
        }

        void setXRot(int cXRot){
            this->cXRot = cXRot;
        }
        void setYRot(int cYRot){
            this->cYRot = cYRot;
        }
        void update();
        Vec3D getCamVel();
};