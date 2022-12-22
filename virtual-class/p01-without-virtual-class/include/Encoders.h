#pragma once

#include <ostream>
#include <memory>
#include <string>

#include <avc/AVCEncoder.h>
#include <hevc/HEVCEncoder.h>
#include <vvc/VVCEncoder.h>

namespace vc {

using VirtualParameterPtr = std::shared_ptr<void>;
using VirtualEncoderPtr   = std::shared_ptr<void>;
using AVCEncoderPtr       = std::shared_ptr<avc::AVCEncoder>;
using HEVCParameterPtr    = std::shared_ptr<hevc::HEVCParameter>;
using HEVCEncoderPtr      = std::shared_ptr<hevc::HEVCEncoder>;
using VVCParameterPtr     = std::shared_ptr<vvc::VVCParameter>;
using VVCEncoderPtr       = std::shared_ptr<vvc::VVCEncoder>;

class GroupOfFrames {};

void avcInit(const std::string& configFile, VirtualEncoderPtr& encoder);
void hevcInit(const std::string& configFile, VirtualParameterPtr& parameter, VirtualEncoderPtr& encoder);
void vvcInit(const std::string& configFile, VirtualParameterPtr& parameter, VirtualEncoderPtr& encoder);

avc::AVCGroupOfFrame   toAVCFrames(const GroupOfFrames& frames);
hevc::HEVCGroupOfFrame toHEVCFrames(const GroupOfFrames& frames);
vvc::VVCGroupOfFrame   toVVCFrames(const GroupOfFrames& frames);

void avcEncode(avc::AVCEncoder& avcEncoder, std::ostream& os, const GroupOfFrames& frames);
void hevcEncode(hevc::HEVCEncoder& hevcEncoder, std::ostream& os, const GroupOfFrames& frames);
void vvcEncode(vvc::VVCEncoder& vvcEncoder, std::ostream& os, const GroupOfFrames& frames);

}  // namespace vc