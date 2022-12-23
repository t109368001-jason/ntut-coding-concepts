#include <vvc/VVCEncoder.h>

#include <iostream>

namespace vvc {

void loadParameter(const std::string& filepath, VVCParameter& parameter) {
  std::cout << "vvc::loadParameter()" << std::endl;
}

VVCEncoder::VVCEncoder(const VVCParameter& parameter) : parameter_(parameter) {
  std::cout << "VVCEncoder()" << std::endl;
}

void VVCEncoder::encoding(const VVCGroupOfFrame& frames, std::vector<char>& bytes) {
  std::cout << "VVCEncoder.compress()" << std::endl;
}

}  // namespace vvc
