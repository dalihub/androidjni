package com.sec.dali.actors;

public class ClippingMode {
    /**
     * @brief Enumeration for ClippingMode types.
     * @SINCE_1_2_5
     */
    enum Type
    {
        DISABLED(0),                     ///< This Actor will not clip its children. @SINCE_1_2_5
        CLIP_CHILDREN(1),                ///< This Actor will clip itself and all children to within the pixel areas of this actors renderers. @SINCE_1_2_5
        CLIP_TO_BOUNDING_BOX(2);          ///< This Actor will clip itself and all children to within a screen-aligned rectangle encompassing its boundaries. @SINCE_1_2.61

        Type(int value) { this.value = value; }
        public int value;
    };
}
