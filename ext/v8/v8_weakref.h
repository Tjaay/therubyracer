#ifndef _RR_V8_WEAKREF_
#define _RR_V8_WEAKREF_ 

#include <v8.h>
#include "ruby.h"

struct v8_weakref  {
  v8_weakref(VALUE object);
  VALUE get();
  void set(VALUE object);
  void retain();
  void release();

  VALUE object_id;
  v8::Persistent<v8::External> external;
};

void  v8_weakref_finalize(v8::Persistent<v8::Value> value, void* weakref);
VALUE v8_weakref_nil(VALUE nil, VALUE exception);
VALUE v8_weakref_id2ref(VALUE id);

#endif
