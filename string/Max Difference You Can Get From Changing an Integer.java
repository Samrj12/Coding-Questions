class Solution {
    public int maxDiff(int num) {
        String n1 = String.valueOf(num);
        String n2 = String.valueOf(num);
        int pos = 0;
        while(pos < n1.length() && n1.charAt(pos) == '9'){
            pos++;
        }
        if(pos < n1.length())
        n1 = n1.replace(n1.charAt(pos), '9');
        pos = 0;
        while(pos < n2.length()){
            if(pos == 0){
                if(n2.charAt(pos) != '1')
                break;
            }else{
                 if(n2.charAt(pos) != '0' && n2.charAt(pos) != n2.charAt(0))
                 break;
            }
            pos++;
        }
        
        if(pos < n2.length())
        n2 = n2.replace(n2.charAt(pos), pos == 0 ? '1' : '0');
        
        return Integer.parseInt(n1) - Integer.parseInt(n2);
    }
}
