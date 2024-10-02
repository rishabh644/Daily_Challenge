#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>&
equations,
vector<double>& values,
vector<vector<string>>& queries) {
        // Step 1: Build the graph from the equations
        unordered_map<string, unordered_map<string,
double>> graph;
        for (int i = 0; i < equations.size(); ++i) {
            string dividend = equations[i][0];
            string divisor = equations[i][1];
            double quotient = values[i];
            graph[dividend][divisor] = quotient;
            graph[divisor][dividend] = 1.0 / quotient;
        }

        // Step 2: Evaluate each query via backtracking (DFS)
        vector<double> results;
        for (const auto& query : queries) {
            string dividend = query[0];
            string divisor = query[1];
            if (graph.find(dividend) == graph.end()
 || graph.find(divisor) == graph.end()) {
                results.push_back(-1.0);
            } else if (dividend == divisor) {
                results.push_back(1.0);
            } else {
                unordered_set<string> visited;
                double result = backtrackEvaluate
           (graph, dividend, divisor, 1.0, visited);
                results.push_back(result);
            }
        }
        return results;
    }

private:
    double backtrackEvaluate(unordered_map<string,
 unordered_map<string, double>>& graph,
 string currNode, string targetNode,
 double accProduct,
 unordered_set<string>& visited) {
        // Mark the current node as visited
        visited.insert(currNode);

        // If the target node is a direct neighbor, return the result
        if (graph[currNode].find(targetNode) != graph[currNode].end()) {
            return accProduct * graph[currNode][targetNode];
        }

        // Explore neighbors using DFS
        for (const auto& neighbor : graph[currNode]) {
            if (visited.find(neighbor.first) != visited.end()) {
                continue;
            }
            double result = backtrackEvaluate(graph, neighbor.first, targetNode, accProduct * neighbor.second, visited);
            if (result != -1.0) {
                return result;
            }
        }

        // Unmark the visit for backtracking
        visited.erase(currNode);
        return -1.0;
    }
};

// Example usage:
int main() {
    Solution solution;

    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    vector<double> results = solution.calcEquation(equations, values, queries);

    for (double result : results) {
        cout << result << " ";
    }
    // Output: 6.0 0.5 -1.0 1.0 -1.0

    return 0;
}
