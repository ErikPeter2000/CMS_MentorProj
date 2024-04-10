#include <SFML/Graphics.hpp>
#include "LorenzSettings.h"
#include "LorenzAttractor.h"
#include "LorenzPlotter.h"
#include "DrawSettings.h"
#include "NormalVariable.h"

int main()
{
	printf("Hello World\n");
	const unsigned int width = 1800;
	const unsigned int height = 1000;

	sf::RenderWindow window(sf::VideoMode(width, height), "Lorenz Trajectories");

	sf::Sprite sprite;
	sf::Texture texture;

	window.setFramerateLimit(30);

	// Create an image
	sf::Image image;
	image.create(width, height, sf::Color::Black);

	DrawSettings drawSettings(width, height, 310000, 0.018);
	drawSettings.PlotTrajectory = true;
	VariableLorenzSettings lorenzSettings;
	const double variance = 0.00001;

	lorenzSettings.sigma = NormalVariable(10, 0);
	lorenzSettings.rho = NormalVariable(28, 0);
	lorenzSettings.beta = NormalVariable(8.0 / 3.0, 0);
	lorenzSettings.x0 = NormalVariable(0, variance);
	lorenzSettings.y0 = NormalVariable(1, 0);
	lorenzSettings.z0 = NormalVariable(0, 0);
	lorenzSettings.dt = 0.0001;
	lorenzSettings.size = 1000;
	LorenzPlotter plotter = LorenzPlotter(lorenzSettings);
	plotter.PlotMultipleTrajectories(image, drawSettings);

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