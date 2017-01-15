/// @file
/// @brief Contains ClimateModelCrahesData declaration
/// @author Alexander Soroka
/// @since 1/13/17.
/// @copyright

namespace dataset
{

template <class FeatureType>
ClimateModelCrashesData<FeatureType>::ClimateModelCrashesData(const std::string& filepath)
    : filepath_(filepath)
{
    ReadData();
}

template <class FeatureType>
const char* ClimateModelCrashesData<FeatureType>::Description() const
{
    return "https://archive.ics.uci.edu/ml/datasets/Climate+Model+Simulation+Crashes#";
}

template <class FeatureType>
const std::vector<generic::ObjectDescription> ClimateModelCrashesData<FeatureType>::TrainData() const
{
    return train_data_;
}

template <class FeatureType>
const std::vector<generic::ObjectDescription>
ClimateModelCrashesData<FeatureType>::TestData() const
{
    return test_data_;
}

template <class FeatureType>
void ClimateModelCrashesData<FeatureType>::ReadData()
{
    std::ifstream input(filepath_);
    std::string line;
    int64_t line_number = 0;
    std::vector<generic::ObjectDescription> dataset;

    while (input.good())
    {
        std::getline(input, line);

        // skip header
        if (line_number++ == 0)
        {
            continue;
        }

        generic::ObjectDescription object;
        this->ParseLine(line, object.second, object.first);
        dataset.push_back(object);
    }

    Bake(dataset, 0.8);
}

template <class FeatureType>
void ClimateModelCrashesData<FeatureType>::Bake(
        std::vector<generic::ObjectDescription>& object, double factor)
{
    if (factor < 0 || factor >= 1)
    {
        throw std::invalid_argument("shuffle factor must be in (0, 1)");
    }

    std::size_t training_size = object.size() * factor;
    std::cout << "Dataset contains " << object.size() << " objects, "
              << training_size << " for trainig" << std::endl;
    while (training_size-- > 0)
    {
        std::size_t random_object = rand() % (object.size() - 1);
        train_data_.push_back(object[random_object]);
        object.erase(object.begin() + random_object);
    }
    test_data_ = object;
    object.clear();
}
} // namespace dataset
