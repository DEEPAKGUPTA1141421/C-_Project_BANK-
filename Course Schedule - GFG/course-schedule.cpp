//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int numCourses, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<vector<int>>adj(numCourses);
      vector<int>indegree(numCourses,0);
	   for(int i=0;i<prerequisites.size();i++){
	       indegree[prerequisites[i][0]]++;
				 adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
	   }
	   queue<int>q1;
	   vector<int>ans;
	   vector<bool>visited(numCourses,false);
	   for(int i=0;i<numCourses;i++){
	       if(indegree[i]==0){
	           q1.push(i);
	           visited[i]=true;
	       }
	   }
	   while(q1.size()!=0){
	       int front=q1.front();
	       q1.pop();
	       ans.push_back(front);
	       for(auto it:adj[front]){
	           indegree[it]--;
	           if(!visited[it]&&indegree[it]==0){
	               q1.push(it);
	           }
	       }
	   }
	    if(ans.size()==numCourses){
            return ans;
        }
        else{
            vector<int>ans;
            return ans;
        }
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends