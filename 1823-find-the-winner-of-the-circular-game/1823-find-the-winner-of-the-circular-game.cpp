class Solution {
public:

// 0:- means alive
// 1:- means dead

    int winner(vector<int> &person, int index, int n, int k, int person_alive){

            if(person_alive == 1){

                for(int i=0;i<n;i++){
                    if(person[i] == 0){     
                        return i;
                    }
                }
            }

            int kill = (k-1)%person_alive;   // finding the position of person which we want to kill 

            while(kill)
            {
                index = (index+1)%n;    // move the index to that position 

                while(person[index] == 1){
                    index = (index+1)%n;
                }

                kill--;
            }

            person[index] = 1;    // when find the postion , kill the person

            while(person[index] ==1){
                index = (index+1)%n;    // now find out the next alive person
            } 

           return  winner(person, index, n, k, person_alive - 1);   // now again start this call 
    }



    int findTheWinner(int n, int k) {
        
        vector<int> person(n,0);
        int index = 0;

        return winner(person,index,n,k,n /*person alive*/) + 1;   // starting mai toh saare person alive hai isliya "n" pass kiya

    }
};