/// @file
/// @brief Contains ClimateModelCrahesData declaration
/// @author Alexander Soroka
/// @since 1/13/17.
/// @copyright

#ifndef SVM_PERFORMANCE_EVALUATION_DATASETS_CLIMATE_MODEL_CRASHES_H
#define SVM_PERFORMANCE_EVALUATION_DATASETS_CLIMATE_MODEL_CRASHES_H

#include <fstream>
#include <sstream>
#include <vector>

#include "generic/line_base.h"

namespace dataset
{
/// @link https://archive.ics.uci.edu/ml/datasets/Climate+Model+Simulation+Crashes#
template <class FeatureType = double>
class ClimateModelCrashesData : public generic::LineBase<FeatureType, 2, 20>
{
public:
    /// @brief Initiate dataset
    /// @param[in] filepath path to the file that contains dataset
    explicit ClimateModelCrashesData(const std::string& filepath);

    /// @return dataset description
    const char* Description() const;

    /// @return data for training
    const std::vector<generic::ObjectDescription > TrainData() const;

    /// @return data for verification
    const std::vector<generic::ObjectDescription > TestData() const;

protected:
    /// @brief read dataset from specified file
    /// @todo: move to common base
    void ReadData();

    /// @brief Split dataset to train and test part based on specified factor
    /// @param[in] dataset data to be splitted, can be erased by method
    /// @param[in] factor how many data will be in train set
    void Bake(std::vector<generic::ObjectDescription>& dataset, double factor);

private:
    std::vector<generic::ObjectDescription> train_data_;
    std::vector<generic::ObjectDescription> test_data_;

    const std::string& filepath_;
};
}

#include "climate_model_crashes.inl"

#endif // SVM_PERFORMANCE_EVALUATION_DATASETS_CLIMATE_MODEL_CRASHES_H

