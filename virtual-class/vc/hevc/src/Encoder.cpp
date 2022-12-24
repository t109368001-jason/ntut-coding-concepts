#include <vc/Encoder.h>

#include <iostream>

namespace vc {

void loadParameter(const std::string& filepath, Parameter& parameter) {
  std::cout << "vc::loadParameter()" << std::endl;
}

void VideoEncoder::init(const Parameter& parameter) {
  parameter_ = parameter;
  std::cout << "Encoder.init()" << std::endl;
}

void VideoEncoder::compress(const GroupOfFrame& frames, std::ostream& os) {
  std::cout << "Encoder.compress()" << std::endl;
}

}  // namespace vc
