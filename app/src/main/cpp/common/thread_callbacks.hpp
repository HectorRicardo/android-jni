//
// Created by hecto on 1/4/2022.
//

#ifndef MYAPP_THREAD_CALLBACKS_HPP
#define MYAPP_THREAD_CALLBACKS_HPP

class ThreadCallbacks {
 public:
  virtual void onThreadStarted() const = 0;
  virtual void onIterationComplete(int iteration) const = 0;
  virtual void onThreadFinished() const = 0;
};

#endif // MYAPP_THREAD_CALLBACKS_HPP
