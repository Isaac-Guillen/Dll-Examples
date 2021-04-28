import numpy as np
import ctypes as cpp
from ctypes import*

dll = cpp.cdll.LoadLibrary('./build/test.so')
dll.SayHelloFromCpp.argstype = None
dll.SayHelloFromCpp.restype = None

dll.PrintArray.argtypes = [POINTER(c_double), c_size_t, c_size_t, c_size_t, c_size_t]
dll.PrintArray.restype = None

def CallCPPMethod(array):
    a = array.ctypes.data_as(POINTER(c_double))
    dll.PrintArray(a, array.size, array.shape[2], array.shape[1], array.shape[0])

#array = np.array([[[1,2,3],[3,4,5]],[[5,6,7],[7,8,9]]], dtype = np.double)

array = np.random.rand(2,2,3)

print(array)

CallCPPMethod(array)

dll.SayHelloFromCpp()
