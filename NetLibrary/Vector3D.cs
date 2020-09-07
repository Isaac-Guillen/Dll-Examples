using System;

namespace NetLibrary
{
    public class Vector3D
    {
        public double x;
        public double y;
        public double z;

        Vector3D(double x, double y, double z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public double Lenght 
        {
            get
            {
                return this.CalculateLenght();
            }
        }

        private double CalculateLenght()
        {
            return Math.Sqrt(this.x*this.x + this.y*this.y + this.z+this.z);
        }
    }
}