#include"IndexBuffer.h"

void IndexBuffer::load(vector<TriMesh> triMesh){
    this->triMesh = triMesh;
}
void IndexBuffer::clear(){
    triMesh.clear();
}
vector<TriMesh> IndexBuffer::getTriMesh(){
    return triMesh;
}