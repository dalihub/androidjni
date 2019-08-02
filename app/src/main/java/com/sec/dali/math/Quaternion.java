package com.sec.dali.math;

// TODO
public class Quaternion {
    /**
     * @brief Default Constructor.
     * @SINCE_1_0.0
     */
    public Quaternion() {};

    /**
     * @brief Constructs from a quaternion represented by floats.
     *
     * @SINCE_1_0.0
     * @param[in] cosThetaBy2
     * @param[in] iBySineTheta
     * @param[in] jBySineTheta
     * @param[in] kBySineTheta
     */
    public Quaternion( float cosThetaBy2, float iBySineTheta, float jBySineTheta, float kBySineTheta )
    {
        vector = new Vector4( iBySineTheta, jBySineTheta, kBySineTheta, cosThetaBy2 );
    }

    /**
     * @brief Constructs from a quaternion represented by a vector.
     *
     * @SINCE_1_0.0
     * @param[in] vector x,y,z fields represent i,j,k coefficients, w represents cos(theta/2)
     */
    public Quaternion( Vector4 vector )
    {
        this.vector = new Vector4( vector );
    }

    /**
     * @brief Constructor from an axis and angle.
     *
     * @SINCE_1_0.0
     * @param[in] angle The angle around the axis
     * @param[in] axis  The vector of the axis
     */
    public Quaternion( Radian angle, Vector3 axis )
    {
        Vector3 tmpAxis = axis;
        tmpAxis.normalize();
        float halfAngle = angle.radian * 0.5f;
        float sinThetaByTwo = (float)Math.sin(halfAngle);
        float cosThetaByTwo = (float)Math.cos(halfAngle);
        vector.x = tmpAxis.x * sinThetaByTwo;
        vector.y = tmpAxis.y * sinThetaByTwo;
        vector.z = tmpAxis.z * sinThetaByTwo;
        vector.w = cosThetaByTwo;
    }

    public Vector4 vector;   ///< w component is s ( = cos(theta/2.0) )
}
