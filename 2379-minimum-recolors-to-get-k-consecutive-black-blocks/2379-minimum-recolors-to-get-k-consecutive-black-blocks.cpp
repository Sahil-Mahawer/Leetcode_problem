class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int moves = 0;
        int count_black = 0;

        int min_moves = INT_MAX;

        int i = 0, j = 0;

        int n = blocks.size();

        
        while(j<n){
            
            if(blocks[j] == 'W'){
                moves++;
            }
            count_black++;

            while(count_black == k){

                min_moves = min(min_moves, moves);
                count_black--;

                if(blocks[i] == 'W'){
                    moves--;
                }
                i++;

            }
            j++;
        }

    return min_moves;
    }
};