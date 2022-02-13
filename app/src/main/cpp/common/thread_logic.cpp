//
// Created by hecto on 1/4/2022.
//

#include "thread_logic.hpp"
#include "ThreadExecutionCallbacks.hpp"
#include <thread>
#include <chrono>

void threadBody(ThreadExecutionCallbacks& bridge) {
  for (int i = 0; i < 5; i++) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    bridge.onThreadStarted();
  }
}
