class Solution {
public:

    vector<int> psee(vector<int> &arr){
      stack<int>st;
      vector<int>psee(arr.size());
     for(int i=0;i<arr.size();i++){
      while(!st.empty() && arr[st.top()]>arr[i])
      st.pop();

      if(st.empty()) psee[i]=-1;
      else{
        psee[i]=st.top();
      }
      st.push(i);
     }
     return psee;

    }
    vector<int> nse(vector<int> &arr){
       stack<int>st;
      vector<int>nse(arr.size());
     for(int i=arr.size()-1;i>=0;i--){
      while(!st.empty() && arr[st.top()]>=arr[i])
      st.pop();

      if(st.empty()) nse[i]=arr.size();
      else{
        nse[i]=st.top();
      }
      st.push(i);
     }
     return nse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int left{0},right{0};
        long long mod=1e9+7;
        long long total{0};
        vector<int>left_bound(psee(arr));
        vector<int>right_bound(nse(arr));
        for(int i=0;i<arr.size();i++){
           left=i-left_bound[i];
           right=right_bound[i]-i;
           long long product=(left*right)%mod;
           long long contribution=(product*arr[i])%mod;
           total=(total+contribution)%mod;
        }
        return total;
    }
};
