package com.sec.dali.actors;

import com.sec.dali.math.Matrix;
import com.sec.dali.math.Rect;
import com.sec.dali.math.Vector2;
import com.sec.dali.math.Vector3;
import com.sec.dali.math.Vector4;
import com.sec.dali.math.Quaternion;
import com.sec.dali.object.Handle;

public class Actor extends Handle {
    public Actor( long nativeHandle ) {
        this.nativeHandle = nativeHandle;
    }

    public void raise() {
        nativeRaise(nativeHandle);
    }

    public void getPadding(Rect paddingOut) {
        nativeGetPadding(nativeHandle, paddingOut);
    }

    public boolean isVisible() {
        return nativeIsVisible(nativeHandle);
    }

    public void raiseAbove(Actor target) {
        nativeRaiseAbove(nativeHandle, target);
    }

    public Quaternion getCurrentWorldOrientation() {
        return nativeGetCurrentWorldOrientation(nativeHandle);
    }

    public void setVisible(boolean visible) {
        nativeSetVisible(nativeHandle, visible);
    }

    public void setSizeModeFactor(Vector3 factor) {
        nativeSetSizeModeFactor(nativeHandle, factor);
    }

    public boolean isScaleInherited() {
        return nativeIsScaleInherited(nativeHandle);
    }

    public Vector3 getTargetSize() {
        return nativeGetTargetSize(nativeHandle);
    }

    public Vector4 getCurrentColor() {
        return nativeGetCurrentColor(nativeHandle);
    }

    public void setScale(Vector3 scale) {
        nativeSetScale(nativeHandle, scale);
    }

    public float getRelayoutSize(Dimension.Type dimension) {
        return nativeGetRelayoutSize(nativeHandle, dimension);
    }

    public Vector3 getCurrentScale() {
        return nativeGetCurrentScale(nativeHandle);
    }

    public boolean isLayer() {
        return nativeIsLayer(nativeHandle);
    }

    public void unparent() {
        nativeUnparent(nativeHandle);
    }

    public void setName(String name) {
        nativeSetName(nativeHandle, name);
    }

    public float getWidthForHeight(float height) {
        return nativeGetWidthForHeight(nativeHandle, height);
    }

    public void setColorMode(ColorMode colorMode) {
        nativeSetColorMode(nativeHandle, colorMode);
    }

    public void setSensitive(boolean sensitive) {
        nativeSetSensitive(nativeHandle, sensitive);
    }

    public void setX(float x) {
        nativeSetX(nativeHandle, x);
    }

    public void setY(float y) {
        nativeSetY(nativeHandle, y);
    }

    public void setZ(float z) {
        nativeSetZ(nativeHandle, z);
    }

    public Matrix getCurrentWorldMatrix() {
        return nativeGetCurrentWorldMatrix(nativeHandle);
    }

    public Actor getParent() {
        return nativeGetParent(nativeHandle);
    }

    public Vector3 getCurrentPosition() {
        return nativeGetCurrentPosition(nativeHandle);
    }

    public Actor findChildByName(String actorName) {
        return nativeFindChildByName(nativeHandle, actorName);
    }

    public int getChildCount() {
        return nativeGetChildCount(nativeHandle);
    }

    public Vector2 getMinimumSize() {
        return nativeGetMinimumSize(nativeHandle);
    }

    public void setParentOrigin(Vector3 origin) {
        nativeSetParentOrigin(nativeHandle, origin);
    }

    public int getRendererCount() {
        return nativeGetRendererCount(nativeHandle);
    }

    public Actor getChildAt(int index) {
        return nativeGetChildAt(nativeHandle, index);
    }

    public ResizePolicy.Type getResizePolicy(Dimension.Type dimension) {
        return nativeGetResizePolicy(nativeHandle, dimension);
    }

    public int getHierarchyDepth() {
        return nativeGetHierarchyDepth(nativeHandle);
    }

    public boolean getLeaveRequired() {
        return nativeGetLeaveRequired(nativeHandle);
    }

    public DrawMode.Type getDrawMode() {
        return nativeGetDrawMode(nativeHandle);
    }

    public void remove(Actor child) {
        nativeRemove(nativeHandle, child);
    }

    public boolean isOrientationInherited() {
        return nativeIsOrientationInherited(nativeHandle);
    }

    public void setLeaveRequired(boolean required) {
        nativeSetLeaveRequired(nativeHandle, required);
    }

    public void setAnchorPoint(Vector3 anchorPoint) {
        nativeSetAnchorPoint(nativeHandle, anchorPoint);
    }

    public Vector3 getCurrentSize() {
        return nativeGetCurrentSize(nativeHandle);
    }

    public void setMinimumSize(Vector2 size) {
        nativeSetMinimumSize(nativeHandle, size);
    }

    public void setResizePolicy(ResizePolicy.Type policy, Dimension.Type dimension) {
        nativeSetResizePolicy(nativeHandle, policy, dimension);
    }

    public void setMaximumSize(Vector2 size) {
        nativeSetMaximumSize(nativeHandle, size);
    }

    public boolean onStage() {
        return nativeOnStage(nativeHandle);
    }

    public void setOrientation(Quaternion orientation) {
        nativeSetOrientation(nativeHandle, orientation);
    }

    public boolean isKeyboardFocusable() {
        return nativeIsKeyboardFocusable(nativeHandle);
    }

    public ColorMode getColorMode() {
        return nativeGetColorMode(nativeHandle);
    }

    public Actor findChildById(int id) {
        return nativeFindChildById(nativeHandle, id);
    }

    public Vector3 getCurrentAnchorPoint() {
        return nativeGetCurrentAnchorPoint(nativeHandle);
    }

    public Vector3 getCurrentWorldScale() {
        return nativeGetCurrentWorldScale(nativeHandle);
    }

    public void add(Actor child) {
        nativeAdd(nativeHandle, child);
    }

    public void setColor(Vector4 color) {
        nativeSetColor(nativeHandle, color);
    }

    public void setKeyboardFocusable(boolean focusable) {
        nativeSetKeyboardFocusable(nativeHandle, focusable);
    }

    public void setInheritScale(boolean inherit) {
        nativeSetInheritScale(nativeHandle, inherit);
    }

    public SizeScalePolicy.Type getSizeScalePolicy() {
        return nativeGetSizeScalePolicy(nativeHandle);
    }

    public Quaternion getCurrentOrientation() {
        return nativeGetCurrentOrientation(nativeHandle);
    }

    public void setOpacity(float opacity) {
        nativeSetOpacity(nativeHandle, opacity);
    }

    public void lowerBelow(Actor target) {
        nativeLowerBelow(nativeHandle, target);
    }

    public void setPadding(Rect padding) {
        nativeSetPadding(nativeHandle, padding);
    }

    public Vector3 getSizeModeFactor() {
        return nativeGetSizeModeFactor(nativeHandle);
    }

    public boolean isRoot() {
        return nativeIsRoot(nativeHandle);
    }

    public void lowerToBottom() {
        nativeLowerToBottom(nativeHandle);
    }

    public void setInheritOrientation(boolean inherit) {
        nativeSetInheritOrientation(nativeHandle, inherit);
    }

    public void setSizeScalePolicy(SizeScalePolicy.Type policy) {
        nativeSetSizeScalePolicy(nativeHandle, policy);
    }

    public void setDrawMode(DrawMode.Type drawMode) {
        nativeSetDrawMode(nativeHandle, drawMode);
    }

    public void raiseToTop() {
        nativeRaiseToTop(nativeHandle);
    }

    public void scaleBy(Vector3 relativeScale) {
        nativeScaleBy(nativeHandle, relativeScale);
    }

    public Vector3 getNaturalSize() {
        return nativeGetNaturalSize(nativeHandle);
    }

    public void setSize(Vector3 size) {
        nativeSetSize(nativeHandle, size);
    }

    public boolean screenToLocal(float localX, float localY, float screenX, float screenY) {
        return nativeScreenToLocal(nativeHandle, localX, localY, screenX, screenY);
    }

    public void translateBy(Vector3 distance) {
        nativeTranslateBy(nativeHandle, distance);
    }

    public float getHeightForWidth(float width) {
        return nativeGetHeightForWidth(nativeHandle, width);
    }

    public float getCurrentOpacity() {
        return nativeGetCurrentOpacity(nativeHandle);
    }

    public void lower() {
        nativeLower(nativeHandle);
    }

    public Vector3 getCurrentWorldPosition() {
        return nativeGetCurrentWorldPosition(nativeHandle);
    }

    public boolean isSensitive() {
        return nativeIsSensitive(nativeHandle);
    }

    public int getId() {
        return nativeGetId(nativeHandle);
    }

    public void rotateBy(Quaternion relativeRotation) {
        nativeRotateBy(nativeHandle, relativeRotation);
    }

    public Vector2 getMaximumSize() {
        return nativeGetMaximumSize(nativeHandle);
    }

    public void removeRenderer(int index) {
        nativeRemoveRenderer(nativeHandle, index);
    }

    public void setPosition(Vector3 position) {
        nativeSetPosition(nativeHandle, position);
    }

    public Vector4 getCurrentWorldColor() {
        return nativeGetCurrentWorldColor(nativeHandle);
    }

    public Vector3 getCurrentParentOrigin() {
        return nativeGetCurrentParentOrigin(nativeHandle);
    }

    protected native void nativeRaise(long nativeHandle);
    protected native void nativeGetPadding(long nativeHandle, Rect paddingOut);
    protected native boolean nativeIsVisible(long nativeHandle);
    protected native void nativeRaiseAbove(long nativeHandle, Actor target);
    protected native Quaternion nativeGetCurrentWorldOrientation(long nativeHandle);
    protected native void nativeSetVisible(long nativeHandle, boolean visible);
    protected native void nativeSetSizeModeFactor(long nativeHandle, Vector3 factor);
    protected native boolean nativeIsScaleInherited(long nativeHandle);
    protected native Vector3 nativeGetTargetSize(long nativeHandle);
    protected native Vector4 nativeGetCurrentColor(long nativeHandle);
    protected native void nativeSetScale(long nativeHandle, Vector3 scale);
    protected native float nativeGetRelayoutSize(long nativeHandle, Dimension.Type dimension);
    protected native Vector3 nativeGetCurrentScale(long nativeHandle);
    protected native boolean nativeIsLayer(long nativeHandle);
    protected native void nativeUnparent(long nativeHandle);
    protected native void nativeSetName(long nativeHandle, String name);
    protected native float nativeGetWidthForHeight(long nativeHandle, float height);
    protected native void nativeSetColorMode(long nativeHandle, ColorMode colorMode);
    protected native void nativeSetSensitive(long nativeHandle, boolean sensitive);
    protected native void nativeSetX(long nativeHandle, float x);
    protected native void nativeSetY(long nativeHandle, float y);
    protected native void nativeSetZ(long nativeHandle, float z);
    protected native Matrix nativeGetCurrentWorldMatrix(long nativeHandle);
    protected native Actor nativeGetParent(long nativeHandle);
    protected native Vector3 nativeGetCurrentPosition(long nativeHandle);
    protected native Actor nativeFindChildByName(long nativeHandle, String actorName);
    protected native int nativeGetChildCount(long nativeHandle);
    protected native Vector2 nativeGetMinimumSize(long nativeHandle);
    protected native void nativeSetParentOrigin(long nativeHandle, Vector3 origin);
    protected native int nativeGetRendererCount(long nativeHandle);
    protected native Actor nativeGetChildAt(long nativeHandle, int index);
    protected native ResizePolicy.Type nativeGetResizePolicy(long nativeHandle, Dimension.Type dimension);
    protected native int nativeGetHierarchyDepth(long nativeHandle);
    protected native boolean nativeGetLeaveRequired(long nativeHandle);
    protected native DrawMode.Type nativeGetDrawMode(long nativeHandle);
    protected native void nativeRemove(long nativeHandle, Actor child);
    protected native boolean nativeIsOrientationInherited(long nativeHandle);
    protected native void nativeSetLeaveRequired(long nativeHandle, boolean required);
    protected native void nativeSetAnchorPoint(long nativeHandle, Vector3 anchorPoint);
    protected native Vector3 nativeGetCurrentSize(long nativeHandle);
    protected native void nativeSetMinimumSize(long nativeHandle, Vector2 size);
    protected native void nativeSetResizePolicy(long nativeHandle, ResizePolicy.Type policy, Dimension.Type dimension);
    protected native void nativeSetMaximumSize(long nativeHandle, Vector2 size);
    protected native boolean nativeOnStage(long nativeHandle);
    protected native void nativeSetOrientation(long nativeHandle, Quaternion orientation);
    protected native boolean nativeIsKeyboardFocusable(long nativeHandle);
    protected native ColorMode nativeGetColorMode(long nativeHandle);
    protected native Actor nativeFindChildById(long nativeHandle, int id);
    protected native Vector3 nativeGetCurrentAnchorPoint(long nativeHandle);
    protected native Vector3 nativeGetCurrentWorldScale(long nativeHandle);
    protected native void nativeAdd(long nativeHandle, Actor child);
    protected native void nativeSetColor(long nativeHandle, Vector4 color);
    protected native void nativeSetKeyboardFocusable(long nativeHandle, boolean focusable);
    protected native void nativeSetInheritScale(long nativeHandle, boolean inherit);
    protected native SizeScalePolicy.Type nativeGetSizeScalePolicy(long nativeHandle);
    protected native Quaternion nativeGetCurrentOrientation(long nativeHandle);
    protected native void nativeSetOpacity(long nativeHandle, float opacity);
    protected native void nativeLowerBelow(long nativeHandle, Actor target);
    protected native void nativeSetPadding(long nativeHandle, Rect padding);
    protected native Vector3 nativeGetSizeModeFactor(long nativeHandle);
    protected native boolean nativeIsRoot(long nativeHandle);
    protected native void nativeLowerToBottom(long nativeHandle);
    protected native void nativeSetInheritOrientation(long nativeHandle, boolean inherit);
    protected native void nativeSetSizeScalePolicy(long nativeHandle, SizeScalePolicy.Type policy);
    protected native void nativeSetDrawMode(long nativeHandle, DrawMode.Type drawMode);
    protected native void nativeRaiseToTop(long nativeHandle);
    protected native void nativeScaleBy(long nativeHandle, Vector3 relativeScale);
    protected native Vector3 nativeGetNaturalSize(long nativeHandle);
    protected native void nativeSetSize(long nativeHandle, Vector3 size);
    protected native boolean nativeScreenToLocal(long nativeHandle, float localX, float localY, float screenX, float screenY);
    protected native void nativeTranslateBy(long nativeHandle, Vector3 distance);
    protected native float nativeGetHeightForWidth(long nativeHandle, float width);
    protected native float nativeGetCurrentOpacity(long nativeHandle);
    protected native void nativeLower(long nativeHandle);
    protected native Vector3 nativeGetCurrentWorldPosition(long nativeHandle);
    protected native boolean nativeIsSensitive(long nativeHandle);
    protected native int nativeGetId(long nativeHandle);
    protected native void nativeRotateBy(long nativeHandle, Quaternion relativeRotation);
    protected native Vector2 nativeGetMaximumSize(long nativeHandle);
    protected native void nativeRemoveRenderer(long nativeHandle, int index);
    protected native void nativeSetPosition(long nativeHandle, Vector3 position);
    protected native Vector4 nativeGetCurrentWorldColor(long nativeHandle);
    protected native Vector3 nativeGetCurrentParentOrigin(long nativeHandle);
    protected long nativeHandle;
};
