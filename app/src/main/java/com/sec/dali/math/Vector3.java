package com.sec.dali.math;

public class Vector3 {
    /**
     * @brief Constructor.
     * @SINCE_1_0.0
     */
    public Vector3() {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }

    /**
     * @brief Constructor.
     * @SINCE_1_0.0
     * @param[in] x (or width) component
     * @param[in] y (or height) component
     * @param[in] z (or depth) component
     */
    public Vector3(float x, float y, float z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    /**
     * @brief Conversion constructor from an array of three floats.
     * @SINCE_1_0.0
     * @param[in] array Array of xyz
     */
    public Vector3(final float[] array) {
        this.x = array[0];
        this.y = array[1];
        this.z = array[2];
    }

    /**
     * @brief Constructor.
     * @SINCE_1_0.0
     * @param[in] vec2 Vector2 to create this vector from
     */
    public Vector3(final Vector2 vec2) {
        this.x = vec2.x;
        this.y = vec2.y;
        this.z = 0.0f;
    }

    /**
     * @brief Constructor.
     * @SINCE_1_0.0
     * @param[in] vec3 Vector3 to create this vector from
     */
    public Vector3(final Vector3 vec3) {
        this.x = vec3.x;
        this.y = vec3.y;
        this.z = vec3.z;
    }

    /**
     * @brief Constructor.
     * @SINCE_1_0.0
     * @param[in] vec4 Vector4 to create this vector from
     */
    public Vector3(final Vector4 vec4) {
        this.x = vec4.x;
        this.y = vec4.y;
        this.z = vec4.z;
    }

    public static final Vector3 ONE = new Vector3(1.0f,1.0f,1.0f);               ///< (1.0f,1.0f,1.0f)
    public static final Vector3 XAXIS = new Vector3(1.0f,0.0f,0.0f);             ///< Vector representing the X axis
    public static final Vector3 YAXIS = new Vector3(0.0f,1.0f,0.0f);             ///< Vector representing the Y axis
    public static final Vector3 ZAXIS = new Vector3(0.0f,0.0f,1.0f);             ///< Vector representing the Z axis
    public static final Vector3 NEGATIVE_XAXIS = new Vector3(-1.0f,0.0f,0.0f);    ///< Vector representing the negative X axis
    public static final Vector3 NEGATIVE_YAXIS = new Vector3(0.0f,-1.0f,0.0f);    ///< Vector representing the negative Y axis
    public static final Vector3 NEGATIVE_ZAXIS = new Vector3(0.0f,0.0f,-1.0f);    ///< Vector representing the negative Z axis
    public static final Vector3 ZERO= new Vector3(0.0f,0.0f,0.0f);              ///< (0.0f, 0.0f, 0.0f)

    public final boolean equals(final Vector3 rhs) { return x == rhs.x && y == rhs.y && z == rhs.z; }
    public final Vector3 add(final Vector3 rhs) { return new Vector3(x + rhs.x, y + rhs.y, z += rhs.z); }
    public final Vector3 substract(final Vector3 rhs) { return new Vector3(x - rhs.x, y - rhs.y, z -= rhs.z); }
    public final Vector3 multiply(final Vector3 rhs) { return new Vector3(x * rhs.x, y *rhs.y, z *= rhs.z); }
    public final Vector3 divide(final Vector3 rhs) { return new Vector3(x / rhs.x, y / rhs.y, z /= rhs.z); }

    /**
     * @brief Returns the dot product of this vector and another vector.
     *
     * The dot product is the length of one vector in the direction of another vector.
     * This is great for lighting, threshold testing the angle between two unit vectors,
     * calculating the distance between two points in a particular direction.
     * @SINCE_1_0.0
     * @param[in] other The other vector
     * @return The dot product
     */
    public final float dot(final Vector3 other) {
        return x * other.x + y * other.y + z * other.z;
    }

    /**
     * @brief Returns the cross produce of this vector and another vector.
     *
     * The cross produce of two vectors is a vector which is perpendicular to the plane of the
     * two vectors. This is great for calculating normals and making matrices orthogonal.
     *
     * @SINCE_1_0.0
     * @param[in] other The other vector
     * @return The cross product
     */
    public final Vector3 cross(final Vector3 other) {
        return new Vector3( (y * other.z) - (z * other.y),
                (z * other.x) - (x * other.z),
                (x * other.y) - (y * other.x));
    }

    /**
     * @brief Returns the length of the vector.
     *
     * @SINCE_1_0.0
     * @return The length of the vector
     */
    public final float length() { return (float)Math.sqrt(lengthSquared()); };

    /**
     * @brief Returns the length of the vector squared.
     *
     * This is more efficient than Length() for threshold
     * testing as it avoids the use of a square root.
     * @SINCE_1_0.0
     * @return The length of the vector squared
     */
    float lengthSquared() { return (x*x) + (y*y) + (z*z); };

    /**
     * @brief Sets the vector to be unit length, whilst maintaining its direction.
     *
     * @SINCE_1_0.0
     */
    void normalize() {
        float length = length();
        if ( !(length == 0.0f) )
        {
            final float inverseLength = 1.0f / length;
            x *= inverseLength;
            y *= inverseLength;
            z *= inverseLength;
        }
    };

    /**
     * @brief Clamps the vector between minimum and maximum vectors.
     *
     * @SINCE_1_0.0
     * @param[in] min The minimum vector
     * @param[in] max The maximum vector
     */
    void clamp( final Vector3 min, final Vector3 max ){
        x = Math.max(min.x, Math.min(max.x, x));
        y = Math.max(min.y, Math.min(max.y, y));
        z = Math.max(min.z, Math.min(max.z, z));
    }

    public float x;
    public float y;
    public float z;
}