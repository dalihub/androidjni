package com.sec.dali.math;

public class Vector2 {
    /**
     * @brief Constructor.
     * @SINCE_1_0.0
     */
    public Vector2() { x = 0.0f; y = 0.0f; }

    /**
     * @brief Constructor.
     *
     * @SINCE_1_0.0
     * @param[in] x x or width component
     * @param[in] y y or height component
     */
    public Vector2(float x, float y) { this.x = x; this.y = y; }

    /**
     * @brief Conversion constructor from an array of two floats.
     *
     * @SINCE_1_0.0
     * @param[in] array Array of xy
     */
    public Vector2(final float[] array) { this.x = array[0]; this.y = array[1]; }

    /**
     * @brief Constructor.
     *
     * @SINCE_1_0.0
     * @param[in] vec3 Vector3 to create this vector from
     */
    public Vector2(final Vector2 vec2) { this.x = vec2.x; this.y = vec2.y; }

    /**
     * @brief Constructor.
     *
     * @SINCE_1_0.0
     * @param[in] vec3 Vector3 to create this vector from
     */
    public Vector2(final Vector3 vec3) { this.x = vec3.x; this.y = vec3.y; }

    /**
     * @brief Constructor.
     *
     * @SINCE_1_0.0
     * @param[in] vec4 Vector4 to create this vector from
     */
    public Vector2(final Vector4 vec4) { this.x = vec4.x; this.y = vec4.y; }

    public static Vector2 ONE = new Vector2(1.0f, 1.0f);               ///< (1.0f,1.0f)
    public static Vector2 XAXIS = new Vector2(1.0f, 0.0f);             ///< Vector representing the X axis
    public static Vector2 YAXIS = new Vector2(0.0f, 1.0f);             ///< Vector representing the Y axis
    public static Vector2 NEGATIVE_XAXIS = new Vector2(-1.0f, 0.0f);;    ///< Vector representing the negative X axis
    public static Vector2 NEGATIVE_YAXIS = new Vector2(0.0f, -1.0f);;    ///< Vector representing the negative Y axis
    public static Vector2 ZERO = new Vector2(0.0f, 0.0f);;              ///< (0.0f, 0.0f)

    public final boolean equals(final Vector2 rhs) { return x == rhs.x && y == rhs.y; }
    public final Vector2 add(final Vector2 rhs) { return new Vector2(x + rhs.x, y + rhs.y); }
    public final Vector2 substract(final Vector2 rhs) { return new Vector2(x - rhs.x, y - rhs.y); }
    public final Vector2 multiply(final Vector2 rhs) { return new Vector2(x * rhs.x, y *rhs.y); }
    public final Vector2 divide(final Vector2 rhs) { return new Vector2(x / rhs.x, y / rhs.y); }

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
    float lengthSquared() { return (x*x) + (y*y); };

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
        }
    };

    /**
     * @brief Clamps the vector between minimum and maximum vectors.
     *
     * @SINCE_1_0.0
     * @param[in] min The minimum vector
     * @param[in] max The maximum vector
     */
    void clamp( final Vector2 min, final Vector2 max ){
        x = Math.max(min.x, Math.min(max.x, x));
        y = Math.max(min.y, Math.min(max.y, y));
    }

    public float x;
    public float y;
}
