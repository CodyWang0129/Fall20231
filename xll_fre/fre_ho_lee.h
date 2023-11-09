// fre_ho_lee.h - Ho-Lee interest rate model for constant futures and volatility.
#pragma once
#include <cmath>
#include <random>

namespace fre::ho_lee {

	// E[exp(N)] = exp(E[N] + Var(N)/2)
	inline double Eexp(const std::normal_distribution<double>& N)
	{
		return std::exp(N.mean() + N.sigma() * N.sigma() / 2);
	}

	// D(t) = E[D_t] = ???
	inline double ED(double φ, double σ, double t)
	{
		return std::exp(-φ * t - 0.5 * σ * σ * t * t); // !!!
	}

	// φ(t) - f(t) = ???
	inline double convexity(double σ, double t)
	{
		return 0.5 * σ * σ * t; // !!!
	}

	// log D_t(u) = ???
	// Return mean and standard deviation of log D_t(u).
	inline std::normal_distribution<double> logD(double φ, double σ, double t, double u)
	{
		double mean = -φ * u - 0.5 * σ * σ * t * u;
		double std_dev = σ * std::sqrt(t * u);
		return std::normal_distribution<double>(mean, std_dev); // !!!
	}

	// φ(u) - f_t(u) = ???
	// Return mean and standard deviation of φ_t(u) - f_t(u)
	inline std::normal_distribution<double> convexity(double σ, double t, double u)
	{
		double mean = 0.5 * σ * σ * t * u;
		double std_dev = σ * std::sqrt(t * u);
		return std::normal_distribution<double>(mean, std_dev); // !!!
	}

} // namespace fre::ho_lee
