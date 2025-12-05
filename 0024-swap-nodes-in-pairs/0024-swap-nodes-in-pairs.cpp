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
    ListNode* swapPairs(ListNode* head) {
        ListNode* slow=head,*fast;
        if(head==nullptr or head->next==nullptr) return head;
        fast=head->next;
        int cnt=0;
        while(fast and fast->next){
            swap(slow->val,fast->val);
            slow=fast->next;
            fast=fast->next->next;
            cnt++;
        }
        if(cnt%2==1 cnt>1){
            if(slow and fast)
                swap(slow->val,fast->val);
        } 
        return head;
    }
};