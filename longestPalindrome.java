class Solution {
    public int longestPalindrome(String s) {
        int[] arr = new int[126];
        int l = s.length(), res = 0;
        boolean oddFound = false;
        for(int i=0;i<l;i++)
        {
            arr[s.charAt(i)]++;
        }
        for(int i=0;i<126;i++)
        {
            if(arr[i] % 2 == 0)
            {
                res += arr[i];
            }else{
                res += arr[i] - 1;
                if(!oddFound)
                {
                    res++;
                    oddFound = true;
                }
            }
        }
        return res;
    }
}
