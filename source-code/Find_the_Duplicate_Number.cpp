// O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int indx = abs(nums[i]) - 1;
            if(nums[indx] < 0) {
                return indx + 1;
            }
            nums[indx] = -nums[indx];
        }
        return INT_MIN;
    }
};

class Solution {
    int countNumbers(vector<int> const& nums, int mid) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++i) {
            cnt += (nums[i] <= mid);
        }
        return cnt;
    }
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        int left = 1, right = n - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            int cnt = countNumbers(nums, mid);
            if(cnt <= mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};