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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; 
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* ,vector<ListNode*>,Compare>minheap;
        for(ListNode* l:lists){
            if(l) minheap.push(l);
        }
        ListNode dummy;
        ListNode* tail=&dummy;
        while(!minheap.empty()){
            ListNode* smallest=minheap.top();
            minheap.pop();
            tail->next=smallest;
            tail=tail->next;
            if(smallest->next)minheap.push(smallest->next);
        }
        return dummy.next;
    }
};