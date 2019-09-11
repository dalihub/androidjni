package com.sec.daliview;

import android.content.Context;
import android.content.res.AssetManager;
import android.util.AttributeSet;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

public class DaliView extends SurfaceView implements SurfaceHolder.Callback {

    public DaliView(Context context) {
        this(context, null);
    }

    public DaliView(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public DaliView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        getHolder().addCallback(this);
        nativeOnConfigure(context.getAssets(), context.getFilesDir().getAbsolutePath());

        System.loadLibrary("dalidemo");
        nativeHandle = nativeOnCreate();
    }

    public DaliView(Context context, AttributeSet attrs, int defStyleAttr, int defStyleRes) {
        super(context, attrs, defStyleAttr, defStyleRes);
        getHolder().addCallback(this);
        nativeOnConfigure(context.getAssets(), context.getFilesDir().getAbsolutePath());

        System.loadLibrary("dalidemo");
        nativeHandle = nativeOnCreate();
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {

    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        nativeSetSurface(nativeHandle, holder.getSurface());
        nativeOnResume(nativeHandle);
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        nativeOnPause(nativeHandle);
        nativeSetSurface(nativeHandle, null);
    }

    protected void finalize() throws Throwable {
        try {
            nativeOnFinalize(nativeHandle);
        } finally {
            super.finalize();
        }
    }

    public long nativeHandle = 0;
    public native void nativeOnConfigure(AssetManager assetManager, String dataPath);
    public native long nativeOnCreate();
    public native void nativeOnResume(long handle);
    public native void nativeOnPause(long handle);
    public native void nativeSetSurface(long handle, Surface surface);
    public native void nativeOnFinalize(long handle);
    static {
        System.loadLibrary("daliview");
    }
}

