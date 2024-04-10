#include <random>

#define M_PI 3.14159265358979323846

#pragma once
#ifndef NORMAL_VARIABLE_H
#define NORMAL_VARIABLE_H

struct NormalVariable
{
	double Mean;
	double Variance;
	NormalVariable(double mean, double variance)
	{
		Mean = mean;
		Variance = variance;
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
		return Mean + Variance * randStdNormal;
	}

};

#endif // !NORMAL_VARIABLE_H