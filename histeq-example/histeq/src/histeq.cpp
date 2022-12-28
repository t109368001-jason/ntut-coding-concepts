#include <histeq.h>

#include <algorithm>
#include <exception>
#include <execution>
#include <limits>
#include <map>
#include <vector>

namespace ntut {

using ValueType = std::remove_pointer_t<decltype(cv::Mat::data)>;

constexpr ValueType VALUE_TYPE_L_MINUS_1 =
    std::numeric_limits<ValueType>::max() - std::numeric_limits<ValueType>::min();

struct ValueTypeCmp {
  bool operator()(const ValueType& a, const ValueType& b) const {
    return a < b;
  }
};

void histeq(const cv::Mat& input, cv::Mat& output) {
  if (input.channels() != 1) {
    throw std::logic_error("histeq() error, invalid input format, supported types: [grayscale]");
  }

  std::vector<ValueType> values(input.rows * input.cols);
  values.assign(input.data, input.data + input.total());

  std::map<ValueType, double, ValueTypeCmp> pdf;
  for (const auto& value : values) {
    auto it = pdf.find(value);
    if (it == pdf.end()) {
      pdf[value] = 1;
    } else {
      pdf[value] = it->second + 1;
    }
  }
  for (auto& [value, p] : pdf) {
    p /= (double)input.total();
  }
  std::map<ValueType, double, ValueTypeCmp> cdf;
  {
    double cp = 0.0;
    for (const auto& [value, p] : pdf) {
      cp += p;
      cdf[value] = cp;
    }
  }

  std::map<ValueType, ValueType> valueMap;
  {
    double cdfMin = cdf.begin()->second;
    double cdfL   = 1.0 - cdfMin;
    for (const auto& [value, cp] : cdf) {
      valueMap[value] = (ValueType)std::round((cp - cdfMin) / cdfL * (double)VALUE_TYPE_L_MINUS_1);
    }
  }

  output = cv::Mat(input.rows, input.cols, input.type());

  // index version
  //  for (int i = 0; i < input.total(); i++) {
  //    output.at<ValueType>(i) = valueMap[input.at<ValueType>(i)];
  //  }

  // iter version
  //  auto itIn  = input.begin<ValueType>();
  //  auto itOut = output.begin<ValueType>();
  //  for (; itIn != input.end<ValueType>() && itOut != output.end<ValueType>();
  //       ++itIn, ++itOut) {  // NOLINT(modernize-loop-convert)
  //    *itOut = valueMap[*itIn];
  //  }

  // transform version
  std::transform(input.begin<ValueType>(), input.end<ValueType>(), output.begin<ValueType>(),
                 [&valueMap](const auto& value) { return valueMap[value]; });

  // parallel transform version (tbb required for linux)
  //  std::transform(std::execution::par, input.begin<ValueType>(), input.end<ValueType>(), output.begin<ValueType>(),
  //                 [&valueMap](const auto& value) { return valueMap[value]; });
}

}  // namespace ntut
