#include "FrameTimer.h"

FrameTimer::FrameTimer()
{
	timePoint = std::chrono::steady_clock::now();
}

const float FrameTimer::Mark()
{
	auto last = timePoint;
	timePoint = std::chrono::steady_clock::now();
	std::chrono::duration<float> duration = (timePoint - last);
	return duration.count();
}
