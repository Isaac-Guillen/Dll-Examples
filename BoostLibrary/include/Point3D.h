#ifndef __POINT3D_H__
#define __POINT3D_H__

#include "cuda_runtime.h"
#include "device_launch_parameters.h"

class Point3D
{
public:
    double x;
    double y;
    double z;

    __host__ __device__ Point3D(double x, double y, double z);
};

#endif
