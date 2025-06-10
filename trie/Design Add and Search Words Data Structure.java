class WordDictionary {
    Node root;
    public WordDictionary() {
        root = new Node();
    }
    
    public void addWord(String word) {
        root.addWord(word, 0);
    }
    
    public boolean search(String word) {
        return root.search(word, 0);
    }

    class Node{
        Node[] nodes;
        boolean isWord;
        Node(){
            nodes = new Node[26];
        }

        private void addWord(String w, int idx)
        {
            if(w.length() == idx)return;
            int i = w.charAt(idx) - 'a';
            if(nodes[i] == null)
            {
                nodes[i] = new Node();
            }
            if(idx == w.length() - 1) nodes[i].isWord= true;
            nodes[i].addWord(w, idx + 1);
        }

        private boolean search(String w, int idx)
        {
            if(w.length() == idx)return false;
            char ch = w.charAt(idx);
            if(ch == '.')
            {
                for(Node node: nodes)
                {
                    if(node != null)
                    {
                        if(idx == w.length() - 1 && node.isWord)return true;
                        if(node.search(w, idx + 1))return true;
                    }
                }
            }
            else
            {
                Node node = nodes[ch - 'a'];
                if(node == null)return false;
                if(idx == w.length() - 1 && node.isWord)return true;
                return node.search(w, idx + 1);
            }
            return false;
        }

    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
