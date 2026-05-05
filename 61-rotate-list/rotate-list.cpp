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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr or head->next==nullptr or k==0) return head;
        int len=1;
        ListNode* tail=head;
        while(tail->next){
            tail=tail->next;
            len++;
        }
        tail->next=head;
        k%=len;
        int n=len-k;
        tail=head;
        for(int i=0;i<n-1;i++) tail=tail->next;
        head=tail->next;
        tail->next=nullptr;
        return head;
    }
};