class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;

        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(pq.size()!=1 && !pq.empty()){
            int x=pq.top();
            pq.pop();
            if(x==pq.top()){
                pq.pop();

            }else{
                int diff=x-pq.top();
                pq.pop();
                pq.push(diff);
            }
        }

        if(pq.empty()) return 0;

        return pq.top();
    }
};
