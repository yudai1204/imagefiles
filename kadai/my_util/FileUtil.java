package my_util;

import java.io.*;

public class FileUtil {
    public static String readTextFile(String filename) {
        String result = new String();
        try {
            FileInputStream fis = new FileInputStream(filename);
            InputStreamReader isr = new InputStreamReader(fis, "SJIS");
            BufferedReader br = new BufferedReader(isr);
            String line;
            while ((line = br.readLine()) != null) {
                result += (line + "\n");
            }
            br.close();
        } catch (IOException e) {
            return null;
        }
        return result;
    }

    public static String readTextFile(String filename, String enc) {
        String result = new String();
        try {
            FileInputStream fis = new FileInputStream(filename);
            InputStreamReader isr = new InputStreamReader(fis, enc);
            BufferedReader br = new BufferedReader(isr);
            String line;
            while ((line = br.readLine()) != null) {
                result += (line + "\n");
            }
            br.close();
        } catch (IOException e) {
            return null;
        }
        return result;
    }

    public static void writeTextFile(String data, String filename){
        try {
        PrintWriter pw = new PrintWriter(
                new BufferedWriter(
                        new OutputStreamWriter(
                                new FileOutputStream(filename), "UTF-8")));
        pw.println(data);
        pw.close();
        }catch(IOException e){
            throw new RuntimeException(e);
        }
    }
    public static void writeTextFile(String data, String filename, String enc) {
        try{
        PrintWriter pw = new PrintWriter(
                new BufferedWriter(
                        new OutputStreamWriter(
                                new FileOutputStream(filename), enc)));
        pw.println(data);
        pw.close();
        }catch(IOException e){
            throw new RuntimeException(e);
        }
    }
}