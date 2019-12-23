/**
 * @brief QuatExp.cpp
 * @author Dan Oates (WPI Class of 2020)
 */
#include "QuatExp.h"

/**
 * @brief Default constructor protected to preclude use
 */
QuatExp::QuatExp()
{
	return;
}

/**
 * @brief Gets w component
 */
float QuatExp::get_w() const
{
	return 0.0f;
}

/**
 * @brief Gets x component
 */
float QuatExp::get_x() const
{
	return 0.0f;
}

/**
 * @brief Gets y component
 */
float QuatExp::get_y() const
{
	return 0.0f;
}

/**
 * @brief Gets z component
 */
float QuatExp::get_z() const
{
	return 0.0f;
}

/**
 * @brief Returns element of expression
 * @param i Vector index [0...n-1]
 * 
 * Mapping: [0, 1, 2, 3] -> [w, x, y, z]
 */
float QuatExp::get(uint8_t i) const
{
	switch (i)
	{
		case 0: return get_w();
		case 1: return get_x();
		case 2: return get_y();
		case 3: return get_z();
	}
	return 0.0f;
}
