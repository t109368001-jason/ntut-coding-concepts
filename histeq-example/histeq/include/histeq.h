#pragma once

#include <opencv2/core.hpp>

namespace ntut {

void histeq(const cv::Mat& input, cv::Mat& output);

}  // namespace ntut