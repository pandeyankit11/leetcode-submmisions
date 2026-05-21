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
    
    long long sumSubarrayMins(vector<int>& arr) {
        long long left{0},right{0};
        
        long long total{0};
        vector<int>left_bound(psee(arr));
        vector<int>right_bound(nse(arr));
        for(int i=0;i<arr.size();i++){
           left=i-left_bound[i];
           right=right_bound[i]-i;
           long long product=(left*right);
           long long contribution=(product*arr[i]);
           total=(total+contribution);
        }
        return total;
    }

  
  
    vector<int> pgee(vector<int> &arr){
      stack<int> st;
      vector<int> pgee(arr.size());
      for(int i = 0; i < arr.size(); i++){
          
          while(!st.empty() && arr[st.top()] < arr[i])
              st.pop();

          if(st.empty()) pgee[i] = -1;
          else{
              pgee[i] = st.top();
          }
          st.push(i);
      }
      return pgee;
    }

    
    vector<int> nge(vector<int> &arr){
      stack<int> st;
      vector<int> nge(arr.size());
      for(int i = arr.size() - 1; i >= 0; i--){
          
          while(!st.empty() && arr[st.top()] <= arr[i])
              st.pop();

          if(st.empty()) nge[i] = arr.size();
          else{
              nge[i] = st.top();
          }
          st.push(i);
      }
      return nge;
    }
    
    long long sumSubarrayMaxs(vector<int>& arr) {
        long long left{0}, right{0}; 
        
        long long total{0};
        
        
        vector<int> left_bound(pgee(arr));
        vector<int> right_bound(nge(arr));
        
        for(int i = 0; i < arr.size(); i++){
           left = i - left_bound[i];
           right = right_bound[i] - i;
           
           long long product = (left * right) ;
           long long contribution = (product * arr[i]);
           total = (total + contribution);
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};
