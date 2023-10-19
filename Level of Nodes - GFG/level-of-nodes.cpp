//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
int nodeLevel(int V, vector<int> adj[], int X) {
    // code here
    queue<pair<int, int>> q1;
    q1.push({0, 0});
    vector<bool> visited(V, false);
    visited[0] = true;

    while (!q1.empty()) {
        pair<int, int> front = q1.front();
        q1.pop();

        if (front.first == X) {
            return front.second;
        }

        for (auto it : adj[front.first]) {
            if (!visited[it]) {
                q1.push({it, front.second + 1});
                visited[it] = true;
            }
        }
    }

    return -1;
}

};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends