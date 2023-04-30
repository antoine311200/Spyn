#ifndef LAW_H
#define LAW_H

class Law {
public:
	virtual const double Density(double x) = 0;
	virtual const double Cumulative(double x) = 0;
	virtual const double InverseCumulative(double x) = 0;
	virtual const double Quantile(double x) = 0;

	const double GetMean() { return mean; }
	const double GetStandardDeviation() { return std; }
protected:
	double mean;
	double std;
};

#endif
