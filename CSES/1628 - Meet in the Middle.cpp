// author: uwuenvy <3
// problem: Meet in the Middle
// created: 5/24/2022 9:38 PM
 
import java.util.*;
import java.io.*;
 
@SuppressWarnings("unchecked")
public class Main {
 
    public static void main(String[] args) {
        Kattio io = new Kattio();
 
        int n = io.nextInt(), x = io.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = io.nextInt();
        }
 
        long[] left = get_subset_sums(a, 0, n / 2 - 1);
        long[] right = get_subset_sums(a, n/2, n-1);
        Arrays.sort(right);
 
        long answer = 0;
        for(long i: left){
            int low_index = lower_bound(right, x - i);
            int high_index = lower_bound(right, x - i + 1);
            answer += high_index - low_index;
        }
 
        io.println(answer);
        io.close();
    }
 
    public static long[] get_subset_sums(int[] a, int l, int r){
        int len = r - l + 1;
        int index = 0;
        long[] sums = new long[(1 << len)];
 
        for(int i = 0; i < (1 << len); i++){
            for(int j = 0; j < len; j++){
                if((i & (1 << j)) != 0){
                    sums[index] += a[j + l];
                }
            }
            index++;
        }
 
        return sums;
    }
 
    // finds the first index which has equal or greater than an element.
    public static int lower_bound(long[] arr, long x){
        int l = -1, r = arr.length;
        while(l < r-1){
            int mid = l + (r - l) / 2;
            if(arr[mid] < x){
                l = mid;
            }
            else r = mid;
        }
        return r;
    }
}
 
class Kattio extends PrintWriter {
    private BufferedReader r;
    private StringTokenizer st;
    // standard input
    public Kattio() { this(System.in,System.out); }
    public Kattio(InputStream i, OutputStream o) {
        super(o);
        r = new BufferedReader(new InputStreamReader(i));
    }
    // USACO-style file input
    public Kattio(String problemName) throws IOException {
        super(problemName+".out");
        r = new BufferedReader(new FileReader(problemName+".in"));
    }
    // returns null if no more input
    public String next() {
        try {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(r.readLine());
            return st.nextToken();
        } catch (Exception e) {}
        return null;
    }
    public int nextInt() { return Integer.parseInt(next()); }
    public double nextDouble() { return Double.parseDouble(next()); }
    public long nextLong() { return Long.parseLong(next()); }
}

