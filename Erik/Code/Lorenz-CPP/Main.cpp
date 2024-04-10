#include <SFML/Graphics.hpp>
#include "LorenzSettings.h"
#include "LorenzAttractor.h"
#include "LorenzPlotter.h"
#include "DrawSettings.h"
#include <chrono>
#include <iostream>


int main()
{
	printf("Calculating...\n");
	const unsigned int width = 1800;
	const unsigned int height = 1000;

	sf::RenderWindow window(sf::VideoMode(width, height), "Lorenz Trajectories");

	sf::Sprite sprite;
	sf::Texture texture;

	window.setFramerateLimit(30);

	// Create an image
	sf::Image image;
	image.create(width, height, sf::Color::Black);

	// draw settings, note that the camera uses orthographic projection
	DrawSettings drawSettings(width, height, 50000);
	drawSettings.PlotTrajectory = true;
	drawSettings.CameraRotationX = 1.75;
	drawSettings.CameraRotationY = -0.88;
	drawSettings.CameraPosition = sf::Vector3<double>(0, 22, 20);

	// attractor settings
	VariableLorenzSettings lorenzSettings;
	const double variance = 0.000001;
	lorenzSettings.sigma = NormalVariable(10, 0);
	lorenzSettings.rho = NormalVariable(28, 0);
	lorenzSettings.beta = NormalVariable(8.0 / 3.0, 0);
	lorenzSettings.x0 = NormalVariable(0, variance);
	lorenzSettings.y0 = NormalVariable(1, variance);
	lorenzSettings.z0 = NormalVariable(0, variance);
	lorenzSettings.dt = 0.00055;
	lorenzSettings.attractorCount = 100000;

	// calculate and plot trajectories
	auto start = std::chrono::high_resolution_clock::now();
	LorenzPlotter plotter = LorenzPlotter(lorenzSettings);
	plotter.PlotMultipleTrajectories(image, drawSettings);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	std::cout << "Time taken: " << duration.count() << " ms" << std::endl;

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
	return 0;
}