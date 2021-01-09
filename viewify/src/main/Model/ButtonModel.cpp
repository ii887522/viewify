#include "ButtonModel.h"
#include "../Struct/Rect.h"
#include <Any/AnimatedAny.h>
#include <functional>
#include <stdexcept>

using std::function;
using std::runtime_error;

namespace ii887522::viewify
{
	ButtonModel::Builder::Builder(const Rect<int>& rect) : rect{ rect }, a{ 255u }, aDuration{ 0u }, hasSetADuration{ false },
		lightnessDuration{ 0u }, hasSetLightnessDuration{ false }, hasSetOnMouseOver{ false }, hasSetOnMouseOut{ false }, hasSetOnClick{ false }
	{ }

	ButtonModel::Builder& ButtonModel::Builder::setOnMouseOver(const function<void()>& value)
	{
		onMouseOver = value;
		hasSetOnMouseOver = true;
		return *this;
	}

	ButtonModel::Builder& ButtonModel::Builder::setOnMouseOut(const function<void()>& value)
	{
		onMouseOut = value;
		hasSetOnMouseOut = true;
		return *this;
	}

	ButtonModel::Builder& ButtonModel::Builder::setOnClick(const function<void()>& value)
	{
		onClick = value;
		hasSetOnClick = true;
		return *this;
	}

	ButtonModel ButtonModel::Builder::build()
	{
		if (!hasSetADuration) throw runtime_error{ "ButtonModel alpha duration is required!" };
		if (!hasSetLightnessDuration) throw runtime_error{ "ButtonModel lightness duration is required!" };
		if (!hasSetOnMouseOver) throw runtime_error{ "ButtonModel onMouseOver is required!" };
		if (!hasSetOnMouseOut) throw runtime_error{ "ButtonModel onMouseOut is required!" };
		if (!hasSetOnClick) throw runtime_error{ "ButtonModel onClick is required!" };
		return ButtonModel{ *this };
	}

	ButtonModel::ButtonModel(const Builder& builder) : rect{ builder.rect },
		state{ State::INITIAL }, lightness{ AnimatedAny<float>::Builder{ 1.f }.setDuration(builder.lightnessDuration).build() },
		a{ AnimatedAny<int>::Builder{ static_cast<int>(builder.a) }.setDuration(builder.aDuration).build() }, onMouseOver{ builder.onMouseOver },
		onMouseOut{ builder.onMouseOut }, onClick{ builder.onClick } { }
}
