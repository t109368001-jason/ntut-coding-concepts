#pragma once

#include <string>
#include <vector>

namespace hevc {

struct HEVCParameter {};

struct HEVCGroupOfFrame {};

void loadParameter(const std::string& filepath, HEVCParameter& parameter);

class HEVCEncoder {
 protected:
  HEVCParameter parameter_;

 public:
  void init(const HEVCParameter& parameter);

  void compress(const HEVCGroupOfFrame& frames, std::ostream& os);
};

}  // namespace hevc