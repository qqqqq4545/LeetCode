class FreqStack {
private:
    unordered_map<int, int> freq;  // Maps value to its frequency
    unordered_map<int, stack<int>> freqStacks;  // Maps frequency to stack of values with that frequency
    int maxFreq;
    
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        
        maxFreq = max(maxFreq, freq[val]);
        
        // Push val to the stack corresponding to its new frequency
        freqStacks[freq[val]].push(val);
    }
    
    int pop() {
        // Get the top element from the stack with maximum frequency
        int val = freqStacks[maxFreq].top();
        freqStacks[maxFreq].pop();
        
        // Decrease frequency of the popped element
        freq[val]--;
        
        // If the stack for maxFreq becomes empty, decrease maxFreq
        if (freqStacks[maxFreq].empty()) {
            maxFreq--;
        }
        
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
