package com.sec.dali.actors;

public class HorizontalAlignment {
    /**
     * @brief Enumeration for HorizontalAlignment types.
     * @SINCE_1_0.0
     */
    enum Type
    {
        LEFT(0),         ///< Align horizontally left @SINCE_1_0.0
        CENTER(1),       ///< Align horizontally center @SINCE_1_0.0
        RIGHT(2);        ///< Align horizontally right @SINCE_1_0.0

        Type(int value) { this.value = value; }
        public int value;
    };
}
