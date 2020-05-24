/**
 * @file Quat.h
 * @brief Class for data-holding quaternion expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include <MatrixExp.h>
#include <Vector.h>

/**
 * Class Declaration
 */
class Quat : public Vector<4>
{
public:

	// Constructors
	Quat();
	Quat(float w_, float x_, float y_, float z_);
	Quat(const MatrixExp<3, 1>& axis, float angle);
	Quat(const MatrixExp<4, 1>& vec);

	// Methods
	Quat& operator=(const MatrixExp<4, 1>& vec);
	float& w();
	float& x();
	float& y();
	float& z();
};

/**
 * Function Declarations
 */
Quat operator*(const MatrixExp<4, 1>& lhs, const MatrixExp<4, 1>& rhs);
Vector<3> operator*(const MatrixExp<4, 1>& quat, const MatrixExp<3, 1>& vec);
