//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<bool>cycle;
  bool dfs(vector<int> adj[],int sr,vector<bool>&visited,vector<bool>&pathvisited){
        visited[sr]=true;
        pathvisited[sr]=true;
        for(auto it:adj[sr]){
            if(!visited[it]){
                if(dfs(adj,it,visited,pathvisited)){
                    return true;
                }
            }
            else if(visited[it]&&pathvisited[it]){
                return true;
            }
        }
        pathvisited[sr]=false;
        cycle[sr]=true;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>ans;
        cycle.resize(V,false);
        vector<bool>visited(V,false);
        vector<bool>pathvisited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj,i,visited,pathvisited);
            }
        }
        for(int i=0;i<V;i++){
            if(cycle[i])ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends