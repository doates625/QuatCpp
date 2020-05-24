/**
 * @file QuatInv.cpp
 * @author Dan Oates (WPI Class of 2020)
 */
#include "QuatInv.h"

/**
 * @brief Constructor
 * @param quat Quaternion to invert
 */
QuatInv::QuatInv(const MatrixExp<4, 1>& quat)
{
	this->quat = &quat;
	float norm_ = norm(quat);
	this->norm_inv_2 = 1.0f / (norm_ * norm_);
}

/**
 * @brief Returns element of expression
 * @param i Row index [0...3]
 * @param j Col index [0]
 */
float QuatInv::get(uint8_t i, uint8_t j) const
{
	if (i == 0)
	{
		return +norm_inv_2 * quat->get(i, 0);
	}
	else
	{
		return -norm_inv_2 * quat->get(i, 0);
	}
}

/**
 * @brief Returns inverse of quat
 */
QuatInv inv(const MatrixExp<4, 1>& quat)
{
	return QuatInv(quat);
}
