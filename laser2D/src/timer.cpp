#include "timer.h"

Timer::Timer(double duration, bool repeat, bool autoStart, std::function<void()> action) : duration(duration),
                                                                                        repeat(repeat), autoStart(autoStart), action(action)
{
    isActive = false;
    if (autoStart)
    {
        activate();
    }
}

Timer::Timer() : duration(0), repeat(true), autoStart(true), action([]() {}) {}

void Timer::update()
{
    if (!isActive)
    {
        return;
    }

    if (GetTime() - startTime < duration)
    {
        return;
    }

    deactivate();
}

void Timer::activate()
{
    isActive = true;
    startTime = GetTime();
    printf("***** activating timer *********\n");
}

void Timer::deactivate()
{
    isActive = false;
    startTime = 0;
    if (repeat)
    {
        activate();
    }
}
