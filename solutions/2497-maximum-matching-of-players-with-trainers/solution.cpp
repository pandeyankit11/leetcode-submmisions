class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int i=0;

        for(int j=0;j<trainers.size();j++){
            if(i<players.size() && players[i]<=trainers[j]){
                i++;
            }
        }

        return i;
    }
};
