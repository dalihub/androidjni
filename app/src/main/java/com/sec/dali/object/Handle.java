package com.sec.dali.object;

import java.util.ArrayList;

public class Handle {
    static Handle New() { return new Handle(); };

    public Handle() { this.nativeHandle = nativeNewHandle(); }

    public Handle( long nativeHandle ) {
        this.nativeHandle = nativeHandle;
    }

    public int getPropertyIndex(String name) {
        return nativeGetPropertyIndex(nativeHandle, name);
    }

    public void removePropertyNotifications() {
        nativeRemovePropertyNotifications(nativeHandle);
    }

    public int getPropertyCount() {
        return nativeGetPropertyCount(nativeHandle);
    }

    public int registerProperty(String name, Property.Value propertyValue, Property.AccessMode accessMode) {
        return nativeRegisterProperty(nativeHandle, name, propertyValue, accessMode);
    }

    public boolean isPropertyWritable(int index) {
        return nativeIsPropertyWritable(nativeHandle, index);
    }

    public Property.Value getCurrentProperty(int index) {
        return nativeGetCurrentProperty(nativeHandle, index);
    }

    public void removeConstraints(int tag) {
        nativeRemoveConstraints(nativeHandle, tag);
    }

    public void setProperty(int index, Property.Value propertyValue) {
        nativeSetProperty(nativeHandle, index, propertyValue);
    }

    public String getPropertyName(int index) {
        return nativeGetPropertyName(nativeHandle, index);
    }

    public boolean isPropertyAnimatable(int index) {
        return nativeIsPropertyAnimatable(nativeHandle, index);
    }

    public Property.Type getPropertyType(int index) {
        return nativeGetPropertyType(nativeHandle, index);
    }

    public Property.Value getProperty(int index) {
        return nativeGetProperty(nativeHandle, index);
    }

    public boolean isPropertyAConstraintInput(int index) {
        return nativeIsPropertyAConstraintInput(nativeHandle, index);
    }

    protected native long nativeNewHandle();
    protected native int nativeGetPropertyIndex(long nativeHandle, String name);
    protected native void nativeRemovePropertyNotifications(long nativeHandle);
    protected native int nativeGetPropertyCount(long nativeHandle);
    protected native int nativeRegisterProperty(long nativeHandle, String name, Property.Value propertyValue, Property.AccessMode accessMode);
    protected native boolean nativeIsPropertyWritable(long nativeHandle, int index);
    protected native Property.Value nativeGetCurrentProperty(long nativeHandle, int index);
    protected native void nativeRemoveConstraints(long nativeHandle, int tag);
    protected native void nativeSetProperty(long nativeHandle, int index, Property.Value propertyValue);
    protected native String nativeGetPropertyName(long nativeHandle, int index);
    protected native boolean nativeIsPropertyAnimatable(long nativeHandle, int index);
    protected native Property.Type nativeGetPropertyType(long nativeHandle, int index);
    protected native Property.Value nativeGetProperty(long nativeHandle, int index);
    protected native boolean nativeIsPropertyAConstraintInput(long nativeHandle, int index);
    protected long nativeHandle;
};
