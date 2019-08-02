package com.sec.dali.actors;

public class VerticalAlignment {
    /**
     * @brief Enumeration for VerticalAlignment types.
     * @SINCE_1_0.0
     */
    enum Type
    {
        TOP(0),          ///< Align vertically top @SINCE_1_0.0
        CENTER(1),       ///< Align vertically center @SINCE_1_0.0
        BOTTOM(2);        ///< Align vertically bottom @SINCE_1_0.0

        Type(int value) { this.value = value; }
        public int value;
    };
}
