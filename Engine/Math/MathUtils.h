#pragma once



namespace math
{
	constexpr float Pi = 3.1415926539f;
	constexpr float TwoPi = 6.28318530718f;
	constexpr float HalfPi = 1.5707963268f;

	int sqr(int v);
	inline int half(int v) { return v / 2; }

	constexpr float DegToRad(float degrees)
	{
		return degrees * (Pi / 180);
	}

	constexpr float RedToDeg(float radians)
	{
		return radians * (180 / Pi);
	}
}
