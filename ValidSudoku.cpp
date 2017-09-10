class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<char> nums = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        //evaluate rows
        for(auto row = board.begin(); row != board.end(); ++row){
            std::vector<char> temp = nums;
            for(auto element = row -> begin(); element != row -> end(); ++element){
                for(auto num = temp.begin(); num != temp.end(); ++num){
                    if(*element == *num){
                        num = temp.erase(num);
                    } 
                }
            }
            if(temp.size() != 0){
                return false; 
            }
        } 
        //evaluate columns
        for(int col = int(); col < 9; ++col){
            std::vector<char> temp = nums;
            for(auto row = board.begin(); row != board.end(); ++row){
                for(auto num = temp.begin(); num != temp.end(); ++num){
                    if(row -> at(col) == *num){
                        num = temp.erase(num); 
                    } 
                }
            }
            if(temp.size() != 0){
                return false; 
            }
        }
        //evaluate row of squares
            //evaluate square (column)
                //evaluate row inside square
                    //evaluate element inside square
                        //iterate through elements in temp, match to current element in square
        for(int squareRow = int(); squareRow < 3; ++squareRow){
            for(int square = int(); square < 3; ++square){
                std::vector<char> temp = nums;
                for(int row = int(); row < 3 + 3 * squareRow; ++row){
                    for(int element = int(); element < 3 + 3 * square; ++element){
                        for(auto num = temp.begin(); num != temp.end(); ++num){
                            if(*num == board.at(row).at(element)){
                                num = temp.erase(num); 
                            } 
                        }
                    } 
                } 
                if(temp.size() != 0){
                    return false; 
                }
            } 
        }
    }
};
