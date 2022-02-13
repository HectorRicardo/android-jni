//
// Created by hecto on 1/4/2022.
//

#ifndef MYAPP_PLATFORM_BRIDGE_H
#define MYAPP_PLATFORM_BRIDGE_H

class PlatformBridge {
 public:
  virtual void callThreadStartedMethod() const = 0;
};

#endif // MYAPP_PLATFORM_BRIDGE_H
