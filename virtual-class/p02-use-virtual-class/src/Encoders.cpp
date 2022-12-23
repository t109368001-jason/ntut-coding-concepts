#include <Encoders.h>

#include <stdexcept>

#include <parser/AVCEncoderParser.h>
#include <parser/HEVCEncoderParser.h>
#include <parser/VVCEncoderParser.h>

using namespace std;

namespace vc {

VirtualEncoder::Ptr create(const CoderType& coderType) {
  switch (coderType) {
    case CoderType::AVC: return make_shared<AVCEncoderParser>();
    case CoderType::HEVC: return make_shared<HEVCEncoderParser>();
    case CoderType::VVC: return make_shared<VVCEncoderParser>();
  }
  throw logic_error("invalid coder type");
}

}  // namespace vc