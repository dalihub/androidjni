package com.sec.dali.actors;

/**
 * @brief Enumeration for Actor color mode.
 *
 * @SINCE_1_0.0
 */
public enum ColorMode
{
    USE_OWN_COLOR (0),                 ///< Actor will use its own color @SINCE_1_0.0
    USE_PARENT_COLOR (1),              ///< Actor will use its parent color @SINCE_1_0.0
    USE_OWN_MULTIPLY_PARENT_COLOR (2), ///< Actor will blend its color with its parents color. @SINCE_1_0.0
    USE_OWN_MULTIPLY_PARENT_ALPHA (3); ///< Actor will blend its alpha with its parents alpha. This means when parent fades in or out child does as well. This is the default. @SINCE_1_0.0

    ColorMode(int value) { this.value = value; }
    public int value;
};

