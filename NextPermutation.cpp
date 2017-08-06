class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool ordered = true;
        for(auto it = nums.rbegin(); it != nums.rend() - 1; ++it){
            //if the previous element is less than the current element
            if((*it) > (*(it + 1))){
                std::iter_swap(it, it + 1);
                ordered = false;
                break;
            } 
        }
        if(ordered) std::sort(nums.begin(), nums.end());
    }
};
