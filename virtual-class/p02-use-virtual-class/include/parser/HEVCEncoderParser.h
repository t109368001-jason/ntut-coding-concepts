#pragma once

#include <stdexcept>

#include <hevc/HEVCEncoder.h>

#include <VirtualEncoder.h>

namespace vc {

class HEVCEncoderParser : public VirtualEncoder {
 protected:
  std::shared_ptr<hevc::HEVCEncoder> encoder_;

 public:
  HEVCEncoderParser() = default;

  void init(const std::string& filepath) override;

  void encode(const GroupOfFrames& frames, std::ostream& os) override;

  static hevc::HEVCGroupOfFrame toHEVCFrames(const GroupOfFrames& frames);
};

}  // namespace vc