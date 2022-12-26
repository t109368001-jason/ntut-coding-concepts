#pragma once

#include <stdexcept>

#include <VirtualEncoder.h>

namespace vcs {

class AVCEncoderParser : public VirtualEncoder {
 protected:
  std::shared_ptr<void> encoder_;

 public:
  AVCEncoderParser() = default;

  void init(const std::string& filepath) override;

  void encode(const GroupOfFrames& frames, std::ostream& os) override;
};

}  // namespace vcs