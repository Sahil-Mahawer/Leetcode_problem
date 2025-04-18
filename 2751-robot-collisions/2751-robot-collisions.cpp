class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        vector<int> dir;

        for(int i = 0; i < directions.size(); i++) {
            if(directions[i] == 'R') {
                dir.push_back(1);
            } else {
                dir.push_back(-1);
            }
        }

        int n = positions.size();

        vector<tuple<int,int,int,int>> robot;  // position, health, direction, index

        for(int i=0;i<n;i++){

            robot.push_back({positions[i], healths[i], dir[i], i});

        }
        sort(begin(robot), end(robot));


        stack<tuple<int, int, int>> st; // direction , health , index
        
        vector<int> final_health(n,0);
        vector<bool> alive(n,false);



        for(int i=0;i<n;i++){

            int pos = get<0>(robot[i]);
            int health = get<1>(robot[i]);
            int direction = get<2>(robot[i]);
            int idx = get<3>(robot[i]);

            if(direction == 1){
                st.push({direction, health, idx});
            }

            else{

                while(!st.empty()){

                    auto[d1, h1, i1] = st.top();

                    if(d1 == 1){  // direction -1 and jo stack ke top hai vo 1 ... so collision occurs 

                        if(h1 == health){
                            st.pop();
                            goto skip_push;
                        }

                        else if(h1 > health){
                           get<1>(st.top()) = h1 - 1 ;
                           goto skip_push;
                        }

                        else{  // health > h1 :- so simply do st.pop()
                            st.pop();
                            health--;
                        }

                    }

                    else{
                        break;
                    }  

                }

                st.push({direction, health, idx});
            }

            skip_push: ;
        }

        while(!st.empty()){

            auto[d,h,id] = st.top();

            final_health[id] = h;

            alive[id] = true;

            st.pop(); 
        }

        vector<int> ans;

        for(int i=0;i<n;i++){

            if(alive[i] == true){
                ans.push_back(final_health[i]);
            }
        }

        return ans;
    }
};
