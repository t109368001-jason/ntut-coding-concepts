#include <parser/AVCEncoderParser.h>

namespace vc {

void AVCEncoderParser::init(const std::string& filepath) {
  encoder_ = std::make_shared<avc::AVCEncoder>(filepath);
}

void AVCEncoderParser::encode(const GroupOfFrames& frames, std::ostream& os) {
  if (!encoder_) {
    throw std::logic_error("uninitialized error");
  }
  avc::AVCGroupOfFrame avcFrames = toAVCFrames(frames);
  std::vector<char>    bytes;
  encoder_->encode(avcFrames, bytes);
  for (const char& byte : bytes) {
    os << byte;
  }
}

avc::AVCGroupOfFrame AVCEncoderParser::toAVCFrames(const GroupOfFrames& frames) {
  return {};
}

}  // namespace vc