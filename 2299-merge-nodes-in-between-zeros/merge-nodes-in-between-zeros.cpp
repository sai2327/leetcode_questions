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
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        ListNode* res=new ListNode(0);
        ListNode* temp=res;
        ListNode* curr=head->next;
        while(curr!=nullptr){
            if(curr->val==0){
                if(sum!=0){
                    res->next=new ListNode(sum);
                    sum=0;
                    res=res->next;
                }
            }
            else{
                sum+=curr->val;
            }
            curr=curr->next;
        }
        return temp->next;

    }
};