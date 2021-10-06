package com.newfeatures.samplemodule;

import androidx.annotation.Keep;

import com.facebook.proguard.annotations.DoNotStrip;
import com.facebook.react.bridge.JSIModulePackage;
import com.facebook.react.bridge.JSIModuleSpec;
import com.facebook.react.bridge.JavaScriptContextHolder;
import com.facebook.react.bridge.ReactApplicationContext;

import java.util.Arrays;
import java.util.List;

@Keep
public class SampleJSIModulePackage implements JSIModulePackage {
    static {
        System.loadLibrary("newfeatures");
    }

    @Keep
    @DoNotStrip
    private native void installJSIBindings(long jsiRuntimePointer);

    @Override
    public List<JSIModuleSpec> getJSIModules(ReactApplicationContext reactApplicationContext, JavaScriptContextHolder jsContext) {
        installJSIBindings(jsContext.get()); // to make this access as quickly as possible TODO research if this can be done in some other place
        return Arrays.asList();
    }
}
