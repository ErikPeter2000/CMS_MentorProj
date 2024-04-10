#include "LorenzAttractor.h"
LorenzAttractor::LorenzAttractor(LorenzSettings settings)
{
	_position = sf::Vector3<double>(settings.x0, settings.y0, settings.z0);
	_settings = settings;
}
sf::Vector3<double> LorenzAttractor::Next()
{
	double dx = _settings.sigma * (_position.y - _position.x);
	double dy = _position.x * (_settings.rho - _position.z) - _position.y;
	double dz = _position.x * _position.y - _settings.beta * _position.z;
	_position.x += dx * _settings.dt;
	_position.y += dy * _settings.dt;
	_position.z += dz * _settings.dt;
	return _position;
}