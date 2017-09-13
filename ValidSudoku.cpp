class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board){
        //evaluate rows
        //go down rows 
        for(auto row = board.begin(); row != board.end(); ++row){
            std::unordered_map<char, int> numerals = std::unordered_map<char, int>();
            //visit each square (go across columns) 
            for(auto column = row -> begin(); column != row -> end(); ++column){
                if(numerals[*column] > 0 && *column != '.'){
                    return false; 
                }
                else{
                    ++numerals[*column]; 
                }
            }
        }

        //evaluate columns
        //go across columns
        for(int column = int(); column < board.at(0).size(); ++column){
            std::unordered_map<char, int> numerals = std::unordered_map<char, int>();
            for(auto row = board.begin(); row != board.end(); ++row){
                if(numerals[(*row).at(column)] > 0 && (*row).at(column) != '.'){
                    return false;
                }
                else{
                    ++numerals[(*row).at(column)]; 
                }
            } 
        }

        //evaluate 3 x 3 squares
        //select square
        //select square starting row
        for(int squareRow = int(); squareRow < 3; ++squareRow){
            //select square starting column  
            for(int squareCol = int(); squareCol < 3; ++squareCol){
                std::unordered_map<char, int> numerals = std::unordered_map<char, int>();
                for(auto row = board.begin() + 3 * squareRow; row != board.begin() + 3 * squareRow + 3; ++row){
                    for(auto column = row -> begin() + 3 * squareCol; column != row -> begin() + 3 * squareCol + 3; ++column){
                        if(numerals[*column] > 0 && *column != '.'){
                            return false; 
                        }
                        else{
                            ++numerals[*column]; 
                        }
                    } 
                }
            }
        }
        return true;
    }
};
