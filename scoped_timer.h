/// @file
/// @brief Contains ScopedTimer declaration
/// @author Alexander Soroka
/// @since 1/13/17.
/// @copyright

#ifndef SVM_PERFOMANCE_EVALUATION_SCOPED_TIMER_H
#define SVM_PERFOMANCE_EVALUATION_SCOPED_TIMER_H

#include <chrono>
#include <string>

/// @brief Simple timer that is based on RAII principle - start measurement in constructor
///        and finishes in destructor
class ScopedTimer
{
public:
    /// @brief Starts measurement and logs it
    /// @param[in] message prefix for timer message
    explicit ScopedTimer(const std::string& message);

    /// @brief Log result
    ~ScopedTimer();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_;
    std::string message_;
};

#endif //SVM_PERFOMANCE_EVALUATION_SCOPED_TIMER_H_H
