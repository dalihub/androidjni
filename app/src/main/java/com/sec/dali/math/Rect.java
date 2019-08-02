package com.sec.dali.math;

public class Rect {
    /**
     * @brief Constructor.
     * @SINCE_1_0.0
     */
    public Rect() {
        x = 0.0f;
        y = 0.0f;
        width = 0.0f;
        height = 0.0f;
    }

    /**
     * @brief Constructor.
     *
     * @SINCE_1_0.0
     * @param[in] x      X coordinate (or left)
     * @param[in] y      Y coordinate (or right)
     * @param[in] width  Width (or bottom)
     * @param[in] height Height (or top)
     */
    public Rect(float x, float y, float width, float height) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    /**
     * @brief Copy constructor.
     *
     * @SINCE_1_0.0
     * @param[in] rhs The original object
     */
    public Rect(Rect rect)
    {
        this.x = rect.x;
        this.y = rect.y;
        this.width = rect.width;
        this.height = rect.height;
    }

    /**
     * @brief Determines whether or not this Rectangle is empty.
     *
     * @SINCE_1_0.0
     * @return True if width or height are zero
     */
    public final boolean isEmpty() { return width  == 0 || height == 0; }

    /**
     * @brief Gets the left of the rectangle.
     *
     * @SINCE_1_0.0
     * @return The left edge of the rectangle
     */
    public final float left() { return x; }
    /**
     * @brief Gets the right of the rectangle.
     *
     * @SINCE_1_0.0
     * @return The right edge of the rectangle
     */
    public final float right() { return x + width; }

    /**
     * @brief Gets the top of the rectangle.
     *
     * @SINCE_1_0.0
     * @return The top of the rectangle
     */
    public final float top() { return y; }

    /**
     * @brief Gets the bottom of the rectangle.
     *
     * @SINCE_1_0.0
     * @return The bottom of the rectangle
     */
    public final float bottom() { return y + height; }

    /**
     * @brief Gets the area of the rectangle.
     *
     * @SINCE_1_0.0
     * @return The area of the rectangle
     */
    public final float area() { return width * height; }

    /**
     * @brief Determines whether or not this rectangle and the specified rectangle intersect.
     *
     * @SINCE_1_0.0
     * @param[in] other The other rectangle to test against this rectangle
     * @return True if the rectangles intersect
     */
    public final boolean intersects(final Rect other)
    {
        return (other.x + other.width) > x && other.x < (x + width) && (other.y + other.height) > y && other.y < (y + height);
    }

    /**
     * @brief Determines whether or not this Rectangle contains the specified rectangle.
     *
     * @SINCE_1_0.0
     * @param[in] other The other rectangle to test against this rectangle
     * @return True if the specified rectangle is contained
     */
    public final boolean contains(final Rect other)
    {
        return other.x >= x && (other.x + other.width) <= (x + width) && other.y >= y && (other.y + other.height) <= (y + height);
    }

    private float x;
    private float y;
    private float width;
    private float height;
};
