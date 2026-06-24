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
    

    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode*temp=head;
        ListNode* front;

        while(temp!=nullptr){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }

        return prev;
    }
    ListNode* getkthNode(ListNode* groupPrev,int k){
        while(k--){
            groupPrev=groupPrev->next;
            if(groupPrev==nullptr)
            return nullptr;
        }

        return groupPrev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(-1,head);

        ListNode* groupPrev=dummy;

        while(true){
        ListNode* kth=getkthNode(groupPrev,k);

        if(kth==nullptr)
        break;
        
        ListNode* groupNext=kth->next;

        kth->next=nullptr;

        ListNode* newHead=reverse(groupPrev->next);

        ListNode* oldHead=groupPrev->next;

        groupPrev->next=newHead;

        oldHead->next=groupNext;

        groupPrev=oldHead;

        }
        
        return dummy->next;

    }
};
