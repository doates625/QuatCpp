/**
 * @file QuatConj.cpp
 * @author Dan Oates (WPI Class of 2020)
 */
#include "QuatConj.h"

/**
 * @brief Constructor
 * @param quat Quaternion to conjugate
 */
QuatConj::QuatConj(const QuatExp& quat)
{
	this->quat = &quat;
}

/**
 * @brief Gets w component
 */
float QuatConj::get_w() const
{
	return quat->get_w();
}

/**
 * @brief Gets x component
 */
float QuatConj::get_x() const
{
	return -quat->get_x();
}

/**
 * @brief Gets y component
 */
float QuatConj::get_y() const
{
	return -quat->get_y();
}

/**
 * @brief Gets z component
 */
float QuatConj::get_z() const
{
    return -quat->get_z();
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
QuatConj conj(const QuatExp& quat)
{
	return QuatConj(quat);
}
