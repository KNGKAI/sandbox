#ifndef VECTOR3_H
#define VECTOR3_H

struct Vector3
{
    public:
        Vector3() {return;}
        Vector3(double x, double y, double z) : x(x), y(y), z(z) { return; }
        ~Vector3() {return;}
        double x;
        double y;
        double z;
};

#endif