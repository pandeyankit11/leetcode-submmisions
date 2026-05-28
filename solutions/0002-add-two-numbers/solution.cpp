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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* prev=nullptr;

        int carry=0;

        while(temp1!=NULL || temp2!=NULL || carry>0){
            int digitFromL2;
            if(temp2!=NULL){
               digitFromL2=temp2->val;
            }
            else{
                digitFromL2=0;
            }

            int sum=digitFromL2+carry;
        
            if(temp1!=NULL){
            sum+=temp1->val;
            }

            int newDigit=sum%10;
            carry=sum/10;

            if(temp1!=NULL){
                temp1->val =newDigit;
                
                prev=temp1;
                temp1=temp1->next;
            }
            else{
                prev->next=new ListNode(newDigit);
                prev=prev->next;
            }
            if(temp2!=NULL)
            temp2=temp2->next;
        }

        return l1;
    }
};
