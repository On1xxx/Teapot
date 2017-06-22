#ifndef _AUTOMATICTEAPOT_HPP_
#define _AUTOMATICTEAPOT_HPP_

/*****************************************************************************/

#include "teapot.hpp"

/*****************************************************************************/

class AutomaticTeapot
	: public Teapot
{
public:
	AutomaticTeapot(int _max_vol, int _speed, int _unique_num = 0);

	virtual void BoledReaction() override { switchOff(); };
	virtual void EmtpyReaction() override { switchOff(); };
};

inline
AutomaticTeapot::AutomaticTeapot(int _max_vol, int _speed, int _unique_num)
	:Teapot(_max_vol, _unique_num, _speed)
{
}

/*****************************************************************************/

#endif // _AUTOMATICTEAPOT_HPP_#pragma once
