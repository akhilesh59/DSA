struct Node {
    Node* links[2];
    
    bool containsKey(int& bit) {
        return (links[bit] != NULL);
    }
    
    Node* getNextNode(int& bit) {
        return links[bit];
    }
    
    void putNewNode(int& bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
private : Node* root;
    
public :
    
    Trie() {
        root = new Node();
    }
    
    void insert(int& num) {
        Node* node = root;
        for(int i=31; i>=0; i--) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) {
                node->putNewNode(bit, new Node());
            }
            node = node->getNextNode(bit);
        }
    }
    
    int getMax(int& num) {
        Node* node = root;
        int maxi = 0;
        for(int i=31; i>=0; i--) {
            int bit = (num >> i) & 1;
            int opp = 1-bit;
            if(node->containsKey(opp)) {
                maxi |= (1 << i);
                node = node->getNextNode(opp);
            }
            else node = node->getNextNode(bit);
        }
        
        return maxi;
    }
    
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& qrs) {
        int n = arr.size(), q = qrs.size();
        
        sort(begin(arr), end(arr));
        
        for(int i=0; i<q; i++) qrs[i].push_back(i);
        
        sort(begin(qrs), end(qrs), [](auto& a, auto& b) {return a[1] < b[1];});
        
        vector<int> ans(q);
        int j=0;
        Trie* trie = new Trie();
        
        for(int i=0; i<q; i++) {
            int x = qrs[i][0], m = qrs[i][1], idx = qrs[i][2];
            
            while(j < n && arr[j] <= m) {
                trie->insert(arr[j]);
                j++;
            }
            
            int max_val = (j == 0) ? -1 : trie->getMax(x); // It means that no element is inserted in the trie.
            ans[idx] = max_val == -1 ? -1 : max_val;
        }
        
        return ans;
        
    }
};