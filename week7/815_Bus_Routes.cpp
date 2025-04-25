class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }
        
        // Build a map from bus stop to all the buses that go through it
        unordered_map<int, vector<int>> stopToBuses;
        for (int busId = 0; busId < routes.size(); busId++) {
            for (int stop : routes[busId]) {
                stopToBuses[stop].push_back(busId);
            }
        }
        
        queue<int> q;
        unordered_set<int> visitedStops; // Visited stops
        unordered_set<int> visitedBuses; // Visited buses
        
        // Start from the source
        q.push(source);
        visitedStops.insert(source);
        
        int buses = 0;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                int currentStop = q.front();
                q.pop();
                
                // Check all buses that go through this stop
                for (int busId : stopToBuses[currentStop]) {
                    // Skip already taken
                    if (visitedBuses.count(busId)) {
                        continue;
                    }
                    
                    visitedBuses.insert(busId);
                    
                    // Check all stops this bus goes through
                    for (int nextStop : routes[busId]) {
                        // new stop , return the number of buses + 1
                        if (nextStop == target) {
                            return buses + 1;
                        }
                        
                        if (!visitedStops.count(nextStop)) {
                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
            
            buses++;
        }
        
        return -1;
    }
};
