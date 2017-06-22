#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_

#include <memory>
#include <set>
#include <vector>
/*****************************************************************************/

#include "teapot.hpp"

class Controller
{

	/*-----------------------------------------------------------------*/

public:

	/*-----------------------------------------------------------------*/

	Controller() = default;

	Controller(const Controller &) = delete;

	Controller & operator = (const Controller &) = delete;

	~Controller() = default;

	/*-----------------------------------------------------------------*/

	void createManualTeapot(int _maxVolume, int _speed);

	void createAutomaticTeapot(int _maxVolume, int _speed);

	/*-----------------------------------------------------------------*/

	int getTeapotCurrentVolume(int _teapotIndex) const;

	int getTeapotMaxVolume(int _teapotIndex) const;

	int getTeapotCurrentTemperature(int _teapotIndex) const;

	int getTeapotBoilingSpeed(int _teapotIndex) const;

	/*-----------------------------------------------------------------*/

	bool isTeapotOn(int _teapotIndex) const;

	void turnOnTeapot(int _teapotIndex);

	void turnOffTeapot(int _teapotIndex);

	/*-----------------------------------------------------------------*/

	void addWater(int _teapotIndex, int _volume);

	void takeWater(int _teapotIndex, int _volume);

	/*-----------------------------------------------------------------*/

	void wait(int _minutesCount);

	/*-----------------------------------------------------------------*/

private:

	std::vector< std::unique_ptr<Teapot> > setteapot;


};

/*****************************************************************************/

#endif // _CONTROLLER_HPP_#pragma once
