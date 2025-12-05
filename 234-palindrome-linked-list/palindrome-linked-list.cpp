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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr and fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL and fast->next==nullptr) slow=slow->next;
        ListNode* prev=NULL;
        ListNode* temp=NULL;
        while(slow!=nullptr){
            temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        fast=head;
        while(fast and prev){
            if(prev->val!=fast->val) return false;
            prev=prev->next;
            fast=fast->next;
        }
        return true;
    }
};