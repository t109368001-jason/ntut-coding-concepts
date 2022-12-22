#pragma once

#include <string>

namespace vc {

enum class CoderType {
  AVC  = 264,
  HEVC = 265,
  VVC  = 266,
};

CoderType parseCoderType(std::string type);

}  // namespace vc
