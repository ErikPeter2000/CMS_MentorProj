#include "NormalVariable.h"
#include <SFML/Graphics.hpp>

#pragma once
#ifndef LORENZSETTINGS_H

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

struct VariableLorenzSettings
{
	NormalVariable sigma;
	NormalVariable rho;
	NormalVariable beta;
	NormalVariable x0;
	NormalVariable y0;
	NormalVariable z0;
	double dt;
	int size;

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

#define LORENZSETTINGS_H
#endif // !LORENZSETTINGS_H