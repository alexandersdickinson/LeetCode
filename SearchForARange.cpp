class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        std::vector<int> solution;
        auto it = nums.begin();
        for(it = nums.begin(); it != nums.end(); ++it){
            if(*it == target){
                solution.push_back(it - nums.begin()); 
            }
            else if(solution.size() > 0){
                break; 
            }
        }
        if(solution.size() == 0){
            return {-1, -1}; 
        }
        else if(solution.size() == 1){
            solution.push_back(solution.at(0));
            return solution;
        }
        else{
            if(solution.size() > 2){
                solution.erase(solution.begin() + 1, solution.end() - 1); 
            }
            return solution; 
        }
    }
};
