#include <SFML/Graphics.hpp>

#pragma once
#ifndef DRAWSETTINGS_H
struct DrawSettings
{
public:
	int Width;
	int Height;
	int SimulationSteps;
	double Zoom = 0.016;
	bool PlotTrajectory = false;
	bool PlotEnd = true;
	sf::Color EndColor = sf::Color::Red;
	int EndSize = 1;
	sf::Vector3<double> CameraPosition = sf::Vector3<double>(0, 0, 0);
	double CameraRotationX = 0;
	double CameraRotationY = 0;
	DrawSettings(int width, int height, int steps)
	{
		Width = width;
		Height = height;
		SimulationSteps = steps;
	};
	DrawSettings(int width, int height, int steps, double zoom)
	{
		Width = width;
		Height = height;
		SimulationSteps = steps;
		Zoom = zoom;
	};
};
#define DRAWSETTINGS_H
#endif // !DRAWSETTINGS_H