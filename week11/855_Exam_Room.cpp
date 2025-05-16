class ExamRoom {
private:
    int n;
    set<int> seats;
    // {-distance, position, start, end}
    set<tuple<int, int, int, int>> intervals;
    
    // Calculate distance and position for interval
    tuple<int, int, int, int> getInterval(int start, int end) {
        int pos, dist;
        
        if (start == -1) {
            pos = 0;
            dist = end;
        } else if (end == n) {
            pos = n - 1;
            dist = n - 1 - start;
        } else {
            pos = start + (end - start) / 2;
            dist = (end - start) / 2;
        }
        
        return {-dist, pos, start, end};
    }
    
    void addInterval(int start, int end) {
        if (start < end) { // Only add valid intervals
            intervals.insert(getInterval(start, end));
        }
    }
    
public:
    ExamRoom(int n) {
        this->n = n;
        intervals.insert({-n, 0, -1, n});
    }
    
    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            intervals.clear();
            
            addInterval(-1, 0);
            addInterval(0, n);
            return 0;
        }
        
        // Get the interval with maximum distance
        auto [negDist, pos, start, end] = *intervals.begin();
        
        // Remove the current interval
        intervals.erase(intervals.begin());
        
        // Add the student to the seat
        seats.insert(pos);
        
        addInterval(start, pos);
        addInterval(pos, end);
        
        return pos;
    }
    
    void leave(int p) {
        seats.erase(p);
        
        auto it = seats.lower_bound(p);
        int right = (it == seats.end()) ? n : *it;
        int left = (it == seats.begin()) ? -1 : *(--it);
        
        intervals.erase(getInterval(left, p));
        intervals.erase(getInterval(p, right));
        
        addInterval(left, right);
        
        if (seats.empty()) {
            intervals.clear();
            intervals.insert({-n, 0, -1, n});
        }
    }
};
