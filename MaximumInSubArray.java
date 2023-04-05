import java.util.*;
public class Solution {
    public static void main(String[] args) {
        int[] arr = firstNegative(new int[] {3,-1, -2, -4, 2 , 3}, 6, 3);
        for(int i=0;i<arr.length;i++)
        System.out.print(arr[i]);
    }
	public static int[] firstNegative(int[] arr, int n, int k) {
        // Write your code here.
		Queue<Integer> l = new LinkedList<>();
        int res[] = new int[n - k + 1];
		int start=0,end=0;
        while(end < n)
        {
            while(l.size() > 0 && l.peek() < arr[end])
                {
                    l.poll();
                }
            //Calculation
            l.add(arr[end]);
            if(end - start + 1 < k)
            {
                end++;
            }
            
           else if(end - start + 1 == k)
            {
                res[start] = l.peek();
                if(arr[start] == l.peek())
                {
                    l.poll();
                }
                start++;
            }
        }
        return res;
	}
    /* More optimized
     * public static int[] firstNegative(int[] arr, int n, int k) {
        // Write your code here.
		Queue<Integer> l = new LinkedList<>();
        int res[] = new int[n - k + 1];
		int start=0,end=0;
        for(; end<k-1;end++)
        {
            while(l.size() > 0 && l.peek() < arr[end])
                {
                    l.poll();
                }
            //Calculation
            l.add(arr[end]);
        }
        while(end < n)
        {
            
            while(l.size() > 0 && l.peek() < arr[end])
                {
                    l.poll();
                }
            //Calculation
            l.add(arr[end++]);
            
            res[start] = l.peek();
            if(arr[start] == l.peek())
            {
                l.poll();
            }
            start++;
        }
        return res;
	}
     */
}
