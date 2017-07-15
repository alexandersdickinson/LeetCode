class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mid = int();
        int left = 0;
        int right = nums.size() - 1;
        int smallestDifference = INT_MAX;
        int smallestDifferenceSum = int();

        //while left and right are not next to each other, start at opposite ends of the array
            //if sum of left and right - target is greater than or equal to zero
                //then start from the left + 1, move mid right across the array until sum of left, right, mid - target is not negative
            //if sum of left and right - target is negative (else)
                //then start from the right - 1, move mid left across the array until sum of left, right, mid - target is not positive
            //if sum is zero
                //return 0
            //else 
                //record sum - target, compare to smallest difference.
            //if sum of left and rigtht is greater than or equal to 0, decrement right
            //else increment left

        while(right != left + 1){
            if(nums.at(left) + nums.at(right) - target >= 0){
                for(mid = left + 1; nums.at(left) + nums.at(mid) + nums.at(right) - target >= 0 && mid < right - 1; ++mid);
                std::cout << "One pass through array finished, going to check against smallestdifference." << std::endl;
                std::cout << "left is " << left << ", mid is " << mid << " and right is " << right << std::endl;
                if(abs(nums.at(left) + nums.at(mid) + nums.at(right) - target) < smallestDifference){
                    std::cout << "Checking against smallestdifference" << std::endl;
                    smallestDifference = abs(nums.at(left) + nums.at(right) + nums.at(mid) - target); 
                    smallestDifferenceSum = nums.at(left) + nums.at(mid) + nums.at(right);
                }
            } 
            else{
                for(mid = right - 1; nums.at(left) + nums.at(mid) + nums.at(right) - target < 0 && mid > left + 1; --mid);
                std::cout << "One pass through array finished, going to check against smallestdifference." << std::endl;
                std::cout << "left is " << left << ", mid is " << mid << " and right is " << right << std::endl;
                if(abs(nums.at(left) + nums.at(mid) + nums.at(right) - target) < smallestDifference){
                    std::cout << "Checking against smallestdifference" << std::endl;
                    smallestDifference = abs(nums.at(left) + nums.at(right) + nums.at(mid) - target); 
                    smallestDifferenceSum = nums.at(left) + nums.at(mid) + nums.at(right);
                }
            }
            if(nums.at(left) + nums.at(mid) + nums.at(right) - target > 0){
                std::cout << "Sum is negative. Decrementing left." << std::endl;
                ++left; 
            }
            if(nums.at(left) + nums.at(right) + nums.at(mid) - target < 0){
                --right;
                std::cout << "Sum is positive. Incrementing right." << std::endl;
            }
            else{
                return smallestDifferenceSum;
                std::cout << "Sum is zero. Returning." << std::endl;
            }
        }
        std::cout << "Exited outermost while loop" << std::endl;
        return smallestDifferenceSum;
    }
};
