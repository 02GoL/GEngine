#include"FileParser.h"

bool FileParser::loadData(string dataPath){
    ifstream myFile(dataPath);
    if(myFile.is_open()){
        string str;
        int index = 0;
        while(getline(myFile,str)){
            if(str != ""){
                stringstream ss(str);
                string header;
                ss >> header;
                if(header == "v"){
                    string metaData[3];
                    ss >> metaData[0] >> metaData[1] >> metaData[2];
                    vectors.push_back(Vec3D(stof(metaData[0]),
                                        stof(metaData[1]),stof(metaData[2]),index));
                    index++;
                }else if(header == "f"){
                    string metaData[3];
                    ss >> metaData[0] >> metaData[1] >> metaData[2];
                    vectorMesh.push_back(TriMesh(stof(metaData[0])-1,
                                            stof(metaData[1])-1,stof(metaData[2])-1));
                }
            }
        }
        cout << "Loaded map data...\n";
        myFile.close();
        return true;
    }else{
        cout << "Unable to open file...\n";
        myFile.close();
        return false;
    }
}