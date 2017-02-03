#include <node_jsvmapi.h>

static double value_ = 1;

void GetValue(napi_env env, napi_callback_info info) {
  napi_status status;

  int argc;
  status = napi_get_cb_args_length(env, info, &argc);
  if (status != napi_ok) return;

  if (argc != 0) {
    napi_throw_type_error(env, "Wrong number of arguments");
    return;
  }

  napi_value number;
  status = napi_create_number(env, value_, &number);
  if (status != napi_ok) return;

  status = napi_set_return_value(env, info, number);
  if (status != napi_ok) return;
}

void SetValue(napi_env env, napi_callback_info info) {
  napi_status status;

  int argc;
  status = napi_get_cb_args_length(env, info, &argc);
  if (status != napi_ok) return;

  if (argc != 1) {
    napi_throw_type_error(env, "Wrong number of arguments");
    return;
  }

  napi_value arg;
  status = napi_get_cb_args(env, info, &arg, 1);
  if (status != napi_ok) return;

  status = napi_get_value_double(env, arg, &value_);
  if (status != napi_ok) return;
}

void Echo(napi_env env, napi_callback_info info) {
  napi_status status;

  int argc;
  status = napi_get_cb_args_length(env, info, &argc);
  if (status != napi_ok) return;

  if (argc != 1) {
    napi_throw_type_error(env, "Wrong number of arguments");
    return;
  }

  napi_value arg;
  status = napi_get_cb_args(env, info, &arg, 1);
  if (status != napi_ok) return;

  status = napi_set_return_value(env, info, arg);
  if (status != napi_ok) return;
}

void Init(napi_env env, napi_value exports, napi_value module) {
  napi_status status;

  napi_value number;
  status = napi_create_number(env, value_, &number);
  if (status != napi_ok) return;

  napi_property_descriptor properties[] = {
    { "echo", Echo },
    { "accessorValue", nullptr, GetValue, SetValue },
    { "readwriteValue", nullptr, nullptr, nullptr, number },
    { "readonlyValue", nullptr, nullptr, nullptr, number, napi_read_only },
    { "hiddenValue", nullptr, nullptr, nullptr, number,
      static_cast<napi_property_attributes>(napi_read_only | napi_dont_enum) },
  };

  for (int i = 0; i < sizeof(properties) / sizeof(*properties); i++) {
    status = napi_define_property(env, exports, &properties[i]);
    if (status != napi_ok) return;
  }
}

NODE_MODULE_ABI(addon, Init)
