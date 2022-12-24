#include <avc/AVCEncoder.h>

#include <iostream>

namespace avc {

AVCEncoder::AVCEncoder(const std::string& filepath) {
  std::cout << "AVCEncoder()" << std::endl;
  this->loadParameter(filepath);
}

void AVCEncoder::encode(const AVCGroupOfFrame& frames, std::vector<char>& bytes) {
  std::cout << "AVCEncoder.encode()" << std::endl;
}

void AVCEncoder::loadParameter(const std::string& filepath) {
  parameter_ = AVCParameter();
  std::cout << "AVCEncoder::loadParameter()" << std::endl;
}

}  // namespace avc
