public class QuickSort {
    public static void main(String[] args) {
        String[] a = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October",
                "November", "December" };
        for (int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }
        sort(a, 0, a.length-1);
        for (int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }
    }

    public static void sort(String[] a, int low, int high) {
        if(low >= high) {
            return;
        }
        String pivot = a[(low+high)/2];
        int i = low, j = high;
        while(i<=j){
            while( pivot.compareTo(a[i]) > 0 ) i++;
            while( pivot.compareTo(a[j]) < 0 ) j--;
            if( i<=j ) {
                String temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;j--;
            }
        }
        sort(a, low, j);
        sort(a, i, high);
    }
}
