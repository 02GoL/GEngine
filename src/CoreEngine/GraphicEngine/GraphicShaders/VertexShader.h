#pragma once
#include"../../Util.h"

class VertexShader{
    private:
    public:
        VertexShader(){};
        ~VertexShader(){};
        vector<Vec3D> setPosition(vector<Vec3D> vectors, Vec3D position);
        vector<Vec3D> rotateVectors(vector<Vec3D> vectors, Vec3D rotationAxis, float angle);
        vector<Vec3D> transformVectors(vector<Vec3D> vectors, Vec3D rotationAxis, float angle, float xTransformation, float yTransformation);
        void compileVectorShader(vector<Vec3D>* vectors, Vec3D worldCamPos, int rotAngleX, int rotAngleY){
            for(auto it = vectors->begin(); it != vectors->end(); it++){
                setRotation(*it,rotAngleX,rotAngleY);
                setTransformation(*it,worldCamPos);
            }
        }
        void setWorldSpace(Vec3D& vector){

        }
        void setTransformation(Vec3D& vector, Vec3D worldCamPos){
            vector -= worldCamPos;
        }
        void setRotation(Vec3D& vector, float rotAngleX, float rotAngleY){
            if(rotAngleX != 0){
                vector.rotate(Vec3D(1,0,0),rotAngleX*0.01);
            }
            if(rotAngleY != 0){
                vector.rotate(Vec3D(0,1,0),rotAngleY*0.01);
            }
        }
        void setViewSpace(Vec3D& vector){

        }
        void setClipSpace(Vec3D& vector){

        }
};