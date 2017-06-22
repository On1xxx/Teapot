#include "controller.hpp"
#include "messages.hpp"
#include "manualteapot.hpp"
#include "automaticteapot.hpp"

#include <algorithm>

void Controller::createManualTeapot(int _maxVolume, int _speed)
{
	if (_maxVolume < 0)
		throw std::logic_error(Messages::NonPositiveVolume);

	if (_speed < 0)
		throw std::logic_error(Messages::NonPositiveSpeed);

	setteapot.push_back
	(
		std::unique_ptr<ManualTeapot>
		(
			new ManualTeapot(_maxVolume, _speed, static_cast<int>(setteapot.size()))
		)
	);
}

void Controller::createAutomaticTeapot(int _maxVolume, int _speed)
{
	if (_maxVolume < 0)
		throw std::logic_error(Messages::NonPositiveVolume);

	if (_speed < 0)
		throw std::logic_error(Messages::NonPositiveSpeed);

	setteapot.push_back
	(
		std::unique_ptr<AutomaticTeapot>
		(
			new AutomaticTeapot(_maxVolume, _speed, static_cast<int>(setteapot.size()))
		)
	);
}

int Controller::getTeapotCurrentVolume(int _teapotIndex) const
{
	for (auto const & x : setteapot)
		if (x->getSerialNumber() == _teapotIndex)
			return x->getCurentVolume();

	throw std::logic_error(Messages::WrongTeapotIndex);
}

int Controller::getTeapotMaxVolume(int _teapotIndex) const
{
	for (auto const & x : setteapot)
		if (x->getSerialNumber() == _teapotIndex)
			return x->getMaxVolume();
	
	
	throw std::logic_error(Messages::WrongTeapotIndex);

}

int Controller::getTeapotCurrentTemperature(int _teapotIndex) const
{
	for (auto const & x : setteapot)
		if (x->getSerialNumber() == _teapotIndex)
			return x->getCurrentTemperature();
	
	throw std::logic_error(Messages::WrongTeapotIndex);
	
}

int Controller::getTeapotBoilingSpeed(int _teapotIndex) const
{

	for (auto const & x : setteapot)
		if (x->getSerialNumber() == _teapotIndex)
			return x->getBoilingSpeed();

	throw std::logic_error(Messages::WrongTeapotIndex);
	
}


bool Controller::isTeapotOn(int _teapotIndex) const
{
	for (auto const & x : setteapot)
		if (x->getSerialNumber() == _teapotIndex)
			return x->isOn();

	throw std::logic_error(Messages::WrongTeapotIndex);	
}

void Controller::turnOnTeapot(int _teapotIndex)
{
	for (auto const & x : setteapot)
		if (x->getSerialNumber() == _teapotIndex)
		{
			x->switchOn();
			return;
		}

	throw std::logic_error(Messages::WrongTeapotIndex);

}

void Controller::turnOffTeapot(int _teapotIndex)
{
	for (auto const & x : setteapot)
		if (x->getSerialNumber() == _teapotIndex)
		{
			x->switchOff();
			return;
		}

	throw std::logic_error(Messages::WrongTeapotIndex);
}

void Controller::addWater(int _teapotIndex, int _volume)
{
	if(_volume < 0)
		throw std::logic_error(Messages::NonPositiveVolume);

	for (auto const & x : setteapot)
		if (x->getSerialNumber() == _teapotIndex)
		{
			x->addWater(_volume);
			return;
		}

	throw std::logic_error(Messages::WrongTeapotIndex);

}

void Controller::takeWater(int _teapotIndex, int _volume)
{
	if (_volume < 0)
		throw std::logic_error(Messages::NonPositiveVolume);

	for (auto const & x : setteapot)
		if (x->getSerialNumber() == _teapotIndex)
		{
			x->takeWater(_volume);
			return;
		}

	throw std::logic_error(Messages::WrongTeapotIndex);
}

void Controller::wait(int _minutesCount)
{
	for (auto const & x : setteapot)
	{
		x->updateState(_minutesCount);
	}
}
