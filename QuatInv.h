/**
 * @file QuatInv.h
 * @brief Class for quaternion inverse expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "MatrixExp.h"

/**
 * Class Declaration
 */
class QuatInv : public MatrixExp<4, 1>
{
public:
	QuatInv(const MatrixExp<4, 1>& quat);
	float get(uint8_t i, uint8_t j) const override;
protected:
	const MatrixExp<4, 1>* quat;
	float norm_inv_2;
};

/**
 * Function Declaration
 */
QuatInv inv(const MatrixExp<4, 1>& quat);
