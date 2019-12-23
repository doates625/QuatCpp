/**
 * @file Quat.h
 * @brief Class for data-holding quaternion expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "QuatExp.h"

/**
 * Class Declaration
 */
class Quat : public QuatExp
{
public:

	// Data members
	float w;
	float x;
	float y;
	float z;

	// Constructors
	Quat();
	Quat(float w, float x, float y, float z);
	Quat(const VectorExp<3>& axis, float angle);
	Quat(const VectorExp<4>& vec);

	// Methods
	Quat& operator=(const VectorExp<4>& vec);
	float get_w() const override;
	float get_x() const override;
	float get_y() const override;
	float get_z() const override;
	bool evaluated() const override;
};
