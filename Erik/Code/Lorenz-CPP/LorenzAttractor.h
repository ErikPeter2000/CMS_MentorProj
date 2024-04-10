#include <SFML/Graphics.hpp>
#include "LorenzSettings.h"
#include "DrawSettings.h"


#pragma once
#ifndef LORENZATTRACTOR_H
class LorenzAttractor
{
private:
	LorenzSettings _settings;
	sf::Vector3<double> _position;
public:
	LorenzAttractor(LorenzSettings settings);
	sf::Vector3<double> Next();
};
#define LORENZATTRACTOR_H
#endif // !LORENZATTRACTOR_H