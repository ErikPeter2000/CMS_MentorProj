#include <SFML/Graphics.hpp>
#include <random>

constexpr double M_PI = 3.14159265358979323846;

#pragma once

struct LorenzSettings
{
	double sigma;
	double rho;
	double beta;
	double dt;
	double x0;
	double y0;
	double z0;
};

struct NormalVariable
{
public:
	double Mean;
	double StandardDeviation;
	NormalVariable(double mean, double standardDeviation)
	{
		Mean = mean;
		StandardDeviation = standardDeviation;
	}
	NormalVariable() : NormalVariable(0, 1) { }

	double GetValue()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(0, 1);

		double u1 = dis(gen);
		double u2 = dis(gen);
		double randStdNormal = sqrt(-2.0 * log(u1)) * sin(2.0 * M_PI * u2);
		return Mean + StandardDeviation * randStdNormal;
	}

};

struct VariableLorenzSettings
{
	NormalVariable sigma;
	NormalVariable rho;
	NormalVariable beta;
	NormalVariable x0;
	NormalVariable y0;
	NormalVariable z0;
	double dt;
	int attractorCount;

	LorenzSettings GetSettings()
	{
		LorenzSettings settings;
		settings.sigma = sigma.GetValue();
		settings.rho = rho.GetValue();
		settings.beta = beta.GetValue();
		settings.x0 = x0.GetValue();
		settings.y0 = y0.GetValue();
		settings.z0 = z0.GetValue();
		settings.dt = dt;
		return settings;
	}
};