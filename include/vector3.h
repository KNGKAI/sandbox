#ifndef VECTOR3_H
#define VECTOR3_H

struct Vector3
{
    public:
        Vector3() : x(0), y(0), z(0) { return; }
        Vector3(double x, double y, double z) : x(x), y(y), z(z) { return; }
        Vector3(double x, double y) : x(x), y(y), z(0) { return; }

        double x;
        double y;
        double z;
};

#endif