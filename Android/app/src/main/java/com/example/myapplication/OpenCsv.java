package com.example.myapplication;

import android.util.Log;

import com.opencsv.CSVReader;
import com.opencsv.CSVWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class OpenCsv {

    public static void writeDataToCsv(String filePath) throws IOException {
        CSVWriter writer = new CSVWriter(new FileWriter(filePath));
        String[] entries = "EW#City#State".split("#");  // 1
        writer.writeNext(entries);

        String[] entries1 = {"W", "Youngstown", "OH"};  // 2
        writer.writeNext(entries1);

        String[] entries2 = {"W", "Williamson", "WV"};
        writer.writeNext(entries2);

        writer.close();
    }

    public static ArrayList readDataFromCsv(String filePath, ArrayList a) throws IOException {
        CSVReader reader = new CSVReader(new FileReader(filePath)); // 1
        String[] nextLine;
        while ((nextLine = reader.readNext()) != null) {   // 2
            if( a.size() == 0 ) {
                a.add(Integer.toString(nextLine.length));
            }
            for (int i = 0; i < nextLine.length; i++) {
                a.add(nextLine[i]);
                //System.out.println(i + " " + nextLine[i]);
                //Log.i("22",nextLine[i]);
            }
        }
        return a;
    }
}