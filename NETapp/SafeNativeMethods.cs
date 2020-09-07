using System;
using System.Runtime.InteropServices;
using System.Security;

namespace NETapp
{
    [SuppressUnmanagedCodeSecurity]
    public static class SafeNativeMethods
    {
        private const string libraryName = "libtest.so";

        [DllImport(libraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void SayHelloFromCpp();

        [DllImport(libraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void PrintArray(double[,,] array, int arraySize, int x, int y, int z);
    }
}