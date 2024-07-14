#include"Camera.h"

Camera::Camera(){

}
void Camera::update(){
    this->cXRot = 0;
    this->cYRot = 0;
}
Vec3D Camera::getCamVel(){
    return cVel;
}