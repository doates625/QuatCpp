/**
 * @file QuatMul.h
 * @brief Class for quaternion multiplication expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "QuatExp.h"
#include "Quat.h"

/**
 * Class Declaration
 */
class QuatMul : public QuatExp
{
public:
	QuatMul(const QuatExp& lhs, const QuatExp& rhs);
	float get_w() const override;
	float get_x() const override;
	float get_y() const override;
	float get_z() const override;
protected:
	const QuatExp* lhs_ptr;
	const QuatExp* rhs_ptr;
	Quat lhs_copy;
	Quat rhs_copy;
};

/**
 * Operator Declaration
 */
QuatMul operator*(const QuatExp& lhs, const QuatExp& rhs);
