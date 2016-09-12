package com.test.ffmjni;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;


public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView textView = (TextView) this.findViewById(R.id.text);
        textView.setText(getStringFromNative());
    }
    static{
        System.loadLibrary("swresample-2");
        System.loadLibrary("avutil-55");
        System.loadLibrary("avformat-57");
        System.loadLibrary("avcodec-57");
        System.loadLibrary("swscale-4");
        System.loadLibrary("ovsplayer");
    }

    public native String getStringFromNative();
}
