class Solution {
    public boolean wordPattern(String pattern, String s) {
        int l1 = pattern.length();
        String[] split = s.split(" ");
        int l2 = split.length;
        if(l1 != l2)
        return false;
        int index = 0;
        HashMap<Character, String> charMap = new HashMap<>();
        charMap.put(pattern.charAt(index), split[index]);
        index++;
        while(index < l2)
        {
            if(charMap.containsKey(pattern.charAt(index)))
            {
            if(!charMap.get(pattern.charAt(index)).equals(split[index]))
            return false;
            index++;
            }
            else{
                if(charMap.containsValue(split[index]))
                return false;
                charMap.put(pattern.charAt(index), split[index]);
                index++;
            }
        }
        return true;

    }
}
