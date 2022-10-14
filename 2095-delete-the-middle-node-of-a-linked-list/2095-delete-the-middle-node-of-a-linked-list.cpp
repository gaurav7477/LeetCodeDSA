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
//     ListNode* middle(ListNode* head){
//         if(head == NULL) return NULL;
//         ListNode* curr = NULL;
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast != NULL && fast->next != NULL){
            
//             fast = fast->next;
//             if(fast->next != NULL){
//                 fast = fast->next;
//             }
//             curr = slow;
//             slow = slow->next;
            
//         }
//         curr->next = slow->next;
//         delete slow;
//         return head;
//     }
    
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return NULL;
        ListNode* curr = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
            }
            curr = slow;
            slow = slow->next;
        }
        curr->next = slow->next;
        delete slow;
        
        return head;
    }
    
};