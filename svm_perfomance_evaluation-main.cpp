/// @file
/// @brief Contains application entry point
/// @author Alexander Soroka
/// @since 1/13/17.
/// @copyright

#include <iostream>
#include <thread>

#include "scoped_timer.h"

int main()
{
    ScopedTimer timer(__PRETTY_FUNCTION__);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    return 0;
}