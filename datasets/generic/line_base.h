/// @file
/// @brief Contains ClimateModelCrahesData declaration
/// @author Alexander Soroka
/// @since 1/14/17.
/// @copyright

#ifndef SVM_PERFOMANCE_EVALUATION_DATASETS_GENERIC_ROW_BASE_H
#define SVM_PERFOMANCE_EVALUATION_DATASETS_GENERIC_ROW_BASE_H

namespace dataset
{
namespace generic
{

typedef std::pair<int, std::vector<double> > ObjectDescription;

/// @brief This concept implements line parser in assumption that
///        line has next structure:
///        <value1> ... <valueN> <feature1> ... <featureM> <label>
template <class FeatureType, int kFirstFeaturePosition, int kLabelPosition>
class LineBase
{
public:
    /// @brief parse line (it supposes one line describes one object) from dataset file
    /// @param[in] line line to be parsed
    /// @param[out] features destination where parsed features should land
    /// @param[out] label destination where parsed object value should land
    /// @todo: move to common base
    void ParseLine(const std::string& line,
                   typename ObjectDescription::second_type& features,
                   typename ObjectDescription::first_type& label)
    {
        std::stringstream line_stream(line);

        int64_t column_number = 0;
        FeatureType column;
        while (line_stream.good())
        {
            if (column_number++ < kLabelPosition)
            {
                line_stream >> column;
                std::cout << column << " ";
            }
            else
            {
                line_stream >> label;
                std::cout << label << std::endl;
            }

            if (column_number >= kFirstFeaturePosition)
            {
                features.push_back(column);
            }
        }
    }

};

} // namespace generic
} // dataset

#endif // SVM_PERFOMANCE_EVALUATION_DATASETS_GENERIC_ROW_BASE_H

