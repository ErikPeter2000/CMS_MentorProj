#include "LorenzPlotter.h"
#include <iostream>
#include <omp.h>
#include <math.h>

static inline sf::Color generateColor(int attractorId, int maxAttractors, int step, int maxSteps, double z)
{
	sf::Uint8 r = 128 - step * 128 / maxSteps;
	sf::Uint8 g = 255-(sf::Uint8)std::min(((z + 2) * 4), 255.0);
	sf::Uint8 b = step * 128 / maxSteps;
	return sf::Color::Color(r, g, b);
}

static inline sf::Vector3<double> rotateX(sf::Vector3<double> position, double angle)
{
	double y = position.y;
	position.y = y * cos(angle) - position.z * sin(angle);
	position.z = y * sin(angle) + position.z * cos(angle);
	return position;
}

static inline sf::Vector3<double> rotateY(sf::Vector3<double> position, double angle)
{
	double x = position.x;
	position.x = x * cos(angle) - position.z * sin(angle);
	position.z = x * sin(angle) + position.z * cos(angle);
	return position;
}

void LorenzPlotter::PlotMultipleTrajectories(sf::Image& image, DrawSettings drawSettings)
{
	// create the attractors
	std::vector<std::unique_ptr<LorenzAttractor>> lorenzAttractors(_settings.attractorCount);
	for (int i = 0; i < _settings.attractorCount; i++)
	{
		lorenzAttractors[i] = std::make_unique<LorenzAttractor>(_settings.GetSettings());
	}

	// progress display
	int lastProgress = -1;
	int progress = 0;
	int updateStep = 5;
	int incrememnt = drawSettings.SimulationSteps / updateStep;

	// bounds for the plot, calculated first to avoid recalculating them for each step
	int minX = -(drawSettings.Width / 2) / drawSettings.Zoom / drawSettings.Width;
	int maxX = (drawSettings.Width / 2) / drawSettings.Zoom / drawSettings.Width;
	int minY = -(drawSettings.Height / 2) / drawSettings.Zoom / drawSettings.Height;
	int maxY = (drawSettings.Height / 2) / drawSettings.Zoom / drawSettings.Height;
	int minDim = std::min(drawSettings.Width, drawSettings.Height);

	// plot the trajectories
	for (int i = 0; i < drawSettings.SimulationSteps; i++) {
		#pragma omp parallel for // parallelise the loop.
		for (int j = 0; j < _settings.attractorCount; j++)
		{
			// get the next position of the attractor
			sf::Vector3<double> position = lorenzAttractors[j]->Next();
			auto drawPosition = rotateX(position, drawSettings.CameraRotationX);
			drawPosition = rotateY(drawPosition, drawSettings.CameraRotationY);
			drawPosition += drawSettings.CameraPosition;
			// calculate screen position
			int x = (int)(drawPosition.x * minDim * drawSettings.Zoom + drawSettings.Width / 2);
			int y = (int)(drawPosition.y * minDim * drawSettings.Zoom + drawSettings.Height / 2);
			if (x > 0 && x < drawSettings.Width && y > 0 && y < drawSettings.Height)
			{
				auto color = generateColor(j, _settings.attractorCount, i, drawSettings.SimulationSteps, position.z);
				image.setPixel(x, y, color);
				// draw a circle at the end of the trajectory
				if (i == drawSettings.SimulationSteps - 1 && drawSettings.PlotEnd)
				{
					drawCircle(image, x, y, drawSettings.EndSize, drawSettings.EndColor);
				}
			}
		}

		// update progress
		progress = i / incrememnt;
		if (progress != lastProgress)
		{
			std::cout << progress * 100 / updateStep << "%" << std::endl;
			lastProgress = progress;
		}
	}
	std::cout << "100%" << std::endl;
}

void LorenzPlotter::drawCircle(sf::Image& image, int centerX, int centerY, int radius, sf::Color color)
{
	for (int y = -radius; y <= radius; y++)
	{
		for (int x = -radius; x <= radius; x++)
		{
			if (x * x + y * y <= radius * radius)
			{
				int imageX = centerX + x;
				int imageY = centerY + y;
				if (imageX >= 0 && imageX < image.getSize().x && imageY >= 0 && imageY < image.getSize().y)
				{
					image.setPixel(imageX, imageY, color);
				}
			}
		}
	}
}