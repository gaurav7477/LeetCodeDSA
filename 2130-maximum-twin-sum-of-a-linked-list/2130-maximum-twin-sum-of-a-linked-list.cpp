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
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }
    int pairSum(ListNode* head) {
        ListNode* middle = getMid(head);
        cout << middle->val;
        ListNode* temp = middle;
        ListNode* head2 = reverse(temp);
        ListNode* head1 = head;
        // cout << head1->val;
        
        while(head1->next!=NULL && head2!=NULL){
            head1->val = head1->val + head2->val;
            head1 = head1->next;
            head2 = head2->next;
        }
        head1->next = NULL;
        int maxi = head->val;
        head = head->next;
        while(head!=NULL){
            if(head->val>maxi){
                maxi = head->val;
            }
            head = head->next;
        }
        
        return maxi;
    }
};