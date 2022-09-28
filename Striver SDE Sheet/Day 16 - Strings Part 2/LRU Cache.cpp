
class LRUCache {
public:    
    class Node {
    public:
        int key;
        int val;
        Node* next = NULL;
        Node* prev = NULL;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };
    
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
    
    int cap;
    unordered_map<int, Node*> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNewNode(Node* newNode) {
        Node* tmp = head->next;
        newNode->next = tmp;
        newNode->prev = head;
        tmp->prev = newNode;
        head->next = newNode;
    }
    
    void deleteNode(Node* target) {
        Node* tarNext = target->next;
        Node* tarPrev = target->prev;
        tarPrev->next = tarNext;
        tarNext->prev = tarPrev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node* resNode = mp[key];
            int res = resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNewNode(resNode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            deleteNode(mp[key]);
            mp.erase(key);
        }
        if(mp.size() == cap) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNewNode(new Node(key, value));
        mp[key] = head->next;
    }
};
