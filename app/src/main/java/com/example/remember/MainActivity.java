package com.example.remember;

import android.util.Log;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import com.example.remember.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

  // Used to load the 'remember' library on application startup.
  static {
    System.loadLibrary("remember");
  }

  @SuppressWarnings("unused")
  private void onThreadStart() {
    Log.i("MYAPP", "Starting thread");
  }

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);

    setContentView(ActivityMainBinding.inflate(getLayoutInflater()).getRoot());

    jniMethod();
  }

  /**
   * A native method that is implemented by the 'remember' native library, which is packaged with
   * this application.
   */
  public native void jniMethod();
}