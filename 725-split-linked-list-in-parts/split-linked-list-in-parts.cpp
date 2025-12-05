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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>parts(k,NULL);
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        int n=cnt/k,r=cnt%k;
        ListNode* curr=head,*prev=nullptr;
        for(int i=0;i<k and curr;i++){
            parts[i]=curr;
            for(int j=0;j<n+(r>0);j++){
                prev=curr;
                curr=curr->next;
            }
            prev->next=nullptr;
            r--;
        }
        return parts;
    }
};