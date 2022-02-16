package com.example.remember;

import android.util.Log;

@SuppressWarnings("unused")
public class ThreadCallbacks {

  public void onThreadStart() {
    Log.d("MYAPP", "OnThreadStart");
  }

  public void onIterationComplete(int iteration) {
    Log.d("MYAPP", "OnThreadIteration " + iteration);
  }

  public void onThreadFinished() {
    Log.d("MYAPP", "OnThreadFinished");
  }
}
