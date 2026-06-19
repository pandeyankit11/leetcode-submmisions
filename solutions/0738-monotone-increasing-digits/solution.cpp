class Solution {
public:
    bool isMonotone(vector<int>& vec) {
        for (int i = 0; i < vec.size() - 1; i++) {
            if (vec[i] > vec[i + 1])
                return false;
        }
        return true;
    }
    int monotoneIncreasingDigits(int n) {
        vector<int> vec;
        if(n==0) return 0;
        while (n > 0) {
            vec.push_back(n % 10);
            n /= 10;
        }

        reverse(vec.begin(), vec.end());

        while (!isMonotone(vec)) {
            for (int i = 0; i < vec.size() - 1; i++) {
                if (vec[i] > vec[i + 1]) {
                    vec[i]--;
                    i++;
                    while (i < vec.size()) {
                        vec[i] = 9;
                        i++;
                    }
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < vec.size(); i++) {
            ans += pow(10, vec.size() - i - 1) * vec[i];
        }

        return ans;
    }
};
