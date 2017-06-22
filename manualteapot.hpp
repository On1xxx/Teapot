#ifndef _MANUALTEAPOT_HPP_
#define _MANUALTEAPOT_HPP_

/*****************************************************************************/

#include "teapot.hpp"

/*****************************************************************************/

class ManualTeapot
	: public Teapot
{
public:
	ManualTeapot(int _max_vol, int _speed, int _unique_num = 0);

	virtual void BoledReaction() override;
	virtual void EmtpyReaction() override;

	int getMissedWarnings() const { return missed_warnings; }
	int getBoiledWaterCapacity() const { return boiled_water_capacity; }

private:
	static const int warnings = 3;

	int missed_warnings = 0;
	int boiled_water_capacity = 0;

};

inline
ManualTeapot::ManualTeapot(int _max_vol, int _speed, int _unique_num)
	:Teapot(_max_vol, _unique_num, _speed),
	boiled_water_capacity(0), missed_warnings(0)
{
}

/*****************************************************************************/

#endif // _MANUALTEAPOT_HPP_#pragma once
