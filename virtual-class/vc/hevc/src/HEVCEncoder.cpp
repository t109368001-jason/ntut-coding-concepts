#include <hevc/HEVCEncoder.h>

#include <iostream>

namespace hevc {

void loadParameter(const std::string& filepath, HEVCParameter& parameter) {
  std::cout << "hevc::loadParameter()" << std::endl;
}

void HEVCEncoder::init(const HEVCParameter& parameter) {
  parameter_ = parameter;
  std::cout << "HEVCEncoder.init()" << std::endl;
}

void HEVCEncoder::compress(const HEVCGroupOfFrame& frames, std::ostream& os) {
  std::cout << "HEVCEncoder.compress()" << std::endl;
}

}  // namespace hevc
