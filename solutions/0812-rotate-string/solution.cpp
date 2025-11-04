class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
        return false;
        auto it=s.end();
        s.insert(it,s.begin(),s.end());
        if(s.find(goal)!=string::npos)
        return true;

        return false;
            
    }
};
