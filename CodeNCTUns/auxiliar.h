/* 
 * File:   auxiliar.h
 * Author: LuisUrquiza
 *
 * Created on 24 de abril de 2013, 9:06
 */

#ifndef AUXILIAR_H
#define	AUXILIAR_H
#include <math.h>


/*---------------------------------------------------------------------------
 * gaussian()
 *
 * Gaussian random number generator.
 *
 * Arguments:
 *	min, max
 *
 * Returns:
 *	a Gaussian random number between min and max
 *
 * Side effects:
 *      no side effect.
 *
 * References:
 *	http://www.bearcave.com/misl/misl_tech/wavelets/hurst/random.html
 *---------------------------------------------------------------------------*/
double gaussian(double min, double max)
{
	double x1, x2, w, y, f1, f2;

	while (1)
	{
		do {
			f1 = (random() % 1000) / 1000.0;
			f2 = (random() % 1000) / 1000.0;

			x1 = 2.0 * f1 - 1.0;
			x2 = 2.0 * f2 - 1.0;
			w = x1 * x1 + x2 * x2;
		} while (w >= 1.0);

		w = sqrtf((-2.0 * log(w)) / w);
		y = x2 * w;

		if (y >= min && y <= max)
		{
			return y;
		}
	}
}


double gaussian_normal(double avg, double std)
{
	/*
	 * avg = average
	 * std = standard deviation
	 */
	static int parity = 0;
	static double nextresult;
	double x1, x2, w, f1, f2;

	if(std == 0) return avg;
	if(parity == 0){
		while (1)
		{
			do {
				f1 = (random() % 1000) / 1000.0;
				f2 = (random() % 1000) / 1000.0;

				x1 = 2.0 * f1 - 1.0;
				x2 = 2.0 * f2 - 1.0;
				w = x1 * x1 + x2 * x2;
			} while (w >= 1.0);

			w = sqrtf((-2.0 * log(w)) / w);
			nextresult = x2 * w;
			parity = 1;
			return (x1 * w * std + avg);
		}
	}
	else{
		parity = 0;
		return (nextresult * std + avg);
	}
}


#endif	/* AUXILIAR_H */

