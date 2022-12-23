#pragma once

#include <memory>
#include <ostream>
#include <string>

namespace vc {

class GroupOfFrames {};

class VirtualEncoder {
 public:
  using Ptr = std::shared_ptr<VirtualEncoder>;

  virtual void init(const std::string& filepath) = 0;

  virtual void encode(const GroupOfFrames& frames, std::ostream& os) = 0;
};

}  // namespace vc