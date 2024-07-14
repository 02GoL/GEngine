#pragma once
#include"../../Util.h"

class IndexBuffer{
    private:
        vector<TriMesh> triMesh;
    public:
        IndexBuffer(){};
        ~IndexBuffer(){};
        void load(vector<TriMesh> triMesh);
        void clear();
        vector<TriMesh> getTriMesh();
};