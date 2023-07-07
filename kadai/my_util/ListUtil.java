package my_util;
import java.util.*;

public class ListUtil {
    public static List<Integer> makeIntList(int start, int end){
        List<Integer> list = new ArrayList<Integer>();
        for(int i=start; i<=end; i++){
            list.add(i);
        }
        return list;
    }

    public static List<Integer> makeIntList(int n){
        List<Integer> list = new ArrayList<Integer>();
        for(int i=1; i<=n; i++){
            list.add(i);
        }
        return list;
    }

    public static List<Integer> reverse(List<Integer> list){
        List<Integer> newlist = new ArrayList<Integer>();
        for(int temp: list){
            newlist.add(0,temp);
        }
        return newlist;
    }

    public static int max(List<Integer> list){
        int max = list.get(0);
        for(int temp: list){
            if (temp > max) max = temp;
        }
        return max;
    }

    public static int sum(List<Integer> list){
        int sum = 0;
        for(int temp: list){
            sum += temp;
        }
        return sum;
    }
}
