class Solution {
public:
    int search(vector<int>& nums, int target) {
        //iterate through as long as target is smaller than current num
        auto it = nums.begin();
        for(auto it = nums.begin(); it != nums.end(); ++it){
            if(*it == target){
                return it - nums.begin(); 
            } 
        }
        for(; it != nums.end(); ++it){
            if(*it < *(it - 1)){
                break; 
            } 
        }
        for(; it != nums.end(); ++it){
            if(*it > target){
                break; 
            } 
            else if(*it == target){
                return it - nums.begin(); 
            }
        }
        return -1;
    }
};
