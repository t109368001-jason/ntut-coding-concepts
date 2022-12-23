#pragma once

#include <CoderType.h>
#include <VirtualEncoder.h>

namespace vc {

VirtualEncoder::Ptr create(const CoderType& coderType);

}  // namespace vc