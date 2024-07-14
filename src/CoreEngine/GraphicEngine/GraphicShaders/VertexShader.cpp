#include"VertexShader.h"

vector<Vec3D> VertexShader::setPosition(vector<Vec3D> vectors, Vec3D position){
    vector<Vec3D> transformedVector;
    for(Vec3D vector:vectors){
        vector += position;
        transformedVector.push_back(vector);
    }           
    return transformedVector;
}
vector<Vec3D> VertexShader::rotateVectors(vector<Vec3D> vectors, Vec3D rotationAxis, float angle){
    vector<Vec3D> transformedVector;
    for(Vec3D vector:vectors){
        vector.rotate(rotationAxis,angle);
        transformedVector.push_back(vector);
    }
    return transformedVector;
}
vector<Vec3D> VertexShader::transformVectors(vector<Vec3D> vectors, Vec3D rotationAxis, float angle, float xTransformation, float yTransformation){
    vector<Vec3D> transformedVector;
    for(Vec3D vector:vectors){
        vector.x += xTransformation;
        vector.y += yTransformation;
        transformedVector.push_back(vector);
    }
    return transformedVector;
}