package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import java.io.IOException;
import java.util.ArrayList;


public class MainActivity extends AppCompatActivity {

    ArrayList<String> a = new ArrayList<String>();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    }

    OpenCsv my = new OpenCsv();

    public void onClick(View view){
        try {
            a = my.readDataFromCsv("/data/data/com.example.myapplication/files/data.csv", a);
            String text = "열 개수: " + a.get(0);
            TextView txt = (TextView) findViewById(R.id.textView2);
            txt.setText(text);
            System.out.println(a.get(0));
            System.out.println(a.get(7));
        }catch(IOException e){
            System.out.println("err");
        }
    }

    public void onClick1(View view) {
        try {
            int j = 0;
            EditText getCol = (EditText)findViewById(R.id.editNum1);
            String value1 = getCol.getText().toString();

            EditText getRow = (EditText)findViewById(R.id.editNum2);
            int value2 = -1;
            try {value2 = Integer.parseInt(getRow.getText().toString());
            }catch(Exception ee){}

            String cols[] = value1.split(",");
            TextView txt = (TextView) findViewById(R.id.textView3);
            if(value2 != -1) {
                txt.setText(cols[value2]);
            }else if(value2 == -1){
                txt.setText("no");
            }
            /*
            for(int i=1; i<a.size(); i++){
                if( i % Integer.parseInt(a.get(0)) == Integer.parseInt(cols[j])){
                    if( j==cols.length-1 ) j=0;
                    else j++;

                }

            }*/
        }catch(Exception e){
            System.out.println("err");
        }
    }
}