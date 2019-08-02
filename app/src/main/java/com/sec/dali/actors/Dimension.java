package com.sec.dali.actors;

public class Dimension {
    /**
     * @brief Enumeration for Dimension types.
     * @SINCE_1_0.0
     */
    enum Type {
        WIDTH (1),          ///< Width dimension @SINCE_1_0.0
        HEIGHT (2),         ///< Height dimension @SINCE_1_0.0

        ALL_DIMENSIONS (3);  ///< Mask to cover all flags @SINCE_1_0.0

        Type(int value) { this.value = value; }
        public int value;
    };

    /**
     * @brief Enumeration for Dimension number.
     * @SINCE_1_0.0
     */
    enum Meta {
        DIMENSION_COUNT (2);  ///< Number of dimensions - update this if adding new dimension @SINCE_1_0.0

        Meta(int value) { this.value = value; }
        public int value;
    };
}
