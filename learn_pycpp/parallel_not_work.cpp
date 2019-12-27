
#ifndef PARALLEL_NOT_WORK
#define PARALLEL_NOT_WORK

#define BOOST_PYTHON_STATIC_LIB
#include <ctime>
#include <string>
#include <boost/python.hpp>
#include <iostream>

namespace py = boost::python;
using namespace std;

void wait(double seconds)
{
    clock_t delay = seconds * CLOCKS_PER_SEC;
    clock_t start = clock();
    while (clock() - start < delay){}; 
    return;
}

void test(py::str name)
{
    string cpp_name = py::extract<string>(name);
    for (int i = 0; i < 10; i++)
    {
        cout << "parallel_not_work.test(" + cpp_name + ") " << i << endl;
        wait(0.2);
    }
    return;
}

BOOST_PYTHON_MODULE(parallel_not_work)
{
    using namespace boost::python;
    def("test", test);
}



#endif // !PARALLEL_NOT_WORK


