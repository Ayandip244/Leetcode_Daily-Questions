class Solution {
public:
    int countPartitions(vector<int>& a, int k) {
        int n=a.size(); long long M=1e9+7;
        vector<long long> d(n+1), p(n+2);
        d[0]=1; p[1]=1;
        deque<int> mx,mn;
        int L=0;
        for(int i=0;i<n;i++){
            while(!mx.empty()&&a[mx.back()]<=a[i]) mx.pop_back();
            mx.push_back(i);
            while(!mn.empty()&&a[mn.back()]>=a[i]) mn.pop_back();
            mn.push_back(i);
            while(a[mx.front()]-a[mn.front()]>k){
                if(mx.front()==L) mx.pop_front();
                if(mn.front()==L) mn.pop_front();
                L++;
            }
            long long w=(p[i+1]-p[L]+M)%M;
            d[i+1]=w;
            p[i+2]=(p[i+1]+w)%M;
        }
        return d[n];
    }
};
