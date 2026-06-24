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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode(-1);

        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;

        for(int i=0;i<lists.size();i++){
            ListNode* head=lists[i];

            ListNode* temp=head;
            while(temp!=nullptr){
                pq.push({temp->val,temp});
                temp=temp->next;
            }
        }

        ListNode* tail=dummy;

        while(!pq.empty()){
            tail->next=pq.top().second;
            pq.pop();
            tail=tail->next;
            
        }

        return dummy->next;

    }
};
