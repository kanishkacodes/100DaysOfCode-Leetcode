class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        //Starting with the initial node 1, add each connected node who hasn't been visited yet to the queue.
        //Since we only add connected nodes, any node within our queue will have the same minimum disdtance of a 
        //road in its path as any other node who has been added to the queue. Knowing this, keep track of a single
        //minimum value which we will return once we iterate through all of the elements in the queue since
        //that will let us know that we have checked all roads between all elements which are connected to 1 and n

        std::unordered_set<int> visitSet;
        //Make an adjacency list with each node and who it's connected to and the distances from that node.
        std::unordered_map<int, std::unordered_map<int, int>> srcToDestToDist;
        int returnVal = INT_MAX;

        for(const auto& road : roads)
        {
            srcToDestToDist[road[0]][road[1]] = srcToDestToDist[road[1]][road[0]] = road[2];
        }

        visitSet.emplace(1);

        std::queue<int> roadQ;
        roadQ.emplace(1);
        while(roadQ.empty() == false)
        {
            int src = roadQ.front();
            roadQ.pop();

            for(auto& [dest, dist] : srcToDestToDist[src])
            {
                returnVal = std::min(returnVal, dist);

                if(visitSet.count(dest) == 0)
                {
                    roadQ.emplace(dest);
                    visitSet.emplace(dest);
                }
            }
        }

        return returnVal;
    }
};