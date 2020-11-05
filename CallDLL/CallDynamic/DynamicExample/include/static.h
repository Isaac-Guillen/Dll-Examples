#ifndef __STATIC_H__
#define __STATIC_H__

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <iostream>

namespace ExampleLibrary
{
    class MsgPrinter
    {
        public:

        static int Add(int a, int b);

        static void PrintMessage();
    };
}

#endif
