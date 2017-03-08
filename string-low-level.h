#ifndef STRINGLOWLEVEL_H
#define STRINGLOWLEVEL_H

#include <node.h>
#include "string-low-level-lib-wrapper.h"

using v8::Local;
using v8::Object;

void InitAll(Local<Object> exports) {
  stringLowLevelLibWrapper::Init(exports);
}

#endif
