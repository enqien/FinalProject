#include "prerequisites.h"

prerequisites::prerequisites() {
    std::vector<std::vector<std::string>> file_vec = file_to_vector("/workspaces/cs225/release-f22/FinalProject copy/prerequisites-dataset-master/uiuc-prerequisites.csv");
    std::vector<std::vector<std::string>> file_vec2 = file_to_vector("/workspaces/cs225/release-f22/FinalProject copy/prerequisites-dataset-master/2019-fa.csv");
    construct_graph(file_vec, file_vec2);
}
std::vector<std::vector<std::string>> prerequisites::file_to_vector(const std::string & filename){
    // Your code here!
    std::vector<std::vector<std::string>> to_return;
    std::vector<std::string> first;
    std::string converted_string = file_to_string(filename);
    std::vector<std::string> rows;
    int rows_size = SplitString(converted_string, '\n', rows);
    for (int i = 0; i < rows_size; ++i) {
        first.clear();
        std::vector<std::string> elements_vector;
        int elements_size = SplitString(Trim(rows.at(i)), ',', elements_vector);
        for (int j = 0; j < elements_size; ++j) {
            std::string elements = Trim(elements_vector.at(j));
            first.push_back(elements);
        }
        to_return.push_back(first);
    }
    return to_return;
}

void prerequisites::construct_graph(std::vector<std::vector<std::string>> file_vec, std::vector<std::vector<std::string>> file_vec2) {
    graph = Graph(true, true);
    for (unsigned int i = 0; i < file_vec.size(); ++i) {
        graph.insertVertex(file_vec.at(i).at(0));
        for (unsigned int j = 2; j < file_vec.at(i).size(); ++j) {
            graph.insertEdge(file_vec.at(i).at(0), file_vec.at(i).at(j));
            //std::cout << graph.edgeExists(file_vec.at(i).at(0), file_vec.at(i).at(j)) << std::endl;
        }
    }


    //std::cout << "1" << std::endl;
    /*
    for (unsigned int i = 0; i < file_vec2.size(); i++) {
        std::string course_name = file_vec2.at(i).at(3) + " " + file_vec2.at(i).at(4);
        std::vector<std::string> adjacent = graph.getAdjacent(course_name);
        //std::cout << "course name: " << course_name << std::endl;
        for (unsigned int j = 0; j < adjacent.size(); j++) {
            //std::cout << "adjacent: " << adjacent.at(j) << std::endl;
            if (file_vec2.at(i).at(7).size() == 0) {
                graph.setEdgeWeight(course_name, adjacent.at(j), 0);
            } else {
                graph.setEdgeWeight(course_name, adjacent.at(j), file_vec2.at(i).at(6).at(0) - '0');
            }
        }

    }
    */
    
    //std::cout << "2" << std::endl;
}

std::vector<std::string> prerequisites::get_shortest_path(std::string source, std::string destination) {
    std::map<std::string, std::string> previous_map;
    std::map<std::string, int> distance_map;
    distance_map.insert({source, 0});
    std::queue<std::string> que;
    std::set<std::string> visited;

    que.push(source);
    while (que.front() != destination) {
        std::string current = que.front();
        que.pop();
        std::vector<std::string> neighbors = graph.getAdjacent(current);
        for (unsigned int i = 0; i < neighbors.size(); i ++) {
            if (visited.find(neighbors.at(i)) == visited.end()) {
                que.push(neighbors.at(i));
            }
            if (visited.find(neighbors.at(i)) == visited.end() && (distance_map.find(neighbors.at(i)) == distance_map.end() || distance_map.at(neighbors.at(i)) > graph.getEdgeWeight(current, neighbors.at(i)) + distance_map.at(current))) {
                previous_map.insert({neighbors.at(i), current});
                distance_map.insert({neighbors.at(i), graph.getEdgeWeight(current, neighbors.at(i)) + distance_map.at(current)});
            }
        }
        visited.insert(current);
        if (que.empty()) {
            std::cout << "the two courses have no relation" << std::endl;
            return {"-1"};
        }
    }

    std::vector<std::string> to_return;
    std::string current = destination;
    to_return.push_back(destination);
    while (current != source) {
        to_return.push_back(previous_map.at(current));
        current = previous_map.at(current);
    }
    return to_return;
}

std::set<std::string> prerequisites::bf_search(std::string input) {
    std::set<std::string> visited; 
    std::queue<std::string> que;

    que.push(input);
    visited.insert(input);
    while(!que.empty()) {
        std::string curr = que.front();
        que.pop();
        //std::cout << "curr: " << curr << std::endl;
        //std::cout << "size " << graph.getAdjacent(curr).size() << std::endl;
        for (unsigned int i = 0; i < graph.getAdjacent(curr).size(); i++) {
            //std::cout << "prereq " << graph.getAdjacent(curr).at(i) << std::endl;
            if (visited.find(graph.getAdjacent(curr).at(i)) == visited.end()) {
                que.push(graph.getAdjacent(curr).at(i));
                visited.insert(graph.getAdjacent(curr).at(i));
            }
        }
        
    }
    visited.erase(input);
    return visited;
}