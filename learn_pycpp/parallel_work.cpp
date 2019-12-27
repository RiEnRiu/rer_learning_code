#ifndef PARALLEL_WORK
#define PARALLEL_WORK

#include <ctime>
#include <string>
#include <iostream>

using namespace std;

void wait(double seconds)
{
    clock_t delay = seconds * CLOCKS_PER_SEC;
    clock_t start = clock();
    while (clock() - start < delay) {};
    return;
}

extern "C"
{
    void test(string name)
    {
        string cpp_name = name;
        for (int i = 0; i < 10; i++)
        {
            cout << "parallel_work.test(" + cpp_name + ") " << i << endl;
            wait(0.2);
        }
        return;
    }
}



#endif // !PARALLEL_WORK


