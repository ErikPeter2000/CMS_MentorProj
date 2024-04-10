#include "LorenzPlotter.h"
#include <iostream>

std::vector<sf::Color> GeneratePalette(int size, double saturation = 1, double intensity = 1)
{
	std::vector<sf::Color> palette(size);
	for (int i = 0; i < size; i++)
	{
		int r = 0;
		int g = (int)((255 * i / size) * saturation + 255 - saturation * 255) * intensity;
		int b = (int)((255 * (size - i) / size) * saturation + 255 - saturation * 255) * intensity;
		palette[i] = sf::Color::Color(r, g, b);
	}
	return palette;
}

void LorenzPlotter::PlotMultipleTrajectories(sf::Image& image, DrawSettings drawSettings)
{
	std::vector<sf::Color> palette = GeneratePalette(_settings.size, 1, 0.6);
	std::vector<std::unique_ptr<LorenzAttractor>> lorenzAttractors(_settings.size);
	for (int i = 0; i < _settings.size; i++)
	{
		lorenzAttractors[i] = std::make_unique<LorenzAttractor>(_settings.GetSettings());
	}
	int lastProgress = -1;
	int progress = 0;
	int updateStep = 10;
	int incrememnt = drawSettings.Steps / updateStep;
	int minX = -(drawSettings.Width / 2)/drawSettings.Zoom/ drawSettings.Width;
	int maxX = (drawSettings.Width / 2) / drawSettings.Zoom / drawSettings.Width;
	int minY = -(drawSettings.Height / 2) / drawSettings.Zoom / drawSettings.Height;
	int maxY = (drawSettings.Height / 2) / drawSettings.Zoom / drawSettings.Height;
	for (int i = 0; i < drawSettings.Steps; i++) {
		for (int j = 0; j < _settings.size; j++)
		{
			sf::Vector3<double> position = lorenzAttractors[j]->Next();
			if (position.x > minX && position.x < maxX && position.y > minY && position.y < maxY)
			{
				int x = (int)(position.x * drawSettings.Width * drawSettings.Zoom + drawSettings.Width / 2);
				int y = (int)(position.y * drawSettings.Height * drawSettings.Zoom + drawSettings.Height / 2);
				sf::Color newColor = palette[j];
				image.setPixel(x, y, newColor);
				if (i == drawSettings.Steps - 1 && drawSettings.PlotEnd)
				{
					drawCircle(image, x, y, drawSettings.EndSize, drawSettings.EndColor);
				}
			}
		}
		progress = i / incrememnt;
		if (progress != lastProgress)
		{
			std::cout << progress* updateStep << "%" << std::endl;
			lastProgress = progress;
		}
	}
	std::cout << "100% " << std::endl;
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