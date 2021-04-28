#ifndef __STATIC_H__
#define __STATIC_H__

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <iostream>

#if defined(_WIN32) || defined(__WIN32__)
#   define DllExport __declspec(dllexport)
#elif defined(linux) || defined(__linux)
#   define DllExport 
#endif

namespace ExampleLibrary
{
    class DllExport MsgPrinter
    {
        public:

        static int Add(int a, int b);

        static void PrintMessage();
    };
}

#endif
