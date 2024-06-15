class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();

        // if any project can't be completeed with initial capital
        if(w<*min_element(capital.begin(),capital.end())) return 0;

        multiset<pair<int,int>> st;

        for(int i=0;i<n;i++){
            st.insert({profits[i],capital[i]});
        }

        int ans=w;

        // can only do atmax n projects
        if(k>n) k=n;

        while(k){
            // multiset is increasing sorted so max profit will be from last
            for(auto i=st.end();i!=st.begin();){
                i--;
                // if we can do project with given capital we add profit to ans and capital
                // then delete it so thatb it is not selected again
                if(i->second<=w){ 
                    ans+=i->first;
                    w+=i->first;
                    k--;

                    st.erase(i);
                    break;
                }

                // if no project can be done with capital then return ans
                if(i==st.begin()) return ans; 
            }
        }

        return ans;
    }
};