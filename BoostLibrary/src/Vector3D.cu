#include "Vector3D.h"

__host__ __device__ Vector3D::Vector3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

__host__ __device__ Vector3D::Vector3D(const Point3D &point)
{
    this->x=point.x;
    this->y=point.y;
    this->z=point.z;
}

__host__ __device__ double Vector3D::Norm()
{
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

__host__ void Vector3D::PrintCores()
{
    #pragma omp parallel for
    for(int i = 0; i < 10; i++)
    {
        printf("Hello from thread %d \n", omp_get_thread_num());
    }
}