/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace style {
struct InfiniteRadialAnimation;
} // namespace style

namespace Ui {

class RadialAnimation {
public:
	RadialAnimation(AnimationCallbacks &&callbacks);

	float64 opacity() const {
		return _opacity;
	}
	bool animating() const {
		return _animation.animating();
	}

	void start(float64 prg);
	void update(float64 prg, bool finished, TimeMs ms);
	void stop();

	void step(TimeMs ms);
	void step() {
		step(getms());
	}

	void draw(Painter &p, const QRect &inner, int32 thickness, style::color color);

private:
	TimeMs _firstStart = 0;
	TimeMs _lastStart = 0;
	TimeMs _lastTime = 0;
	float64 _opacity = 0.;
	anim::value a_arcEnd;
	anim::value a_arcStart;
	BasicAnimation _animation;

};

class InfiniteRadialAnimation {
public:
	InfiniteRadialAnimation(AnimationCallbacks &&callbacks);

	float64 opacity() const {
		return _opacity;
	}
	bool animating() const {
		return _animation.animating();
	}

	void start();
	void update(bool finished, TimeMs ms);
	void stop();

	void step(TimeMs ms);
	void step() {
		step(getms());
	}

	void draw(
		Painter &p,
		QPoint position,
		int outerWidth,
		const style::InfiniteRadialAnimation &st);

private:
	float64 _opacity = 0.;
	TimeMs _start = 0;
	TimeMs _changed = 0;
	bool _finished = false;
	BasicAnimation _animation;

};

} // namespace Ui
