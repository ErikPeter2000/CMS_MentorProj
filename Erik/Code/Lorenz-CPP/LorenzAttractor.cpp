#include "LorenzAttractor.h"
LorenzAttractor::LorenzAttractor(const LorenzSettings settings)
	: _settings(settings), _position(settings.x0, settings.y0, settings.z0)
{};
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