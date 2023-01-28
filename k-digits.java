import java.util.*;

class Solution {
    public static void main(String[] args) {
        System.out.print(removeKdigits("14356871", 4));
    }
    public static String removeKdigits(String num, int k) {
        Deque<Character> q = new ArrayDeque<>();
        for(int i=0;i<num.length();i++)
        {
            char ch = num.charAt(i);
            while(q.size() >0 && k > 0 && q.getLast() > ch)
            {
                k--;
                q.removeLast();
            }
            q.addLast(ch);
        }
        while(q.size() > 0 && k > 0)
        {
            k--;
            q.removeLast();
        }
        while(q.size()>0 && q.getFirst() == '0')
        {
            q.removeFirst();
        }
        if(q.size() == 0) return "0";
        StringBuilder str = new StringBuilder();
        while(q.size() > 0)
        {
            str.append(q.removeFirst());
        }
        return str.toString();
}
}