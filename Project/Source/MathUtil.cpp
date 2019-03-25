//------------------------------------------------------------------------------
//Includes
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "MathUtil.h"

#include <math.h>

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------



namespace MathUtil {


	//------------------------------------------------------------------------------
	//functions
	//------------------------------------------------------------------------------


	// Wraps a number between an upper and lower value
	// Params:
	//	num - the number that will be wrapped
	//	low - the lower limit
	//	hi  - the upper limit
	// Returns
	//	The number wrapped between the lower and upper limit
	int Wrap(int num, int low, int hi) {
		int range = hi - low;
		num = ((num - low) % range);

		if (num < 0) {
			num += hi;
		}

		return low + num;
	}

	float Wrap(float num, float low, float hi) {
		float range = hi - low;
		num = fmod((num - low), range);

		if (num < 0) {
			num += hi;
		}

		return low + num;
	}

	double Wrap(double num, double low, double hi) {
		double range = hi - low;
		num = fmod((num - low), range);

		if (num < 0) {
			num += hi;
		}

		return low + num;
	}

}