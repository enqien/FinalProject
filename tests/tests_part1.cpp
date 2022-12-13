#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "prerequisites.h"
//#include "tests_util.h"

TEST_CASE("prerequisites contructor Test vertex", "[weight=5]") {
    prerequisites p = prerequisites();
    bool answer = p.graph.vertexExists("CS 225");
    REQUIRE(answer == true);

    answer = p.graph.vertexExists("CS 125");
    REQUIRE(answer == true);

    answer = p.graph.vertexExists("MATH 241");
    REQUIRE(answer == true);

    answer = p.graph.vertexExists("MATH 347");
    REQUIRE(answer == true);

    answer = p.graph.vertexExists("aefg");
    REQUIRE(answer == false);
}

TEST_CASE("prerequisites contructor Test edge", "[weight=5]") {
    prerequisites p = prerequisites();
    bool answer = p.graph.edgeExists("CS 225", "CS 125");
    REQUIRE(answer == true);

    answer = p.graph.edgeExists("MATH 525", "MATH 417");
    REQUIRE(answer == true);

    answer = p.graph.edgeExists("MATH 417", "MATH 525");
    REQUIRE(answer == false);

    answer = p.graph.edgeExists("CS 125", "CS 225");
    REQUIRE(answer == false);
}

TEST_CASE("prerequisites contructor Test adjacent", "[weight=5]") {
    prerequisites p = prerequisites();
    std::vector<std::string> answer = p.graph.getAdjacent("CS 225");
    bool correct = true;
    std::vector<std::string> correct_answer = {"CS 173", "ECE 220", "CS 125"};
    for (unsigned int i = 1; i < answer.size(); i++) {
        if (answer.at(i) != correct_answer.at(i - 1)) {
            correct = false;
            break;
        }
    }
    REQUIRE(correct);
}



TEST_CASE("dijkstra's shortest path algorithm", "[weight=5]") {
    prerequisites p = prerequisites();
    std::vector<std::string> answer = p.get_shortest_path("CS 241", "CS 125");
    bool correct = true;
    std::vector<std::string> correct_answer = {"CS 125", "CS 225", "CS 241"};
    for (unsigned int i = 0; i < answer.size(); i++) {
        if (answer.at(i) != correct_answer.at(i)) {
            correct = false;
            break;
        }
    }
    REQUIRE(correct);
}

/*
TEST_CASE("bfs", "[weight=5]") {
    prerequisites p = prerequisites();
    std::set<string> s = p.bf_search("CS 374");
    bool correct = true;
    std::vector<std::string> correct_answer = {"CS 125", "CS 225", "CS 241"};
    std::vector<std::string> answer;
    for (auto itr : s)
    {
        answer.push_back(itr);
    }
    for (unsigned int i = 0; i < answer.size(); i++) {
        if (answer.at(i) != correct_answer.at(i)) {
            std::cout << answer.at(i) << 
            correct = false;
            break;
        }
    }
    REQUIRE(correct);
}
*/