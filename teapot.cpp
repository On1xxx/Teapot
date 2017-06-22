#include "teapot.hpp"
#include "messages.hpp"
#include <iostream>
#include "automaticteapot.hpp"

void Teapot::updateState(int _minuts)
{
	if (!status)
	{
		for(int i = 0; i < _minuts; i++)
			if (cur_temp > room_temperature)
				cur_temp-= 2;
	}
	else
	{
		if (current_vol == 0)
			for (int i = 0; i < _minuts; i++)
				EmtpyReaction();
		else
		{
			AutomaticTeapot * a = dynamic_cast<AutomaticTeapot*>(this);
			

			if (cur_temp < 100)
			{
				int count = 0;
				while (cur_temp <= 100)
				{
					if (count == _minuts)
						break;

					cur_temp += boiling_speed;
					count++;
				}
				
				if (a && cur_temp >= 100)
					BoledReaction();

				for (int i = 0; i < _minuts - count; i++)
					if (cur_temp > room_temperature)
						cur_temp -= 2;

			}
			else
				for (int i = 0; i < _minuts; i++)
					BoledReaction();
			
		}
	}
}

void Teapot::changeVol(int _new)
{
	current_vol -= _new;
}

void Teapot::addWater(int _vol)
{
	if (current_vol + _vol > max_vol)
		throw std::logic_error(Messages::TeapotVolumeOverflow);

	if (status)
		throw std::logic_error(Messages::TeapotIsNotModifiable);

	current_vol += _vol;
}

void Teapot::takeWater(int _vol)
{
	if (current_vol - _vol < 0)
		throw std::logic_error(Messages::TeapotVolumeUnderflow);

	if (status)
		throw std::logic_error(Messages::TeapotIsNotModifiable);


	current_vol -= _vol;
}