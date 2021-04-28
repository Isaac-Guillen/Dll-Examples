#include "static.h"

namespace ExampleLibrary
{
    int MsgPrinter::Add(int a, int b)
    {
        return a+b;
    }

    void MsgPrinter::PrintMessage()
    {
        std::cout << "Hello from a dynamic library!" << std::endl;
    }
}
