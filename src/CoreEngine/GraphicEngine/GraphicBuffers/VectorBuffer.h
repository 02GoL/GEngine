#pragma once
#include"../../Util.h"

class VectorBuffer{
    private:
        vector<Vec3D> vectors;
    public:
        VectorBuffer(){};
        ~VectorBuffer(){};
        void load(vector<Vec3D> vectors);
        void clear();
        vector<Vec3D>& getVectors();
};