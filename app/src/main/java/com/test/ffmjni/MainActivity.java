package com.test.ffmjni;

import android.app.Activity;
import android.os.Bundle;
import android.os.Process;
import android.text.method.ScrollingMovementMethod;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;


public class MainActivity extends Activity implements View.OnClickListener {
    private TextView textView;
    private Button avcodec_configuration;
    private Button avformatinfo;
    private Button avcodecinfo;
    private Button avfilterinfo;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = (TextView) this.findViewById(R.id.text);
        textView.setMovementMethod(ScrollingMovementMethod.getInstance());

        avcodec_configuration = (Button) this.findViewById(R.id.avcodec_configuration);
        avformatinfo = (Button) this.findViewById(R.id.avformatinfo);
        avcodecinfo = (Button) this.findViewById(R.id.avcodecinfo);
        avfilterinfo = (Button) this.findViewById(R.id.avfilterinfo);

        avcodec_configuration.setOnClickListener(this);
        avformatinfo.setOnClickListener(this);
        avcodecinfo.setOnClickListener(this);
        avfilterinfo.setOnClickListener(this);
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
    public native String avformatinfo();
    public native String avcodecinfo();
    public native String avfilterinfo();


    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.avcodec_configuration:
                textView.setText(getStringFromNative());
                break;

            case R.id.avformatinfo:
                textView.setText(avformatinfo());
                break;

            case R.id.avcodecinfo:
                textView.setText(avcodecinfo());
                break;

            case R.id.avfilterinfo:
                textView.setText(avfilterinfo());
                break;
        }
    }
}
