class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //Find the rightmost element that is smaller in value than an element to the right.
        auto rleft = nums.rbegin() + 1;
        for(; rleft != nums.rend(); ++rleft){
            if((*rleft) < (*(rleft - 1))){
                break; 
            } 
        }
        //return sorted list if every element is larger than the last iterating from back to front.
        if(rleft == nums.rend()){
            std::sort(nums.begin(), nums.end());
            return;
        }
        //Then find the smallest of these larger elements, swap with the leftmost smaller element.
        auto left = (rleft + 1).base();
        auto right = rleft.base();
        for(auto it = right; it != nums.end(); ++it){
            if((*it) < (*right) && (*it) > (*left)){
                right = it; 
            } 
        }
        std::iter_swap(left, right);
        std::sort(left + 1, nums.end());
    }
};
