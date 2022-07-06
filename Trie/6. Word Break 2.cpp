struct Node {
  Node* links[26];
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
private : Node* root;

public :

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->putNewNode(ch, new Node());
            }
            node = node->getNextNode(ch);
        }
        node->markEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) return false;
            node = node->getNextNode(ch);
        }
        return node->isEnd();
    }
};

class Solution{
private:
    Trie* trie = new Trie();
    
    void solve(string& s, string ssf, int idx, vector<string>& ans) {
        if(idx == s.length()) {
            ans.push_back(ssf);
            return;
        }
        if(idx != 0) ssf += ' ';
        
        for(int i=idx; i<s.length(); i++) {
            string tmp = s.substr(idx, i-idx+1);
            if(trie->search(tmp)) {
                solve(s, ssf+tmp, i+1, ans);
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& dict) {
        
        for(string word : dict) trie->insert(word);
        
        vector<string> ans;
        
        solve(s, "", 0, ans);
        
        return ans;
        
    }
};