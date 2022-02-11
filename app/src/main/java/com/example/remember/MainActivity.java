package com.example.remember;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
import com.example.remember.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

  // Used to load the 'remember' library on application startup.
  static {
    System.loadLibrary("remember");
  }

  private ActivityMainBinding binding;

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);

    binding = ActivityMainBinding.inflate(getLayoutInflater());
    setContentView(binding.getRoot());

    // Example of a call to a native method
    TextView tv = binding.sampleText;
    tv.setText(stringFromJNI());
  }

  /**
   * A native method that is implemented by the 'remember' native library, which is packaged with
   * this application.
   */
  public native String stringFromJNI();
}