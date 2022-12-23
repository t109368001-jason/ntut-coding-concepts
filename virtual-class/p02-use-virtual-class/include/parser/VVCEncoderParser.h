#pragma once

#include <stdexcept>

#include <vvc/VVCEncoder.h>

#include <VirtualEncoder.h>

namespace vc {

class VVCEncoderParser : public VirtualEncoder {
 protected:
  std::shared_ptr<vvc::VVCEncoder> encoder_;

 public:
  VVCEncoderParser() = default;

  void init(const std::string& filepath) override;

  void encode(const GroupOfFrames& frames, std::ostream& os) override;

  static vvc::VVCGroupOfFrame toVVCFrames(const GroupOfFrames& frames);
};

}  // namespace vc