package com.example.remember;

import android.os.Bundle;
import android.util.Log;
import androidx.appcompat.app.AppCompatActivity;
import com.example.remember.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

  // Used to load the 'remember' library on application startup.
  static {
    System.loadLibrary("remember");
  }

  @SuppressWarnings("unused")
  private void methodToBeCalledFromJNI() {
    Log.i("MYAPP", "We did it!");
  }

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(ActivityMainBinding.inflate(getLayoutInflater()).getRoot());

    startThread();
  }

  /**
   * A native method that is implemented by the 'remember' native library, which is packaged with
   * this application.
   */
  public native void startThread();
}
