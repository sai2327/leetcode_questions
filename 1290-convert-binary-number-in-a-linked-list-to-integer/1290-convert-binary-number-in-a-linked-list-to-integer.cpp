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
    int getDecimalValue(ListNode* head) {
        vector<int>arr;
        while(head){
            arr.push_back(head->val);
            head=head->next;
        }
        int n=arr.size()-1;
        int ans=0;
        for(int i:arr){
            ans+=pow(2,n)*i;
            n--;
        }
        return ans;
    }
};