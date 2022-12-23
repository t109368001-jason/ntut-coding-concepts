#include <CoderType.h>

#include <algorithm>
#include <stdexcept>

namespace vc {

CoderType parseCoderType(std::string type) {
  std::transform(type.begin(), type.end(), type.begin(), [](const char& c) { return std::toupper(c); });
  if (type == "AVC" || type == "264") {
    return CoderType::AVC;
  } else if (type == "HEVC" || type == "265") {
    return CoderType::HEVC;
  } else if (type == "VVC" || type == "266") {
    return CoderType::VVC;
  } else {
    throw std::logic_error("invalid coder type");
  }
}

}  // namespace vc
