#include <vc/Encoder.h>

#include <iostream>

namespace vc {

inline void loadParameter(const std::string& filepath, Parameter& parameter) {
  std::cout << "VVCEncoder::loadParameter()" << std::endl;
}

VideoEncoder::VideoEncoder(const Parameter& parameter) : parameter_(parameter) {
  std::cout << "VVCEncoder()" << std::endl;
}

void VideoEncoder::encoding(const GroupOfFrame& frames, std::vector<char>& bytes) {
  std::cout << "VVCEncoder.compress()" << std::endl;
}

}  // namespace vc
