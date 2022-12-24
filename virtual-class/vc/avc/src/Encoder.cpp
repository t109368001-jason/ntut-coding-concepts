#include <vc/Encoder.h>

#include <iostream>

namespace vc {

VideoEncoder::VideoEncoder(const std::string& filepath) {
  std::cout << "AVCEncoder()" << std::endl;
  this->loadParameter(filepath);
}

void VideoEncoder::encode(const GroupOfFrame& frames, std::vector<char>& bytes) {
  std::cout << "AVCEncoder.encode()" << std::endl;
}

void VideoEncoder::loadParameter(const std::string& filepath) {
  parameter_ = Parameter();
  std::cout << "AVCEncoder::loadParameter()" << std::endl;
}

}  // namespace vc
