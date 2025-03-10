```cpp
class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>> keyToValFreq;
    unordered_map<int, list<int>::iterator> keyToIter;
    unordered_map<int, list<int>> freqToKeys;
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (keyToValFreq.find(key) == keyToValFreq.end()) {
            return -1;
        }
        
        updateFrequency(key);
        
        return keyToValFreq[key].first;
    }
    
    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        
        // If key already exists, update value and frequency
        if (keyToValFreq.find(key) != keyToValFreq.end()) {
            keyToValFreq[key].first = value;
            updateFrequency(key);
            return;
        }
        
        // If cache is full, remove least frequently used key
        if (keyToValFreq.size() >= capacity) {
            int keyToRemove = freqToKeys[minFreq].back();
            freqToKeys[minFreq].pop_back();
            
            if (freqToKeys[minFreq].empty()) {
                freqToKeys.erase(minFreq);
            }
            
            keyToIter.erase(keyToRemove);
            keyToValFreq.erase(keyToRemove);
        }
        
        // Add new key
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;
    }
    
private:
    void updateFrequency(int key) {
        int freq = keyToValFreq[key].second;
        
        int val = keyToValFreq[key].first;
        
        freqToKeys[freq].erase(keyToIter[key]);
        
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (freq == minFreq) {
                minFreq++;
            }
        }
        
        freq++;
        
        freqToKeys[freq].push_front(key);
        
        keyToValFreq[key] = {val, freq};
        keyToIter[key] = freqToKeys[freq].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
