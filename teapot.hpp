#ifndef _TEAPOT_HPP_
#define _TEAPOT_HPP_

/*****************************************************************************/


class Teapot
{
public:

	 int getCurentVolume() const { return current_vol; };
	 int getSerialNumber() const { return unique_num; };
	 int getCurrentTemperature() const { return cur_temp;};
	 int getMaxVolume() const { return max_vol; };
	 int getBoilingSpeed() const { return boiling_speed; };
	 bool isOn() const { return status; }
	 
	 void addWater(int _vol);
	 void takeWater(int _vol);
	 void switchOn() { status = true; };
	 void switchOff() { status = false; }

	 void updateState(int _minuts);

	 virtual ~Teapot() = default;
protected:

	Teapot(int _max_vol, int _num, int _speed);

	void changeVol(int _new);

	virtual void BoledReaction() = 0;
	virtual void EmtpyReaction() = 0;
private:

	static const int room_temperature = 20;
	int cur_temp;

	int current_vol;
	int max_vol;
	
	int unique_num;
	int boiling_speed;

	bool status = false;
};


inline
Teapot::Teapot(int _max_vol, int _num, int _speed)
	:max_vol(_max_vol), boiling_speed(_speed), unique_num(_num), 
	cur_temp(20), current_vol(0)
{
}


/*****************************************************************************/

#endif // _TEAPOT_HPP_#pragma once
