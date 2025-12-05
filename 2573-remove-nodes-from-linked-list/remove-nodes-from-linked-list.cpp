class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> arr;
        for(ListNode* t=head;t;t=t->next) arr.push_back(t->val);

        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty() || arr[i]>=st.top()) st.push(arr[i]);
        }

        ListNode* newHead=nullptr,*cur=nullptr;
        while(!st.empty()){
            if(!newHead){
                newHead=new ListNode(st.top());
                cur=newHead;
            }
            else{
                cur->next=new ListNode(st.top());
                cur=cur->next;
            }
            st.pop();
        }
        return newHead;
    }
};
