/**
 * @file QuatInv.cpp
 * @author Dan Oates (WPI Class of 2020)
 */
#include "QuatInv.h"

/**
 * @brief Constructor
 * @param quat Quaternion to invert
 */
QuatInv::QuatInv(const QuatExp& quat)
{
	this->quat = &quat;
	float norm_ = norm(quat);
	this->norm_inv_2 = 1.0f / (norm_ * norm_);
}

/**
 * @brief Gets w component
 */
float QuatInv::get_w() const
{
	return norm_inv_2 * quat->get_w();
}

/**
 * @brief Gets x component
 */
float QuatInv::get_x() const
{
	return -norm_inv_2 * quat->get_x();
}

/**
 * @brief Gets y component
 */
float QuatInv::get_y() const
{
	return -norm_inv_2 * quat->get_y();
}

/**
 * @brief Gets z component
 */
float QuatInv::get_z() const
{
    return -norm_inv_2 * quat->get_z();
}

/**
 * @brief Returns inverse of quat
 */
QuatInv inv(const QuatExp& quat)
{
	return QuatInv(quat);
}
