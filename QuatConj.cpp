/**
 * @file QuatConj.cpp
 * @author Dan Oates (WPI Class of 2020)
 */
#include "QuatConj.h"

/**
 * @brief Constructor
 * @param quat Quaternion to conjugate
 */
QuatConj::QuatConj(const MatrixExp<4, 1>& quat)
{
	this->quat = &quat;
}

/**
 * @brief Returns element of expression
 * @param i Row index [0...3]
 * @param j Col index [0]
 */
float QuatConj::get(uint8_t i, uint8_t j) const
{
	if (i == 0)
	{
		return +quat->get(i, 0);
	}
	else
	{
		return -quat->get(i, 0);
	}
}

/**
 * @brief Returns true if reference quaternion is evaluated
 * 
 * Simple negation is not enough to justify copying quaternion
 * under repeated get() call conditions.
 */
bool QuatConj::evaluated() const
{
	return quat->evaluated();
}

/**
 * @brief Returns conjugate of quat
 */
QuatConj conj(const MatrixExp<4, 1>& quat)
{
	return QuatConj(quat);
}
