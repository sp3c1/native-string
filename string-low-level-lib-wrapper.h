#ifndef STRINGLOWLEVELLIBWRAPPER_H
#define STRINGLOWLEVELLIBWRAPPER_H

#include <nan.h>
#include <regex>

class stringLowLevelLibWrapper : public  Nan::ObjectWrap {
  public:
    static void Init(v8::Local<v8::Object> exports);

  private:
    explicit stringLowLevelLibWrapper();
    ~stringLowLevelLibWrapper();

    static void New(const Nan::FunctionCallbackInfo<v8::Value>& args);    
    static Nan::Persistent<v8::Function> constructor;
    std::string  value_;
    

    static void set(const Nan::FunctionCallbackInfo<v8::Value>& args);
    static void append(const Nan::FunctionCallbackInfo<v8::Value>& args);
    static void regex(const Nan::FunctionCallbackInfo<v8::Value>& args);
    static void get(const Nan::FunctionCallbackInfo<v8::Value>& args);
    static void remove(const Nan::FunctionCallbackInfo<v8::Value>& args);
    static void chunk(const Nan::FunctionCallbackInfo<v8::Value>& args);
    static void length(const Nan::FunctionCallbackInfo<v8::Value>& args);
    static void clear(const Nan::FunctionCallbackInfo<v8::Value>& args);
};

#endif
