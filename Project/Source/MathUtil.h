#pragma once


//------------------------------------------------------------------------------
//Includes
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------



namespace MathUtil {

	//------------------------------------------------------------------------------
	//variables
	//------------------------------------------------------------------------------

	const double DegToRad = M_PI / 180;
	const double RadToDeg = 180 / M_PI;

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
	int Wrap(int num, int low, int hi);
	float Wrap(float num, float low, float hi);
	double Wrap(double num, double low, double hi);

}