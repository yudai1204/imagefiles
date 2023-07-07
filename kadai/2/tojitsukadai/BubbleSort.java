public class BubbleSort {
    public static void main(String[] args) {
        String[] a = { "January","February","March","April","May","June","July","August","September","October","November","December" };
        for(int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }
        sort(a);
        for(int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }
    }
    public static void sort(String[] a) {
        for(int i =0;i < a.length-1; i++) {
            for(int j =0; j < a.length-i-1; j++) {
                if( a[j].compareTo(a[j+1]) > 0 ) {
                    String temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
    }
}
