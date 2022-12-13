#include <vector>
#include <map>
#include "Graph.h"
#include "utils.h"
#include <set>
#include <queue>
#include "output.h"
class prerequisites {
    public:
        prerequisites();
        std::vector<std::vector<std::string>> file_to_vector(const std::string & filename);
        void construct_graph(std::vector<std::vector<std::string>> file_vec);
        std::vector<std::string> get_shortest_path(std::string source, std::string destination);
        std::set<std::string> bf_search(std::string input);
        Graph graph;
        
    private:

};
