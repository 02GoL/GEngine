#include"Util.h"

int getMax(int a, int b){
    if(a >= b){
        return a;
    }else{
        return b;
    }
}

int getMin(int a, int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

float toRad(float angle){
    if(angle == 360){
        angle = 0;
    }
    return angle*PI/180.0f;
}

float toDeg(float radian){
    if(radian == 2*PI){
        radian = 0;
    }
    return radian*180.0f/PI;
}

float pytha(float a, float b){
    return sqrt(pow(a,2)+pow(b,2));
}

float getDot(Vec3D v1, Vec3D v2){
    return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
}

Vec3D getCross(Vec3D v1, Vec3D v2){
    return Vec3D(v1.y*v2.z-v1.z*v2.y,
                        v1.z*v2.x-v1.x*v2.z,
                        v1.x*v2.y-v1.y*v2.x);
}

float getMaxF(float a, float b){
    if(a >= b){
        return a;
    }else{
        return b;
    }
}

float getMinF(float a, float b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

float getMinElementF(float a, float b, float c){
    if(getMinF(a,b) == a){
        if(getMinF(a,c) == a){
            return a;
        }else{
            return c;
        }
    }else{
        if(getMinF(b,c) == c){
            return c;
        }else{
            return b;
        }
    }
}

float getMaxElementF(float a, float b, float c){
    if(getMaxF(a,b) == a){
        if(getMaxF(a,c) == a){
            return a;
        }else{
            return c;
        }
    }else{
        if(getMaxF(b,c) == c){
            return c;
        }else{
            return b;
        }
    }
}

float getDet(Vec2D v1, Vec2D v2, Vec2D v3){
    return (v2.x-v1.x)*(v3.y-v1.y)-(v3.x-v1.x)*(v2.y-v1.y);
}

float getAngleDiff(float angle, float relativeAngle){
    float diff = fmod(angle-relativeAngle+PI,2*PI);
    if(diff < 0){
        diff += 2*PI;
    }
    return diff-PI;
}

float getAbsAngleDiff(float angle,float relativeAngle){ //lower bound | upper bound
    return abs(getAngleDiff(angle,relativeAngle));
}

float normalizeAngle(float angle){
    angle = fmod(angle,2*PI);
    if(angle < 0){
        angle += 2*PI;
    }
    return angle;
}

bool inAngleRange(float angle, float lowerAngleBound, float upperAnglerBound){
    float range = getAbsAngleDiff(lowerAngleBound,upperAnglerBound)+eps;
    return getAbsAngleDiff(angle,lowerAngleBound) <= range && getAbsAngleDiff(angle,upperAnglerBound) <= range;
}

bool inRange(float angle, float boundA, float boundB){
    return angle >= getMinF(boundA,boundB)-eps && angle <= getMaxF(boundA,boundB)+eps;
}

// need to add more info about this function since its different
bool isIntersectingSeg(Segment* segment, Vec2D v1, float angle){
    Vec2D v2 = v1;
    v2.x += cos(angle);
    v2.y += sin(angle);
    float t = float(((segment->v1.x-v1.x)*(v1.y-v2.y)-(segment->v1.y-v1.y)*(v1.x-v2.x))/
                    ((segment->v1.x-segment->v2.x)*(v1.y-v2.y)-(segment->v1.y-segment->v2.y)*(v1.x-v2.x)));
    float x = float(segment->v1.x+t*(segment->v2.x-segment->v1.x));
    float y = float(segment->v1.y+t*(segment->v2.y-segment->v1.y));
    float theta = normalizeAngle(atan2(y-v1.y,x-v1.x));
    return inRange(t,0,1) && inAngleRange(theta,angle,angle);
}

bool isIntersectingSeg(Segment* segment, Vec2D v1, Vec2D v2){
    float t = float(((segment->v1.x-v1.x)*(v1.y-v2.y)-(segment->v1.y-v1.y)*(v1.x-v2.x))/
                    ((segment->v1.x-segment->v2.x)*(v1.y-v2.y)-(segment->v1.y-segment->v2.y)*
                    (v1.x-v2.x)));
    float u = float(-((segment->v1.x-segment->v2.x)*(segment->v1.y-v1.y)-(segment->v1.y-segment->v2.y)*
                    (segment->v1.x-v1.x))/((segment->v1.x-segment->v2.x)*(v1.y-v2.y)-
                    (segment->v1.y-segment->v2.y)*(v1.x-v2.x)));      
    return inRange(t,0,1) && inRange(u,0,1);
}

Vec2D intersectingPoint(Segment* segment1, Segment* segment2){
    float t = float((segment1->v1.x-segment2->v1.x)*(segment2->v1.y-segment2->v2.y)-
                    (segment1->v1.y-segment2->v1.y)*(segment2->v1.x-segment2->v2.x))/
                    ((segment1->v1.x-segment1->v2.x)*(segment2->v1.y-segment2->v2.y)-
                    (segment1->v1.y-segment1->v2.y)*(segment2->v1.x-segment2->v2.x));
    Vec2D newVec(float(segment1->v1.x+t*(segment1->v2.x-segment1->v1.x)),
                    float(segment1->v1.y+t*(segment1->v2.y-segment1->v1.y)));
    return newVec;
}

Vec2D intersectingPoint(Segment* segment, Vec2D v1, Vec2D v2){
    float t = float((segment->v1.x-v1.x)*(v1.y-v2.y)-(segment->v1.y-v1.y)*(v1.x-v2.x))/
                ((segment->v1.x-segment->v2.x)*(v1.y-v2.y)-(segment->v1.y-segment->v2.y)*(v1.x-v2.x));
    Vec2D newVec(float(segment->v1.x+t*(segment->v2.x-segment->v1.x)),
                    float(segment->v1.y+t*(segment->v2.y-segment->v1.y)));
    return newVec;
}

Vec2D intersectingPoint(Segment* segment, Vec2D v1, float angle){
    Vec2D v2 = v1;
    v2.x += cos(angle);
    v2.y += sin(angle);
    float t = float((segment->v1.x-v1.x)*(v1.y-v2.y)-(segment->v1.y-v1.y)*(v1.x-v2.x))/
                ((segment->v1.x-segment->v2.x)*(v1.y-v2.y)-(segment->v1.y-segment->v2.y)*(v1.x-v2.x));
    v2.x = float(segment->v1.x+t*(segment->v2.x-segment->v1.x));
    v2.y = float(segment->v1.y+t*(segment->v2.y-segment->v1.y));
    return v2;
}
/*
Vec3D rotateVector(Vec3D v1, Vec3D rotationAxis, float angle){
    float xf = v1.x*pow(cos(angle/2),2)+sin(angle)*(rotationAxis.y*v1.z-rotationAxis.z*v1.y)+
                pow(sin(angle/2),2)*(2*rotationAxis.x*(rotationAxis.z*v1.z+rotationAxis.y*v1.y)+
                v1.x*(pow(rotationAxis.x,2)-pow(rotationAxis.y,2)-pow(rotationAxis.z,2)));
    float yf = v1.y*pow(cos(angle/2),2)-sin(angle)*(rotationAxis.x*v1.z-rotationAxis.z*v1.x)+
                pow(sin(angle/2),2)*(2*rotationAxis.y*(rotationAxis.x*v1.x+rotationAxis.z*v1.z)-
                v1.y*(pow(rotationAxis.x,2)-pow(rotationAxis.y,2)+pow(rotationAxis.z,2)));
    float zf = v1.z*pow(cos(angle/2),2)+sin(angle)*(rotationAxis.x*v1.y-rotationAxis.y*v1.x)+
                pow(sin(angle/2),2)*(2*rotationAxis.z*(rotationAxis.x*v1.x+rotationAxis.y*v1.y)-
                v1.z*(pow(rotationAxis.x,2)+pow(rotationAxis.y,2)-pow(rotationAxis.z,2)));
    return Vec3D(xf,yf,zf);
}
*/
void Segment::setMidPoint(){
    this->midPoint.x = (this->v1.x+this->v2.x)/2;
    this->midPoint.y = (this->v1.y+this->v2.y)/2;
}

void Segment::setNormal(){
    float a = this->v2.x-this->v1.x;
    float b = this->v2.y-this->v1.y;
    float uVect = sqrt(pow(a,2) + pow(b,2));
    if(this->facingDir == 1){ 
        this->normal.x = this->midPoint.x+(a*cos(M_PI/2)-b*sin(M_PI/2))*2/uVect;
        this->normal.y = this->midPoint.y+(a*sin(M_PI/2)+b*cos(M_PI/2))*2/uVect;
    }else{
        this->normal.x = this->midPoint.x-(a*cos(M_PI/2)-b*sin(M_PI/2))*2/uVect;
        this->normal.y = this->midPoint.y-(a*sin(M_PI/2)+b*cos(M_PI/2))*2/uVect;
    }
}

Vec3D::Vec3D(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}
Vec3D::Vec3D(float x, float y, float z, int index){
    this->x = x;
    this->y = y;
    this->z = z;
    this->index = index; // rmove later used for debugging
}
Vec3D::Vec3D(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
};
void Vec3D::normalize(){
    float norm = 1/sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    *this *= norm;
}
void Vec3D::rotate(Vec3D rotationAxis, float angle){
    float w = cos(angle/2);
    Vec3D u = rotationAxis*sin(angle/2);
    Vec3D v = Vec3D(this->x,this->y,this->z);
    *this = u*2*getDot(u,v) + v*(pow(w,2)-getDot(u,u)) + getCross(u,v)*2*w;
}
void Vec3D::rotateX(float angle){
    float w = cos(angle/2);
    Vec3D u = Vec3D(1,0,0)*sin(angle/2);
    Vec3D v = Vec3D(this->x,this->y,this->z);
    *this = u*2*getDot(u,v) + v*(pow(w,2)-getDot(u,u)) + getCross(u,v)*2*w;
}
void Vec3D::rotateY(float angle){
    float w = cos(angle/2);
    Vec3D u = Vec3D(0,1,0)*sin(angle/2);
    Vec3D v = Vec3D(this->x,this->y,this->z);
    *this = u*2*getDot(u,v) + v*(pow(w,2)-getDot(u,u)) + getCross(u,v)*2*w;
}
void Vec3D::rotateZ(float angle){
    float w = cos(angle/2);
    Vec3D u = Vec3D(0,0,1)*sin(angle/2);
    Vec3D v = Vec3D(this->x,this->y,this->z);
    *this = u*2*getDot(u,v) + v*(pow(w,2)-getDot(u,u)) + getCross(u,v)*2*w;
}
Vec3D Vec3D::operator+(const Vec3D& rhs){
    return Vec3D(x+rhs.x,y+rhs.y,z+rhs.z);
}
Vec3D Vec3D::operator-(const Vec3D& rhs){
    return Vec3D(x-rhs.x,y-rhs.y,z-rhs.z);
}
Vec3D Vec3D::operator*(const float& rhs){
    return Vec3D(x*rhs,y*rhs,z*rhs);
}
Vec3D& Vec3D::operator+=(const Vec3D& rhs){
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
    return *this;
}
Vec3D& Vec3D::operator-=(const Vec3D& rhs){
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;
    return *this;
}
Vec3D& Vec3D::operator*=(const float& rhs){
    this->x *= rhs;
    this->y *= rhs;
    this->z *= rhs;
    return *this;
}
/*
Vec3D Vec3D::operator+(const Vec3D& vec){
    return Vec3D(x+vec.x,y+vec.y,z+vec.z);
}
Vec3D Vec3D::operator+=(const Vec3D& vec){
    return *this = Vec3D(x+vec.x,y+vec.y,z+vec.z);
}
Vec3D Vec3D::operator-(const Vec3D& vec){
    return Vec3D(x-vec.x,y-vec.y,z-vec.z);
}
Vec3D Vec3D::operator-=(const Vec3D& vec){
    return *this = Vec3D(x-vec.x,y-vec.y,z-vec.z);
}
Vec3D Vec3D::operator*(const float& multiplier){
    return Vec3D(x*multiplier,y*multiplier,z*multiplier);
}
Vec3D Vec3D::operator*=(const float& multiplier){
    return *this = Vec3D(x*multiplier,y*multiplier,z*multiplier);
}
*/