#include"../CoreEngine/Util.h"

class FileParser{
    private:
        vector<Vec3D> vectors;
        vector<TriMesh> vectorMesh;
    public:
        bool loadData(string dataPath);
        vector<Vec3D> getVectorData(){return vectors;}
        vector<TriMesh> getTriMesh(){return vectorMesh;}
};
