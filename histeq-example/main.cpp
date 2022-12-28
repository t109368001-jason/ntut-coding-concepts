#include <algorithm>
#include <iostream>
#include <numeric>

#include <opencv2/opencv.hpp>
#include <opencv2/quality/qualitymse.hpp>

#include <histeq.h>

double computeMSE(const cv::Mat& img1, const cv::Mat& img2) {
  if (img1.total() != img2.total()) {
    throw std::logic_error("computeMSE() size of inputs are not matched");
  }
  //  double sse = 0.0;
  //  for (auto it1 = img1.begin<uchar>(), it2 = img2.begin<uchar>();  //
  //       it1 != img1.end<uchar>() && it2 != img2.end<uchar>();       //
  //       ++it1, ++it2) {
  //    sse += (*it1 - *it2) * (*it1 - *it2);
  //  }
  double sse = std::transform_reduce(img1.begin<uchar>(), img1.end<uchar>(), img2.begin<uchar>(), 0.0, std::plus{},
                                     [](auto& a, auto& b) { return (a - b) * (a - b); });
  return sse / (double)img1.total();
}

int main() {
  const cv::Mat origin = cv::imread("lena_gray.bmp", cv::IMREAD_GRAYSCALE);

  cv::Mat histEq1, histEq2, histEq3;
  cv::Mat cvHistEq1, cvHistEq2, cvHistEq3;

  ntut::histeq(origin, histEq1);
  cv::equalizeHist(origin, cvHistEq1);
  ntut::histeq(histEq1, histEq2);
  cv::equalizeHist(cvHistEq1, cvHistEq2);
  ntut::histeq(histEq2, histEq3);
  cv::equalizeHist(cvHistEq2, cvHistEq3);

  cv::Mat histEq1Group, histEq2Group, histEq3Group;
  cv::hconcat(histEq1, cvHistEq1, histEq1Group);
  cv::hconcat(histEq2, cvHistEq2, histEq2Group);
  cv::hconcat(histEq3, cvHistEq3, histEq3Group);

  cv::imshow("origin", origin);
  cv::imshow(std::string("histEq1(impl/opencv)")                              //
                 + ", mse=" + std::to_string(computeMSE(histEq1, cvHistEq1))  //
                 + ", mse01=" + std::to_string(computeMSE(origin, histEq1)),
             histEq1Group);
  cv::imshow(std::string("histEq2(impl/opencv)")                              //
                 + ", mse=" + std::to_string(computeMSE(histEq2, cvHistEq2))  //
                 + ", mse12=" + std::to_string(computeMSE(histEq1, histEq2)),
             histEq2Group);
  cv::imshow(std::string("histEq3(impl/opencv)")                              //
                 + ", mse=" + std::to_string(computeMSE(histEq3, cvHistEq3))  //
                 + ", mse23=" + std::to_string(computeMSE(histEq2, histEq3)),
             histEq3Group);

  while (cv::waitKey(100) != 'q') {
  }

  return 0;
}
