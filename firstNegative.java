import java.util.*;
public class Solution {
    public static void main(String[] args) {
        int[] arr = firstNegative(new int[] {3,-1, -2, -4, 2 , 3}, 6, 2);
        for(int i=0;i<arr.length;i++)
        System.out.print(arr[i]);
    }
	public static int[] firstNegative(int[] arr, int n, int k) {
        // Write your code here.
		List<Integer> l = new ArrayList<>();
		int[] res = new int[n - k + 1];
		int j=0,i;
        for( i=0;i <k;i++)if(arr[i] < 0) l.add(arr[i]);
		for(;i<n;i++){
			if(arr[i] < 0)
            l.add(arr[i]);

			if(l.isEmpty())
				res[j] = 0;
			else
            {
                res[j] = l.get(0);
            }
            if(arr[j] < 0) l.remove(0);
            j++;
		}
		return res;
	}
}
