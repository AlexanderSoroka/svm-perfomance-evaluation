/// @file
/// @brief Contains Test definition
/// @author Alexander Soroka
/// @since 1/14/17.
/// @copyright

#ifndef SVM_PERFOMANCE_EVALUATION_TEST_H
#define SVM_PERFOMANCE_EVALUATION_TEST_H

#include <sstream>
#include "scoped_timer.h"

/// @brief Measure amount of time that some code snippet (Test) takes to execute
///        on the specified dataset (TestData)
class TestExecutor
{
public:
    template <class Test, class TestData>
    static void Evaluate(const Test& test, const TestData& data)
    {
        std::stringstream test_description;
        test_description << "test=" << test.Name()
                         << ", dataset=" << data.Description();
        ScopedTimer timer(test_description.str());
        test.Execute();
    }
};

#endif // SVM_PERFOMANCE_EVALUATION_TEST_H
