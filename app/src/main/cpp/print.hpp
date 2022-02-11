//
// Created by hecto on 1/4/2022.
//

#ifndef NATIVEAPPLAST_PRINT_HPP
#define NATIVEAPPLAST_PRINT_HPP

#include <android/log.h>

#define print(...) (__android_log_print(ANDROID_LOG_INFO, "MYAPP", __VA_ARGS__))

#endif //NATIVEAPPLAST_PRINT_HPP
