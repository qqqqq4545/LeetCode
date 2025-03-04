class LRUCache {
private:
    struct DLinkedNode {
        int key;
        int value;
        DLinkedNode* prev;
        DLinkedNode* next;
        DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
        DLinkedNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    
    unordered_map<int, DLinkedNode*> cache;
    
    DLinkedNode* head;
    DLinkedNode* tail;
    
    int capacity;
    int size;
    
    void addNode(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(DLinkedNode* node) {
        DLinkedNode* prev = node->prev;
        DLinkedNode* next = node->next;
        
        prev->next = next;
        next->prev = prev;
    }
    
    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addNode(node);
    }
    
    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        
        head = new DLinkedNode();
        tail = new DLinkedNode();
        
        head->next = tail;
        tail->prev = head;
    }
    
    ~LRUCache() {
        // Clean up all nodes to prevent memory leaks
        DLinkedNode* curr = head;
        while (curr != nullptr) {
            DLinkedNode* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    
    int get(int key) {
        // Check if key exists in cache
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        
        // Get the node and move it to the head 
        DLinkedNode* node = cache[key];
        moveToHead(node);
        
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update the value and move to head
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
            return;
        }
        
        DLinkedNode* newNode = new DLinkedNode(key, value);
        
        // Add to the cache and the list
        cache[key] = newNode;
        addNode(newNode);
        size++;
        
        // If over capacity, remove the LRU item
        if (size > capacity) {
            DLinkedNode* tailNode = removeTail();
            cache.erase(tailNode->key);
            delete tailNode;
            size--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
