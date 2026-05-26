class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> mat(n + 1);
        for (auto edge : times) {
            mat[edge[0]].push_back({edge[1], edge[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            auto edge = pq.top();
            pq.pop();
            if (edge.first > dis[edge.second])
                continue;
            for (auto& next : mat[edge.second]) {
                int nex = next.first, wt = next.second;
                if (dis[edge.second] != INT_MAX &&
                    dis[edge.second] + wt < dis[nex]) {
                    dis[nex] = dis[edge.second] + wt;
                    pq.push({dis[nex], nex});
                }
            }
        }
        int maxi = *max_element(dis.begin()+1, dis.end());
        if (maxi == INT_MAX)
            return -1;
        return maxi;
    }
};