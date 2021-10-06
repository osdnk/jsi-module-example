#import "module.h"

namespace osdnk {
    namespace samplemodule {
        void installNative(jsi::Runtime& runtime) {
            auto addOne = jsi::Function::createFromHostFunction(runtime,
                                                                 jsi::PropNameID::forAscii(runtime, "addOne"),
                                                                 1,  // run
                                                                 [](jsi::Runtime& runtime, const jsi::Value& thisValue, const jsi::Value* arguments, size_t count) -> jsi::Value {

                auto value = arguments[0].asNumber() + 1;
                return jsi::Value(value);
            });
            runtime.global().setProperty(runtime, "__sampleModule__addOne", std::move(addOne));

        }
    }
}
