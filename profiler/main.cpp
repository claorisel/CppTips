#include <iostream>
#include <vector>
#include "profiler.h"
#include "range.h"

using namespace std;


int main() {

    {
//        Profiler x("hello");
        PROFILER("Hello")
//        PROFILER()
        vector<double> vd;

        for(int i = 0; i < 10000000; i++)
        {
            vd.push_back(i * 999);
        }


        for (double &v : Range(vd, 4))
        {
            cout << v << " ";
        }
        cout << endl;

    }
    return 0;
}