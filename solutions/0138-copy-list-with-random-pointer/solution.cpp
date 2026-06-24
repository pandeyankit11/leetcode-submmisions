/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;

        unordered_map<Node*,Node*>m;

        while(temp!=nullptr){
            Node* newNode=new Node(temp->val);
            m[temp]=newNode;
            temp=temp->next;
        }
        temp=head;
        Node* copyList;

        while(temp!=nullptr){
            copyList=m[temp];

            copyList->next=m[temp->next];
            copyList->random=m[temp->random];
            temp=temp->next;
        }

        return m[head];

    }
};
