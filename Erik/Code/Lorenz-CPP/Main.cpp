#include <SFML/Graphics.hpp>
#include "LorenzSettings.h"
#include "LorenzAttractor.h"
#include "LorenzPlotter.h"
#include "DrawSettings.h"
#include <chrono>
#include <iostream>


int getIntParam(std::map<std::string, std::string>& args, std::string key, int defaultValue)
{
	if (args.find(key) != args.end())
	{
		return std::stoi(args[key]);
	}
	return defaultValue;
}
double getDoubleParam(std::map<std::string, std::string>& args, std::string key, double defaultValue)
{
	if (args.find(key) != args.end())
	{
		return std::stod(args[key]);
	}
	return defaultValue;
}
bool argsContains(std::map<std::string, std::string>& args, std::string key)
{
	return args.find(key) != args.end();
}
std::string getStringParam(std::map<std::string, std::string>& args, std::string key, std::string defaultValue)
{
	if (args.find(key) != args.end())
	{
		return args[key];
	}
	return defaultValue;
}

int main(int argc, char* argv[])
{
	// parse args
	std::map<std::string, std::string> args;
	for (int i = 1; i < argc; i ++)
	{
		std::string arg = argv[i];
		if (arg == "--nodisplay")
		{
			args[arg] = "true";
			continue;
		}
		args[arg] = argv[i + 1];
		i++;
	}

	printf("Calculating...\n");
	const unsigned int width = getIntParam(args, "--width", 1800);
	const unsigned int height = getIntParam(args, "--height", 1000);

	sf::RenderWindow window(sf::VideoMode(width, height), "Lorenz Trajectories");

	sf::Sprite sprite;
	sf::Texture texture;

	window.setFramerateLimit(30);

	// Create an image
	sf::Image image;
	image.create(width, height, sf::Color::Black);

	// draw settings, note that the camera uses orthographic projection
	DrawSettings drawSettings(width, height, getIntParam(args, "--steps", 50000));
	drawSettings.PlotTrajectory = true;
	drawSettings.CameraRotationX = 1.75;
	drawSettings.CameraRotationY = -0.88;
	drawSettings.CameraPosition = sf::Vector3<double>(0, 22, 20);
	drawSettings.EndSize = getIntParam(args, "--radius", 2);

	// attractor settings
	VariableLorenzSettings lorenzSettings;
	const double sd = getDoubleParam(args, "--sd", 0.001);
	lorenzSettings.sigma = NormalVariable(10, 0);
	lorenzSettings.rho = NormalVariable(28, 0);
	lorenzSettings.beta = NormalVariable(8.0 / 3.0, 0);
	lorenzSettings.x0 = NormalVariable(0, sd);
	lorenzSettings.y0 = NormalVariable(1, sd);
	lorenzSettings.z0 = NormalVariable(0, sd);
	lorenzSettings.dt = getDoubleParam(args, "--dt", 0.0001);
	lorenzSettings.attractorCount = getIntParam(args, "--count", 100);

	// calculate and plot trajectories
	auto start = std::chrono::high_resolution_clock::now();
	LorenzPlotter plotter = LorenzPlotter(lorenzSettings);
	plotter.PlotMultipleTrajectories(image, drawSettings);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	std::cout << "Time taken: " << duration.count() << " ms" << std::endl;

	if (argsContains(args, "--file"))
	{
		std::string filename = getStringParam(args, "--file", "output.png");
		if (!image.saveToFile(filename))
		{
			std::cerr << "Failed to save image to file" << std::endl;
		}
		else
		{
			std::cout << "Image saved to " << filename << std::endl;
		}
	}

	if (!argsContains(args, "--nodisplay"))
	{
		// display the image
		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();
			}
			texture.loadFromImage(image);
			sprite.setTexture(texture);
			window.clear();
			window.draw(sprite);
			window.display();
		}
	}
	return 0;
}