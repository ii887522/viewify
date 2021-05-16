// Copyright ii887522

#include "ImageModel.h"
#include <nitro/Any/AnimatedAny.h>
#include <stdexcept>

using std::runtime_error;
using ii887522::nitro::AnimatedAny;

namespace ii887522::viewify {

ImageModel ImageModel::Builder::build() {
  if (hasSetDuration) return ImageModel{ *this };
  throw runtime_error{ "ImageModel duration is required!" };
}

ImageModel::ImageModel(const Builder& builder) :
  a{ AnimatedAny<int>::Builder{ static_cast<int>(builder.a) }.setDuration(builder.duration).build() } { }

}  // namespace ii887522::viewify
