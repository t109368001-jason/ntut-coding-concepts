#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/quality/qualitymse.hpp>

#include <histeq.h>

double computeMSE(const cv::Mat& img1, const cv::Mat& img2) {
  if (img1.total() != img2.total()) {
    throw std::logic_error("computeMSE() size of inputs are not matched");
  }
  double sse = 0.0;
  for (auto it1 = img1.begin<uchar>(), it2 = img2.begin<uchar>();  //
       it1 != img1.end<uchar>() && it2 != img2.end<uchar>();       //
       ++it1, ++it2) {
    sse += (*it1 - *it2) * (*it1 - *it2);
  }
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

  cv::Mat i1, i2, i3;
  cv::hconcat(histEq1, cvHistEq1, i1);
  cv::hconcat(histEq2, cvHistEq2, i2);
  cv::hconcat(histEq3, cvHistEq3, i3);

  cv::imshow("origin", origin);
  cv::imshow("cvHistEq1, mse=" + std::to_string(computeMSE(histEq1, cvHistEq1)), i1);
  cv::imshow("cvHistEq2, mse=" + std::to_string(computeMSE(histEq2, cvHistEq2)), i2);
  cv::imshow("cvHistEq3, mse=" + std::to_string(computeMSE(histEq3, cvHistEq3)), i3);

  while (cv::waitKey(100) != 'q') {
  }

  return 0;
}
