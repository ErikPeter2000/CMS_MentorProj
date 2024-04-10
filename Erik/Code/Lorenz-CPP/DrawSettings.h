#include <SFML/Graphics.hpp>

#pragma once
#ifndef DRAWSETTINGS_H
struct DrawSettings
{
public:
	int Width;
	int Height;
	int Steps;
	double Zoom = 0.01;
	bool PlotTrajectory = false;
	bool PlotEnd = true;
	sf::Color EndColor = sf::Color::Red;
	int EndSize = 3;
	DrawSettings(int width, int height, int steps)
	{
		this->Width = width;
		this->Height = height;
		this->Steps = steps;
	};
	DrawSettings(int width, int height, int steps, double zoom)
	{
		this->Width = width;
		this->Height = height;
		this->Steps = steps;
		this->Zoom = zoom;
	};
};
#define DRAWSETTINGS_H
#endif // !DRAWSETTINGS_H