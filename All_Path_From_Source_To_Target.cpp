class Solution {
private:
       // Global Declear variable
    vector<vector<int>> res;
public:
    
    void DFS(vector<vector<int>>& graph, vector<int>& current_path, int current_node, int destination){
        if(current_node==destination){    // Base Case
            current_path.push_back(destination);
            res.push_back(current_path);
            current_path.pop_back();   // Backtracking
            return;
        }
        current_path.push_back(current_node);
        for(auto i: graph[current_node]){
            DFS(graph,current_path,i,destination);
        }
        current_path.pop_back(); // backtracking
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> v;
        DFS(graph, v, 0, graph.size()-1);
        return res;
    }
};
