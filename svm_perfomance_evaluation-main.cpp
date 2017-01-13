/// @file
/// @brief Contains application entry point
/// @author Alexander Soroka
/// @since 1/13/17.
/// @copyright

#include <iostream>
#include <thread>

#include "test.h"

class SleepTest
{
public:
    const char* Name() const
    {
        return "Sleepy";
    }

    void Execute() const
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
};

class NullData
{
public:
    const char* Description() const
    {
        return "Null dataset";
    }
};

int main()
{
    TestExecutor::Evaluate(SleepTest(), NullData());
    return 0;
}
