/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp=head;
        while(temp){
            if(temp->child){
                Node* next=temp->next;
                temp->next=temp->child;
                temp->next->prev=temp;
                temp->child=nullptr;
                Node *next1=temp->next;
                while(next1->next){
                    next1=next1->next;
                }
                next1->next=next;
                if(next) next->prev=next1;
            }
            temp=temp->next;
        }
        return head;
    }
};