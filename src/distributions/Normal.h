#ifndef NORMAL_H
#define NORMAL_H

#include "Law.h"

class Normal : public Law {
public:
	Normal(double mean, double std);

	const double Density(double x);
	const double Cumulative(double x);
	const double InverseCumulative(double x);
	const double Quantile(double x);
};

#endif // !NORMAL_H
