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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        int maxi=0;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *next,*prev=NULL;
        while(slow){
            next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }
        while(prev){
            maxi=max(maxi,head->val+prev->val);
            head=head->next;
            prev=prev->next;
        }
        return maxi;
    }
};