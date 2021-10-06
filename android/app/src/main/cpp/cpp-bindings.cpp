#include <jni.h>
#include <jsi/jsi.h>
#include <memory>
#include <fbjni/fbjni.h>
#include <ReactCommon/CallInvokerHolder.h>
#include <react/jni/JavaScriptExecutorHolder.h>
#include <android/log.h>
#include "../../../../../cpp/module.h"


using namespace facebook;


struct SampleJSIModulePackage : jni::JavaClass<SampleJSIModulePackage> {
public:
    __unused static constexpr auto kJavaDescriptor = "Lcom/newfeatures/samplemodule/SampleJSIModulePackage;";

    static void registerNatives() {
        javaClassStatic()->registerNatives({
                                                   makeNativeMethod("installJSIBindings",
                                                                    SampleJSIModulePackage::installNative),
                                           });
    }

private:
    static void installNative(jni::alias_ref<jni::JClass>,
                              jlong jsiRuntimePointer) {
        auto runtime = reinterpret_cast<jsi::Runtime*>(jsiRuntimePointer);
        osdnk::samplemodule::installNative(*runtime);
    }
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *) {
    return facebook::jni::initialize(vm, [] {
        SampleJSIModulePackage::registerNatives();
    });
}
