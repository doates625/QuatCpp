/**
 * @file QuatExp.h
 * @brief Superclass for quaternion expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include <LinearCpp.h>

/**
 * Class Declaration
 */
class QuatExp : public VectorExp<4>
{
public:
	virtual float get_w() const;
	virtual float get_x() const;
	virtual float get_y() const;
	virtual float get_z() const;
	float get(uint8_t) const;
protected:
	QuatExp();
};
