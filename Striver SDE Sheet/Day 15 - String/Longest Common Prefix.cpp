struct Node {
    Node* links[26];
    int cnt = 0;
    bool flag = false;
    
    bool containsKey(char& ch) {
        return (links[ch-'a'] != NULL);
    }
    
    Node* getNextNode(char& ch) {
        return links[ch-'a'];
    }
    
    void putNewNode(char& ch, Node* node) {
        links[ch-'a'] = node;
    }
    
    void markEnd() {
        flag = true;
    }
      
    bool isEnd() {
        return flag;
    }
    
};

class Trie {
private :
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) node->putNewNode(ch, new Node());
            node = node->getNextNode(ch);
            node->cnt = node->cnt + 1;
        }
    }
    
    bool search(string word, int n) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) return 0;
            node = node->getNextNode(ch);
            if(node->cnt != n) return 0;
            
        }
        return 1;
    }
    
};
class Solution {

public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie *trie = new Trie();
        int sz = strs.size();
        
        for(string s : strs) trie->insert(s);
        
        int i=0, n = strs[0].length();
        string tmp = strs[0];
        string test = "";
        while(i < n) {
            test += tmp[i];
            if(trie->search(test, sz) == 0) break;
            ++i;
        }
        return tmp.substr(0,i);
    }
};