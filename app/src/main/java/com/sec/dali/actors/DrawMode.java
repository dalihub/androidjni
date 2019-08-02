package com.sec.dali.actors;

public class DrawMode {
    /**
     * @brief Enumeration for the instance of how the actor and it's children will be drawn.
     *
     * @SINCE_1_0.0
     */
    enum Type
    {
        NORMAL (0), ///< @brief binary 00. The default draw-mode @SINCE_1_0.0
        OVERLAY_2D (1);  ///< @brief binary 01. Draw the actor and its children as an overlay @SINCE_1_0.0

        Type(int value) { this.value = value; }
        public int value;
    };
}
