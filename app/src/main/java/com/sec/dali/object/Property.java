package com.sec.dali.object;

import com.sec.dali.math.Vector2;
import com.sec.dali.math.Vector3;
import com.sec.dali.math.Vector4;

import java.util.ArrayList;
import java.util.Arrays;

public class Property {
    public static int INVALID_INDEX; ///< -1 is not a valid property index
    public static int INVALID_KEY;   ///< -1 is not a valid property key
    public static int INVALID_COMPONENT_INDEX; ///< -1 is not a valid property index

    /**
     * @brief Enumeration for the property types supported.
     */
    public enum Type
    {
        NONE (0),            ///< No type @SINCE_1_0.0

        BOOLEAN (1),         ///< A boolean type @SINCE_1_0.0
        FLOAT (2),           ///< A float type @SINCE_1_0.0
        INTEGER (3),         ///< An integer type @SINCE_1_0.0
        VECTOR2 (4),         ///< a vector array of size=2 with float precision @SINCE_1_0.0
        VECTOR3 (5),         ///< a vector array of size=3 with float precision @SINCE_1_0.0
        VECTOR4 (6),         ///< a vector array of size=4 with float precision @SINCE_1_0.0
        MATRIX3 (7),         ///< a 3x3 matrix @SINCE_1_0.0
        MATRIX (8),          ///< a 4x4 matrix @SINCE_1_0.0
        RECTANGLE (9),       ///< an integer array of size=4 @SINCE_1_0.0
        ROTATION (10),       ///< either a quaternion or an axis angle rotation @SINCE_1_0.0
        STRING (11),         ///< A string type @SINCE_1_0.0
        ARRAY (12),          ///< an array of Property::Value @SINCE_1_0.0
        MAP (13),            ///< a string key to Property:value mapping @SINCE_1_0.0
        EXTENTS (14);        ///< a collection of 4 x uint16_t @SINCE_1_2.62

        Type(int value) { this.value = value; }
        public int value;
    };

    /**
     * @brief Enumeration for the access mode for custom properties.
     * @SINCE_1_0.0
     */
    public enum AccessMode
    {
        READ_ONLY (0),          ///< if the property is read-only @SINCE_1_0.0
        READ_WRITE (1),         ///< If the property is read/writeable @SINCE_1_0.0
        ANIMATABLE (2),         ///< If the property can be animated or constrained @SINCE_1_0.0
        ACCESS_MODE_COUNT (3);   ///< The number of access modes @SINCE_1_0.0

        AccessMode(int value) {
            this.value = value;
        }
        public int value;
    };

    public abstract class Value {
        public Property.Type getType() { return Type.NONE; }
        public final boolean getBoolean() { return ((BooleanValue)this).value; }
        public final int getInteger() { return ((IntegerValue)this).value; }
        public final float getFloat() { return ((FloatValue)this).value; }
        public final float[] getFloatArray() {
            switch (getType()) {
                case BOOLEAN:
                    return new float[] { (((BooleanValue)this).value) ? 1.0f : 0.0f };
                case INTEGER:
                    return new float[] { ((IntegerValue)this).value };
                case FLOAT:
                    return new float[] { ((FloatValue)this).value };
                case VECTOR2:
                    return new float[] { ((Vector2Value)this).value.x,
                            ((Vector2Value)this).value.y};
                case VECTOR3:
                    return new float[] { ((Vector3Value)this).value.x,
                            ((Vector3Value)this).value.y,
                            ((Vector3Value)this).value.z};
                case VECTOR4:
                    return new float[] { ((Vector4Value)this).value.x,
                            ((Vector4Value)this).value.y,
                            ((Vector4Value)this).value.z, ((Vector4Value)this).value.w};
                default:
                    return new float[] {};
            }
        }
    }

    public final class NoneValue extends Value {
        public final Property.Type getType() { return Type.NONE; }
        public NoneValue() {}
    }

    public final class BooleanValue extends Value {
        public final Property.Type getType() { return Type.BOOLEAN; }
        public BooleanValue(boolean value) { this.value = value; }
        boolean value;
    }

    public final class FloatValue extends Value {
        public final Property.Type getType() { return Type.FLOAT; }
        public FloatValue(float value) { this.value = value; }
        public float value;
    }

    public final class IntegerValue extends Value {
        public final Property.Type getType() { return Type.INTEGER; }
        public IntegerValue(int value) { this.value = value; }
        public int value;
    }

    public final class Vector2Value extends Value {
        public final Property.Type getType() { return Type.VECTOR2; }
        public Vector2Value(float x, float y) { value.x = x; value.y = y; }
        public Vector2 value;
    }

    public final class Vector3Value extends Value {
        public final Property.Type getType() { return Type.VECTOR3; }
        public Vector3Value(float x, float y, float z) { value.x = x; value.y = y; value.z = z; }
        public Vector3 value;
    }

    public final class Vector4Value extends Value {
        public final Property.Type getType() { return Type.VECTOR4; }
        public Vector4Value(float x, float y, float z, float w) { value.x = x; value.y = y; value.z = z; value.w = w; }
        public Vector4 value;
    }

    public final class Array {
        public ArrayList<Value> list;
    }

    enum KeyType {
        INDEX(0), ///< The key is a Property::Index
        STRING(1); ///< The key is a string

        KeyType(int type) {
            this.type = type;
        }

        public int type;
    }

    public final class Key {
        public KeyType type;

        int indexKey; ///< The index key.
        String stringKey; ///< The string key.

        /**
         * @brief Constructor
         * @SINCE_1_2.7
         * @param[in] key The string key
         */
        Key(String key) {
            stringKey = key;
            type = KeyType.STRING;
        }

        /**
         * @brief Constructor
         * @SINCE_1_2.7
         *
         * @param[in] key The index key
         */
        Key( int key ) {
            indexKey = key;
            type = KeyType.INDEX;
        }
    }

    /**
     * @brief Creates a Property instance.
     *
     * @SINCE_1_0.0
     * @param[in] object A valid handle to the target object
     * @param[in] propertyIndex The index of a property
     */
    public Property( Handle object, int propertyIndex ) {
        this.object = object;
        this.propertyIndex = propertyIndex;
        this.componentIndex = INVALID_COMPONENT_INDEX;
    }

    /**
     * @brief Creates a Property instance.
     *
     * @SINCE_1_0.0
     * @param[in] object A valid handle to the target object.
     * @param[in] propertyIndex The index of a property.
     * @param[in] componentIndex Index to a sub component of a property, for use with Vector2, Vector3 and Vector4. -1 for main property (default is -1)
     */
    public Property( Handle object, int propertyIndex, int componentIndex ) {
        this.object = object;
        this.propertyIndex = propertyIndex;
        this.componentIndex = componentIndex;
    }

    /**
     * @brief Creates a Property instance.
     *
     * @SINCE_1_0.0
     * @param[in] object A valid handle to the target object
     * @param[in] propertyName The property name
     * @note This performs a property index query and is therefore slower than
     * constructing a Property directly with the index.
     */
    public Property( Handle object, String propertyName ) {
        this.object = object;
        this.propertyIndex = object.getPropertyIndex(propertyName);
        this.componentIndex = INVALID_COMPONENT_INDEX;
    }

    /**
     * @brief Creates a Property instance.
     *
     * @SINCE_1_0.0
     * @param[in] object A valid handle to the target object
     * @param[in] propertyName The property name
     * @param[in] componentIndex Index to a sub component of a property, for use with Vector2, Vector3 and Vector4. -1 for main property (default is -1)
     * @note This performs a property index query and is therefore slower than
     * constructing a Property directly with the index.
     */
    public Property( Handle object, String propertyName, int componentIndex ) {
        this.object = object;
        this.propertyIndex = object.getPropertyIndex(propertyName);
        this.componentIndex = componentIndex;
    }

    public Handle object; ///< A valid handle to the target object.

    public int propertyIndex; ///< The index of a property provided by object.

    public int componentIndex; ///< Index of a property sub component, for use with Vector2, Vector3 and Vector4, -1 if using main property
}
