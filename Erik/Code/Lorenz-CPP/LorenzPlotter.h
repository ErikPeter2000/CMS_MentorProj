#include "LorenzAttractor.h"
#include "LorenzSettings.h"

#pragma once
#ifndef LORENZ_PLOTTER_H
#define LORENZ_PLOTTER_H
class LorenzPlotter
{
private:
	VariableLorenzSettings _settings;
	void drawCircle(sf::Image& image, int centerX, int centerY, int radius, sf::Color color);
public:
	LorenzPlotter(VariableLorenzSettings settings) : _settings(settings) {}
	void PlotMultipleTrajectories(sf::Image& image, DrawSettings drawSettings);
};

#define LORENZ_PLOTTER_H
#endif // !LORENZ_PLOTTER_H