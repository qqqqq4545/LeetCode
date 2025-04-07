/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Custom comparator for the min-heap
        struct Compare {
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        };
        
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        // Push the first node of each list into the min-heap
        for (ListNode* list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Process nodes until the heap is empty
        while (!pq.empty()) {
            // Get the node with the smallest value
            ListNode* current = pq.top();
            pq.pop();
            
            // Add it to the result list
            tail->next = current;
            tail = tail->next;
            
            // If there are more nodes in this list, add the next node to the heap
            if (current->next) {
                pq.push(current->next);
            }
        }
        
        return dummy.next;
    }
};
