/**
 * @file QuatInv.h
 * @brief Class for quaternion inverse expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "QuatCpp.h"

/**
 * Class Declaration
 */
class QuatInv : public QuatExp
{
public:
	QuatInv(const QuatExp& quat);
	float get_w() const override;
	float get_x() const override;
	float get_y() const override;
	float get_z() const override;
protected:
	const QuatExp* quat;
	float norm_inv_2;
};

/**
 * Function Declaration
 */
QuatInv inv(const QuatExp& quat);
