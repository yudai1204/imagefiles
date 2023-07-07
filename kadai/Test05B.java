import java.util.*;
import my_util.*;

class Test05B {
    public static void main(String[] args) {
        List<Integer> list1 = ListUtil.makeIntList(5); // [1,2,3,4,5]
        System.out.println(list1);
        System.out.println(ListUtil.reverse(list1)); // [5,4,3,2,1]
        System.out.println("sum(" + list1 + ")=" + ListUtil.sum(list1)); // 15
        List<Integer> list2 = ListUtil.makeIntList(3, 7); // [3,4,5,6,7]
        System.out.println("max(" + list2 + ")=" + ListUtil.max(list2)); // 7
    }
}
