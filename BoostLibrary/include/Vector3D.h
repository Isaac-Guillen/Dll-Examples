#ifndef __VECTOR3D_H__
#define __VECTOR3D_H__

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "Point3D.h"

class Vector3D
{
public:
    double x;
    double y;
    double z;

    __host__ __device__ Vector3D(double x, double y, double z);

    __host__ __device__ Vector3D(const Point3D &point);

    __host__ __device__ double Norm();

    __host__ void PrintCores();
};

#endif