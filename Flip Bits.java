import java.util.* ;
import java.io.*; 
public class Solution {
	public static int flipBits(int[] arr,int n) {
		int o = 0;
		int currSum =0, max=0;
		for(int i=0;i<n;i++)
		{
			int val = 1;
			if(arr[i] == 1)
			{
				o++;
				val = -1;
			}
			currSum = Math.max(val, currSum + val);
			max = Math.max(currSum, max);
		}
		return max + o;
	}
}
