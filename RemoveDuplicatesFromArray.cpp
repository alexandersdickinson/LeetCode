class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() > 1){
            int last = nums.front();
            for(auto it = nums.begin() + 1; it != nums.end();){
                if(last == *it){
                    it = nums.erase(it); 
                } 
                else{
                    last = *it;
                    ++it; 
                }
            }
        }
        return nums.size();
    }
};
