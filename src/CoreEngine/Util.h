#pragma once
#include<iostream>
#include<vector>
#include<SDL2/SDL.h>
#include<sstream>
#include<fstream>
#include<math.h>
#include<queue>
#define eps 0.00005
#define PI 3.14159

using namespace std;

struct Vec3D{
    float x;
    float y;
    float z;
    int index;

    Vec3D(float x, float y, float z);
    Vec3D(float x, float y, float z, int index);
    Vec3D();
    void normalize();
    void rotate(Vec3D rotationAxis, float angle);
    Vec3D operator+(const Vec3D& rhs);
    Vec3D operator-(const Vec3D& rhs);
    Vec3D operator*(const float& rhs);
    Vec3D& operator+=(const Vec3D& rhs);
    Vec3D& operator-=(const Vec3D& rhs);
    Vec3D& operator*=(const float& rhs);
};

struct TriMesh{
    int vectors[3];
        
    TriMesh(int v1, int v2, int v3){
        this->vectors[0] = v1;
        this->vectors[1] = v2;
        this->vectors[2] = v3;
    }
};

struct Vec2D{
    float x;
    float y;
    
    Vec2D(float x, float y):x(x), y(y){}
    Vec2D(){};
};

struct Segment{
    Vec2D v1;
    Vec2D v2;
    Vec2D midPoint;
    Vec2D normal;
    int facingDir;
    int sectorIndex;
    int vectorIndex;
    int portalingSector;

    Segment(Vec2D v1, Vec2D v2):v1(v1), v2(v2){}
    Segment(){}
    void setMidPoint();
    void setNormal();
};

struct Sector{
    int sectorIndex;
    float floorHeight;
    float ceilHeight;
};

struct RenderedSection{
    float t0;
    float t1;
    float x0;
    float y0;
    float slope;
    float floor;
    float ceiling;
    bool isPortal;
    
    RenderedSection(float t0, float t1, float x0, float y0, float slope, float floor, float ceiling, bool isPortal){
        this->t0 = t0;
        this->t1 = t1;
        this->x0 = x0;
        this->y0 = y0;
        this->slope = slope;
        this->floor = floor;
        this->ceiling = ceiling;
        this->isPortal = isPortal;
    }
    RenderedSection(){}
};

int getMax(int a, int b);
int getMin(int a, int b);
float toRad(float angle);
float toDeg(float radian);
float pytha(float a, float b);
float getDot(Vec3D v1, Vec3D v2);
Vec3D getCross(Vec3D v1, Vec3D v2);
float getMaxF(float a, float b);
float getMinF(float a, float b);
float getMaxElementF(float a, float b, float c);
float getMinElementF(float a, float b, float c);
float getDet(Vec2D v1, Vec2D v2, Vec2D v3);
float getAngleDiff(float angle, float relativeAngle);
float getAbsAngleDiff(float angle, float relativeAngle);
float normalizeAngle(float angle);
bool inAngleRange(float angle, float lowerAngleBound, float upperAnglerBound);
bool inRange(float x, float boundA, float boundB);
bool isIntersectingSeg(Segment* segment, Vec2D v1, float angle);
bool isIntersectingSeg(Segment* segment, Vec2D v1, Vec2D v2);
Vec2D intersectingPoint(Segment* segment1, Segment* segment2);
Vec2D intersectingPoint(Segment* segment, Vec2D v1, Vec2D v2);
Vec2D intersectingPoint(Segment* segment, Vec2D v1, float angle);
Vec3D rotateVector(Vec3D v1, Vec3D rotationAxis, float angle);