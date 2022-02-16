package com.example.remember;

import android.util.Log;

@SuppressWarnings("unused")
public class ThreadCallbacks {

  public void onThreadStart() {
    Log.d("MYAPP", "OnThreadStart");
  }

  public void onIterationComplete(int iteration) {
    Log.d("MYAPP", "onIterationComplete " + iteration);
  }

  public void onThreadEnd() {
    Log.d("MYAPP", "onThreadEnd");
  }
}
