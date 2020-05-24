/**
 * @file QuatConj.h
 * @brief Class for quaternion conjugation expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "MatrixExp.h"

/**
 * Class Declaration
 */
class QuatConj : public MatrixExp<4, 1>
{
public:
	QuatConj(const MatrixExp<4, 1>& quat);
	float get(uint8_t i, uint8_t j) const override;
	bool evaluated() const override;
protected:
	const MatrixExp<4, 1>* quat;
};

/**
 * Function Declaration
 */
QuatConj conj(const MatrixExp<4, 1>& quat);
