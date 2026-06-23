class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        // code here
        sort(meetings.begin(),meetings.end());
        vector<int>rooms(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>usedRooms;
        
        priority_queue<int,vector<int>,greater<int>>availableRooms;
        
        for(int i=0;i<n;i++){
            availableRooms.push(i);
        }
        
        for(auto &meet:meetings){
            int start=meet[0];
            int end=meet[1];
            int duration =end-start;
            
            while(!usedRooms.empty() && start>=usedRooms.top().first){
                int room=usedRooms.top().second;
                
                usedRooms.pop();
                availableRooms.push(room);
                
            }
            
            if(!availableRooms.empty()){
                
                int room=availableRooms.top();
                availableRooms.pop();
                
                usedRooms.push({end,room});
                rooms[room]++;
                
            }
            else{
                int room=usedRooms.top().second;
                long long endTime=usedRooms.top().first;
                
                usedRooms.pop();
                usedRooms.push({endTime + duration,room});
                rooms[room]++;
            }
            
        }
        
        int max_use=0;
        int result_room=-1;
        
        for(int i=0;i<n;i++){
            if(rooms[i]>max_use){
                max_use=rooms[i];
                result_room=i;
            }
        }
        
        return result_room;
        
    }
};
