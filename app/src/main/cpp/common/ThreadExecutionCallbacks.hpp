//
// Created by hecto on 1/4/2022.
//

#ifndef MYAPP_THREAD_EXECUTION_CALLBACKS_H
#define MYAPP_THREAD_EXECUTION_CALLBACKS_H

class ThreadExecutionCallbacks {
 public:
  virtual void onThreadStarted() const = 0;
};

#endif // MYAPP_THREAD_EXECUTION_CALLBACKS_H
