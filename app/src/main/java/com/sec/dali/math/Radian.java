package com.sec.dali.math;


/**
* @brief An angle in radians.
*
* This reduces ambiguity when using methods which accept angles in degrees or radians.
* @SINCE_1_0.0
*/
public class Radian
{
    /**
     * @brief Default constructor, initializes to 0.
     * @SINCE_1_0.0
     */
    public Radian() { radian =  0.0f; }

    /**
     * @brief Creates an angle in radians.
     *
     * @SINCE_1_0.0
     * @param[in] value The initial value in radians
     */
    public Radian( float value ) { radian = value; }

    /**
     * @brief Creates an angle in radians from an angle in degrees.
     *
     * @SINCE_1_0.0
     * @param[in] degree The initial value in degrees
     */
    public Radian( float degree, boolean isDegree ) { radian = (float)(degree * Math.PI / 180); }

    // member data
    float radian; ///< The value in radians
}
