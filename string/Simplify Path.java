class Solution {
    public String simplifyPath(String path) {
        Stack<String> stk = new Stack();
        String[] tkns = path.split("/");
        for (String tkn : tkns) {
            if (tkn.length() == 0)
                continue;
            if (tkn.equals(".")) {
                continue;
            } else if (tkn.equals("..")) {
                if (stk.empty())
                    continue;
                stk.pop();
            } else {
                stk.push(tkn);
            }
        }
        StringBuilder res = new StringBuilder();
        while (!stk.empty()) {
            String s = stk.pop();
            res.insert(0, s);
            res.insert(0, '/');
        }
        return res.length() == 0 ? "/" : res.toString();
    }
}
