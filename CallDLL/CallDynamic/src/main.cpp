#include <iostream>
#include "static.h"

int main() 
{
    std::cout << "Hello World!"<< std::endl;
    ExampleLibrary::MsgPrinter p;
    p.PrintMessage();
    return 0;
}
