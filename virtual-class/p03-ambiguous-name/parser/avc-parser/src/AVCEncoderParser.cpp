#include <AVCEncoderParser.h>

#include <vc/Encoder.h>

namespace vcs {

vc::GroupOfFrame toAVCFrames(const GroupOfFrames& frames);

void AVCEncoderParser::init(const std::string& filepath) {
  encoder_ = std::make_shared<vc::VideoEncoder>(filepath);
}

void AVCEncoderParser::encode(const GroupOfFrames& frames, std::ostream& os) {
  if (!encoder_) {
    throw std::logic_error("uninitialized error");
  }
  vc::GroupOfFrame  avcFrames = toAVCFrames(frames);
  std::vector<char> bytes;
  std::static_pointer_cast<vc::VideoEncoder>(encoder_)->encode(avcFrames, bytes);
  for (const char& byte : bytes) {
    os << byte;
  }
}

vc::GroupOfFrame toAVCFrames(const GroupOfFrames& frames) {
  return {};
}

}  // namespace vcs