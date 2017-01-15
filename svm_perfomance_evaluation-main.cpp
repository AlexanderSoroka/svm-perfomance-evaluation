/// @file
/// @brief Contains application entry point
/// @author Alexander Soroka
/// @since 1/13/17.
/// @copyright

#include <iostream>
#include <thread>

#include "datasets/climate_model_crashes.h"
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
    dataset::ClimateModelCrashesData<double> data_model("/projects/uci-datasets/climate-model-crashes/pop_failures.dat");
    TestExecutor::Evaluate(SleepTest(), NullData());
    return 0;
}
