#include <vc/Encoder.h>

#include <iostream>

namespace vc {

void loadParameter(const std::string& filepath, Parameter& parameter) {
  std::cout << "vc::loadParameter()" << std::endl;
}

VideoEncoder::VideoEncoder(const Parameter& parameter) : parameter_(parameter) {
  std::cout << "Encoder()" << std::endl;
}

void VideoEncoder::encoding(const GroupOfFrame& frames, std::vector<char>& bytes) {
  std::cout << "Encoder.compress()" << std::endl;
}

}  // namespace vc
