/// @file
/// @brief Contains ScopedTimer definition
/// @author Alexander Soroka
/// @since 1/13/17.
/// @copyright

#include "scoped_timer.h"

#include <iostream>

ScopedTimer::ScopedTimer(const std::string& message)
    : message_(message)
    , start_(std::chrono::high_resolution_clock::now())
{
    std::cerr << "[timer " << message_ << "] start";
}

ScopedTimer::~ScopedTimer()
{
    std::chrono::nanoseconds duration = std::chrono::high_resolution_clock::now()
                                       - start_;
    std::cerr << "[timer " << message_ << "] elapsed " << duration.count() << ", ns";
}
