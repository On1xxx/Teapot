#include "manualteapot.hpp"
#include "messages.hpp"
#include <iostream>

void ManualTeapot::BoledReaction()
{
	double p = static_cast<double>(getCurentVolume()) / 100.0;
	if (p > (int)p)
		p++;
	int z = static_cast<int>(p);
	double x =  z* 5.0;
	boiled_water_capacity = static_cast<int>(x);
	changeVol(static_cast<int>(x));
}

void ManualTeapot::EmtpyReaction()
{
	++missed_warnings;
	if (missed_warnings >= warnings)
		throw std::logic_error(Messages::TeapotAlmostBurned);
}