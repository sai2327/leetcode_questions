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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp=new ListNode(0);
        temp->next=head;
        unordered_map<int,ListNode*>mp;
        int sum=0;
        for(ListNode* cur=temp;cur;cur=cur->next){
            sum+=cur->val;
            mp[sum]=cur;
        }
        sum=0;
        for(ListNode* cur=temp;cur;cur=cur->next){
            sum+=cur->val;
            cur->next=mp[sum]->next;
        }
        return temp->next;
    }
};