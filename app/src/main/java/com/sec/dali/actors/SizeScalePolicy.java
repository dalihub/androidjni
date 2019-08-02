package com.sec.dali.actors;

public class SizeScalePolicy {
    /**
     * @brief Enumeration for SizeScalePolicy types.
     * @SINCE_1_0.0
     */
    enum Type
    {
        USE_SIZE_SET(0),                ///< Use the size that was set @SINCE_1_0.0
        FIT_WITH_ASPECT_RATIO(1),       ///< Fit within the size set maintaining natural size aspect ratio @SINCE_1_0.0
        FILL_WITH_ASPECT_RATIO(2);       ///< Fill up the size set maintaining natural size aspect ratio. May exceed size bounds in one dimension. @SINCE_1_0.0

        Type(int value) { this.value = value; }
        public int value;
    };
}
