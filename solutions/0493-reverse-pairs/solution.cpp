class Solution {
public:
    int merge(vector<int>& arr, int low, int mid, int high) {
        int count = 0;

        int j = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (j <= high && arr[i] > 2LL*arr[j])
                j++;

            count += (j - (mid + 1));
        }

        int i = low;
        j = mid + 1;
        vector<int> temp;
        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }
        while (j <= high) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }

        return count;
    }

    int mergeSort(vector<int>& arr, int low, int high) {
        int count = 0;

        if (low < high) {
            int mid = (low + high) / 2;
            count += mergeSort(arr, low, mid);
            count += mergeSort(arr, mid + 1, high);

            count += merge(arr, low, mid, high);
        }

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
