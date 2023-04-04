import java.util.*;
public class Solution {
    public static void main(String[] args) {
        int arr = longestSubstringWithKUniqueCharacters("aabacbebe", 3);
        System.out.print(arr);
    }
	public static int longestSubstringWithKUniqueCharacters(String s, int k) {
        // Write your code here.
        int max =0;
        int[] table = new int[26];
		int start=0,end=0;
        while(end < s.length())
        {
            table[s.charAt(end) - 'a']++;
            if(mapSize(table) == k)
            {
                max = Math.max(max, end - start + 1);
                System.out.println(max + " end: " + end + " start: " + start);
            }
            
            if(mapSize(table) > k)
            {
                while(mapSize(table) > k)table[s.charAt(start++)-'a']--;
            }
            end++;
        }
        return max;
	}

    public static int mapCount(int[] arr)
    {
        int res =0;
        for(int i=0;i<arr.length;i++)
        {
            res += arr[i];
        }
        return res;
    }

    public static int mapSize(int[] arr)
    {
        int size =0;
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i] != 0)size++;
        }
        return size;
    }
    }
