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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=0;
        ListNode* temp=head;
        while(temp!=NULL){
            sz++;
            temp=temp->next;
        }
        if(sz==1 && n==1) return nullptr;
        if(sz==n){
            ListNode* temp=head->next;
            head->next=nullptr;
            delete head;
            return temp;
        }

        int cnt=0;
        temp=head;
        while(cnt!=sz-n-1){
            cnt++;
            temp=temp->next;

        }
        ListNode* front=temp->next;
        temp->next=temp->next->next;
        front->next=nullptr;
        delete front;

        return head;


    }
};
