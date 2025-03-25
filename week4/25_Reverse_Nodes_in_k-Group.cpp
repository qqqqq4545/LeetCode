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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* prev = &dummy;
        ListNode* curr = head;
        ListNode* next = nullptr;
        
        // Count the number of nodes
        int count = 0;
        ListNode* counter = head;
        while (counter) {
            count++;
            counter = counter->next;
        }
        
        while (count >= k) {
            // First node will be the last after reversal
            ListNode* groupStart = curr;
            
            // Reverse k nodes
            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
                curr = next;
            }
            
            // Connect with the previous group
            groupStart->next = curr;
            
            // Move prev pointer to the end of the current group
            prev = groupStart;
            
            count -= k;
        }
        
        return dummy.next;
    }
};
