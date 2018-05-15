// This is the first solution I could think of and it beats 48% of the solutions. Simple approach find all the indices of zeros and try 
// to find the difference in the current zero index and the previous zero index and then maximize the difference.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int prev_ind = -1, curr_ind = 0, max = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                curr_ind = i;
                max = max > (curr_ind - prev_ind - 1) ? max : (curr_ind - prev_ind - 1);
                prev_ind = curr_ind;
            }
        }
        max = max > (nums.size() - prev_ind - 1) ? max : (nums.size() - prev_ind - 1);
        return max;
    }
};

// A much simplier and naive approach can be to simply count the number of 1's and find the max of the counts. The previous solution is a
// little complicated

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0, count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]) count++;
            else{
                max = max > count ? max : count;
                count = 0;
            }
        }
        max = max > count ? max : count;
        return max;
    }
};
