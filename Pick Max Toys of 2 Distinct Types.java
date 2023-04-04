import java.util.*;
public class Solution {
    public static void main(String[] args) {
        int arr = maxToysWithTwoDistinctTypes("xxxxxxyy");
        System.out.print(arr);
    }

    public static int maxToysWithTwoDistinctTypes(String s) {
        int res =0;
        int[] table = new int[26];
        int l = s.length();
        int ch;
        int start = 0;
        for(int end=0;end<l;end++)
        {
           ch = s.charAt(end) - 'a';
           table[ch]++;

           if(mapSize(table) == 2)
           {
                res = Math.max(res, mapCount(table));
           }
           else if(mapSize(table) > 2)
           {
                while(mapSize(table) > 2)
                table[s.charAt(start++) - 'a']--;
           }
        }
        return res;
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
