package com.sec.dali.math;

public class Vector4 {
    /**
     * @brief Constructor.
     * @SINCE_1_0.0
     */
    public Vector4() {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }

    /**
     * @brief Conversion constructor from four floats.
     *
     * @SINCE_1_0.0
     * @param[in] x x (or r/s) component
     * @param[in] y y (or g/t) component
     * @param[in] z z (or b/p) component
     * @param[in] w w (or a/q) component
     */
    public Vector4(float x, float y, float z, float w) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.w = w;
    }

    /**
     * @brief Conversion constructor from an array of four floats.
     *
     * @SINCE_1_0.0
     * @param[in] array Array of either xyzw/rgba/stpq
     */
    public Vector4(final float[] array) {
        this.x = array[0];
        this.y = array[1];
        this.z = array[2];
        this.w = array[3];
    }

    /**
     * @brief Conversion constructor from Vector2.
     *
     * @SINCE_1_0.0
     * @param[in] vec2 Vector2 to copy from, z and w are initialized to 0
     */
    public Vector4(final Vector2 vec2) {
        this.x = vec2.x;
        this.y = vec2.y;
        this.z = 0.0f;
        this.w = 0.0f;
    }

    /**
     * @brief Conversion constructor from Vector3.
     *
     * @SINCE_1_0.0
     * @param[in] vec3 Vector3 to copy from, w is initialized to 0
     */
    public Vector4(final Vector3 vec3) {
        this.x = vec3.x;
        this.y = vec3.y;
        this.z = vec3.z;
        this.w = 0.0f;
    }

    /**
     * @brief Constructor.
     * @SINCE_1_0.0
     * @param[in] vec4 Vector4 to create this vector from
     */
    public Vector4(final Vector4 vec4) {
        this.x = vec4.x;
        this.y = vec4.y;
        this.z = vec4.z;
        this.w = vec4.w;
    }

    public static final Vector4 ONE = new Vector4(1.0f,1.0f,1.0f,1.0f);               ///< (1.0f,1.0f,1.0f,1.0f)
    public static final Vector4 XAXIS = new Vector4(1.0f,0.0f,0.0f,0.0f);             ///< Vector representing the X axis
    public static final Vector4 YAXIS = new Vector4(0.0f,1.0f,0.0f,0.0f);             ///< Vector representing the Y axis
    public static final Vector4 ZAXIS = new Vector4(0.0f,0.0f,1.0f,0.0f);             ///< Vector representing the Z axis
    public static final Vector4 ZERO = new Vector4(0.0f,0.0f,0.0f,0.0f);              ///< (0.0f, 0.0f, 0.0f)

    public final boolean equals(final Vector4 rhs) { return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w; }
    public final Vector4 add(final Vector4 rhs) { return new Vector4(x + rhs.x, y + rhs.y, z += rhs.z, w += rhs.w); }
    public final Vector4 substract(final Vector4 rhs) { return new Vector4(x - rhs.x, y - rhs.y, z -= rhs.z, w -= rhs.w); }
    public final Vector4 multiply(final Vector4 rhs) { return new Vector4(x * rhs.x, y *rhs.y, z *= rhs.z, w *= rhs.w); }
    public final Vector4 divide(final Vector4 rhs) { return new Vector4(x / rhs.x, y / rhs.y, z /= rhs.z, w /= rhs.w); }

    /**
     * @brief Returns the dot product of this vector (4d) and another vector (3d).
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
     * @brief Returns the dot product of this vector and another vector.
     *
     * The dot product is the length of one vector in the direction of another vector.
     * This is great for lighting, threshold testing the angle between two unit vectors,
     * calculating the distance between two points in a particular direction.
     * @SINCE_1_0.0
     * @param[in] other The other vector
     * @return The dot product
     */
    public final float dot(final Vector4 other) {
        return x * other.x + y * other.y + z * other.z;
    }

    /**
     * @brief Returns the 4d dot product of this vector and another vector.
     *
     * @SINCE_1_0.0
     * @param[in] other The other vector
     * @return The dot product
     */
    public final float dot4(final Vector4 other) {
        return x * other.x + y * other.y + z * other.z + w * other.w;
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
    public final Vector4 cross(final Vector4 other) {
        return new Vector4( (y * other.z) - (z * other.y),
                (z * other.x) - (x * other.z),
                (x * other.y) - (y * other.x),0.0f);
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
    public final float lengthSquared() { return (x*x) + (y*y) + (z*z); };

    /**
     * @brief Sets the vector to be unit length, whilst maintaining its direction.
     *
     * @SINCE_1_0.0
     */
    public final void normalize() {
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
    public final void clamp( final Vector4 min, final Vector4 max ){
        x = Math.max(min.x, Math.min(max.x, x));
        y = Math.max(min.y, Math.min(max.y, y));
        z = Math.max(min.z, Math.min(max.z, z));
        w = Math.max(min.w, Math.min(max.w, w));
    }

    public float x;
    public float y;
    public float z;
    public float w;
}
