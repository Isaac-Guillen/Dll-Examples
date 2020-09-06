using System;
using System.Diagnostics;

namespace NETapp
{
    class Program
    {
        static void Main(string[] args)
        {
            Stopwatch stpw = new Stopwatch();
            stpw.Start();

            Console.WriteLine("Hello World!");
            Console.WriteLine("We are about to call the library");

            SafeNativeMethods.SayHelloToPython();

            double[ , , ] array3D = new double[ , , ] { { {1, 2, 3}, 
                                                          {3, 4, 5} },

                                                        { {5, 6, 7}, 
                                                          {7, 8, 9} } };

            Console.WriteLine("The array's dimensions are [{0},{1},{2}]", array3D.GetLength(2), array3D.GetLength(1), array3D.GetLength(0));
            SafeNativeMethods.PrintArray(array3D, array3D.Length, array3D.GetLength(2), array3D.GetLength(1), array3D.GetLength(0));
            stpw.Stop();
            Console.WriteLine("Elapsed time (MilliSeconds) = {0}", stpw.ElapsedMilliseconds);
        }                                 
    }
}