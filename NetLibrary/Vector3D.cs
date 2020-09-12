using System;

namespace NetLibrary
{
    public class Vector3D
    {
        public double x;
        public double y;
        public double z;

        public Vector3D(double x, double y, double z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public double Length 
        {
            get
            {
                return this.CalculateLength();
            }
        }
        
        public string License
        {
            get
            {
                return "Vector3D library";
            }
        }

        private double CalculateLenght()
        {
            return Math.Sqrt(this.x*this.x + this.y*this.y + this.z+this.z);
        }
    }
}
