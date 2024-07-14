#include"VectorBuffer.h"

void VectorBuffer::load(vector<Vec3D> vectors){
    this->vectors = vectors;
}
void VectorBuffer::clear(){
    vectors.clear();
}
vector<Vec3D>& VectorBuffer::getVectors(){
    return vectors;
}