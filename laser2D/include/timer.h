#pragma once
#include <functional>
#include "raylib.h"
class Timer
{
private:
    /* data */
    double duration;
    bool repeat;
    bool autoStart;
    bool isActive;
    double startTime;
    std::function<void()> action;

public:
    Timer();
    Timer(double duration, bool repeat, bool autoStart, std::function<void()> action);
    void activate();
    void deactivate();
    void update();
};
