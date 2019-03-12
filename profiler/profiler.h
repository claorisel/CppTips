//
// Created by Nadezhda Churikova on 2019-03-12.
//

#ifndef PROFILER_PROFILER_H
#define PROFILER_PROFILER_H

#include <chrono>
#include <string>
#include <iostream>

#define PROFILER_0() Profiler prof();
#define PROFILER_1(A) Profiler prof(A);

#define PROFILER_X(x,A,FUNC, ...)  FUNC

// The macro that the programmer uses
#define PROFILER(...)                    PROFILER_X(,##__VA_ARGS__,\
                                         PROFILER_1(__VA_ARGS__),\
                                         PROFILER_0(__VA_ARGS__)\
                                         )

class Profiler {
public:
    Profiler(const std::string msg =""):
    msg(msg),
    start(std::chrono::system_clock::now())
    {}

    ~Profiler()
    {
        finish = std::chrono::system_clock::now();
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
        std:: cout << msg << " " << ms.count() << " ms" << std::endl;

    }

//    auto x = time_point std::chrono::high_resolution_clock::now();
private:
    std::string msg;
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> finish;



};


#endif //PROFILER_PROFILER_H
