#include <boost/python.hpp>
#include "Vector3D.h"
#include "Point3D.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(pylib)
{
    class_< Vector3D >("Vector3D", init<double, double, double>())
      .def("Norm", &Vector3D::Norm)
      .def("PrintCores", &Vector3D::PrintCores)
      .def_readwrite("x", &Vector3D::x)
      .def_readwrite("y", &Vector3D::y)
      .def_readwrite("z", &Vector3D::z);

    class_< Point3D >("Point3D", init<double, double, double>())
      .def_readwrite("x", &Point3D::x)
      .def_readwrite("y", &Point3D::y)
      .def_readwrite("z", &Point3D::z);
}