public class Solution {
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
     StringBuilder res;
    public String alienOrder(String[] words) {
        // Write your code here
        List<Character>[] lists = new ArrayList();
        for(String s : words)
        {
            for(char ch : s.toCharArray())
            {
                if(lists[ch - 'a'] == null)
                lists[ch - 'a'] = new LinkedList();
            }
        }

        //Initializing adjacency list
        for(int i=1; i<words.length();i++)
        {
            String s1 = words[i - 1], s2 = words[i];
            int min = Math.min(s1.length(), s2.length());
            if(s1.length() > s2.length() && areStringEqual(s1,s2,min))
            return "";

            for(int i=0;i<min;i++)
            {
                if(s1.charAt(i) != s2.charAt(i))
                {
                    lists[s1.charAt(i)].add(s2.charAt(i));
                    break;
                }
            }
        }
        //Check string equality
        //dfs
        Boolean[] visited = new Boolean[26];
        for(List<Character> list : lists)
        {
            for(char ch : list)
            {
                if(DFS(ch,lists, visited))
                return "";
            }
        }
        return res.toString();
    }
    public boolean areStringsEqual(String s1, String s2, int l)
    {
        for(int i=0;i<l;i++)
        {
            if(s1.charAt(i) != s2.charAt(i))
            return false;
        }
        return true;
    }

    public boolean DFS(char ch,List<Character>[] lists,Boolean[] visited  )
    {
        if(visited[ch - 'a'] != null)return visited[ch - 'a'];

        visited[ch - 'a'] = true;
        for(char neigh : lists[ch - 'a'])
        {
            if(DFS(neigh, lists, visited))
            return true;
        }
        visited[ch - 'a'] = false;
        res.insert(0, ch);
    }
}
