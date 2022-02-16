//
// Created by hecto on 1/4/2022.
//

#include <thread>
#include <chrono>
#include "thread_logic.hpp"
#include "ThreadExecutionCallbacks.hpp"

void threadBody(ThreadExecutionCallbacks& threadCallbacks) {
  for (int i = 0; i < 5; i++) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    threadCallbacks.onThreadStarted();
  }
}
