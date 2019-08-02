package com.sec.dali.actors;

public class ResizePolicy {
    /**
     * @brief Enumeration for ResizePolicy types.
     * @SINCE_1_0.0
     */
    enum Type {
        FIXED (0),                 ///< Size is fixed as set by SetSize @SINCE_1_0.0
        USE_NATURAL_SIZE(1),      ///< Size is to use the actor's natural size @SINCE_1_0.0 @see Actor::GetNaturalSize()
        FILL_TO_PARENT(2),        ///< Size is to fill up to the actor's parent's bounds. Aspect ratio is not maintained. @SINCE_1_0.0
        SIZE_RELATIVE_TO_PARENT(3),        ///< The actors size will be ( ParentSize * SizeRelativeToParentFactor ). @SINCE_1_0.0
        SIZE_FIXED_OFFSET_FROM_PARENT(4),  ///< The actors size will be ( ParentSize + SizeRelativeToParentFactor ). @SINCE_1_0.0
        FIT_TO_CHILDREN(5),       ///< Size will adjust to wrap around all children @SINCE_1_0.0
        DIMENSION_DEPENDENCY(6),  ///< One dimension is dependent on the other @SINCE_1_0.0
        USE_ASSIGNED_SIZE(7);      ///< The size will be assigned to the actor @SINCE_1_0.0

        Type(int value) { this.value = value; }
        public int value;
    };

    final static Type DEFAULT = Type.USE_NATURAL_SIZE; ///< Default resize policy
}
