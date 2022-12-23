#pragma once

#include <stdexcept>

#include <avc/AVCEncoder.h>

#include <VirtualEncoder.h>

namespace vc {

class AVCEncoderParser : public VirtualEncoder {
 protected:
  std::shared_ptr<avc::AVCEncoder> encoder_;

 public:
  AVCEncoderParser() = default;

  void init(const std::string& filepath) override;

  void encode(const GroupOfFrames& frames, std::ostream& os) override;

  static avc::AVCGroupOfFrame toAVCFrames(const GroupOfFrames& frames);
};

}  // namespace vc