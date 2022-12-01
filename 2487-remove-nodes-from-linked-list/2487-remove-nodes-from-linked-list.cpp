/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
            
            if(head == NULL || head->next == NULL)
            {
                return head;
            }
        ListNode* prev  = NULL;
        ListNode* curr = head;
        ListNode* forward = curr->next;
        
        while(curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    ListNode* removeNodes(ListNode* temp) {
       ListNode* head = reverseList(temp);
        // return head;
        ListNode* prev = head;
        if(head->next == NULL) return head;
        ListNode* curr = head->next;
        int maxVal = head->val;
        
        while(curr != NULL){
            if(curr->val < prev->val){
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                prev = prev->next;
                curr = curr->next;
            }
        }
        // return head;
        return reverseList(head);
    }
};