//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n=heights.size(),m=heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,         greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>>distance(n,vector<int>(m,1e9));
        pq.push({0,{0,0}});
        distance[0][0]=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!pq.empty()){
            auto front=pq.top();
            int dist=front.first;
            int r=front.second.first;
            int c=front.second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int newr=r+drow[i];
                int newc=c+dcol[i];
                if(newr<n&&newr>=0&&newc<m&&newc>=0&&max(abs(heights[r][c]-heights[newr][newc]),distance[r][c])<distance[newr][newc]){
                    int pathdiff=max(abs(heights[r][c]-heights[newr][newc]),distance[r][c]);
                    distance[newr][newc]=pathdiff;
                    pq.push({pathdiff,{newr,newc}});
                }
            }
        }
        return distance[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends