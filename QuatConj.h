/**
 * @file QuatConj.h
 * @brief Class for quaternion conjugation expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "QuatCpp.h"

/**
 * Class Declaration
 */
class QuatConj : public QuatExp
{
public:
	QuatConj(const QuatExp& quat);
	float get_w() const override;
	float get_x() const override;
	float get_y() const override;
	float get_z() const override;
	bool evaluated() const override;
protected:
	const QuatExp* quat;
};

/**
 * Function Declaration
 */
QuatConj conj(const QuatExp& quat);
