#include <cmath>
#include "Normal.h"
#include "../utils/Constants.h"

Normal::Normal(double mean, double std) {
	this->mean = mean;
	this->std = std;
}

const double Normal::Density(double x) {
	return 1 / (std * sqrt(2 * PI)) * exp(-pow(x - mean, 2) / (2 * pow(std, 2)));
}

const double Normal::Cumulative(double x) {
	return 0.5 * (1 + erf((x - mean) / (std * sqrt(2))));
}

// Beasley-Springer-Boro method for the inverse cumulative normal distribution
const double Normal::InverseCumulative(double x) {
	static double a[4] = {
		2.50662823884,
		-18.61500062529,
		41.39119773534,
		-25.44106049637
	};
	static double b[4] = { 
		-8.47351093090,
		23.08336743743,
		-21.06224101826,
		3.13082909833
	};
	static double c[9] = {
		0.3374754822726147,
		0.9761690190917186,
		0.1607979714918209,
		0.0276438810333863,
		0.0038405729373609,
		0.0003951896511919,
		0.0000321767881768,
		0.0000002888167364,
		0.0000003960315187
	};

	double y = x - 0.5;
	double r;

	if (fabs(x) < 0.42) {
		r = y * y;
		r = y * (((a[3] * r + a[2]) * r + a[1]) * r + a[0]) /
			((((b[3] * r + b[2]) * r + b[1]) * r + b[0]) * r + 1);
	}
	else {
		r = x;
		if (x > 0) {
			r = 1 - x;
		}
		r = log(-log(r));
		r = c[0] + r * (c[1] + r * (c[2] + r * (c[3] + r * (c[4] + r * (c[5] + r * (c[6] + r * (c[7] + r * c[8])))))));
		if (x < 0) {
			r = -r;
		}
	}

	return mean + std * r;
}

const double Normal::Quantile(double x) {
	return InverseCumulative(x);
}