/**
 * @file schedule.cpp
 * Exam scheduling using graph coloring
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <set>
#include <utility>

#include "schedule.h"
#include "utils.h"
#include <algorithm>

/**
 * Given a filename to a CSV-formatted text file, create a 2D vector of strings where each row
 * in the text file is a row in the V2D and each comma-separated value is stripped of whitespace
 * and stored as its own string. 
 * 
 * Your V2D should match the exact structure of the input file -- so the first row, first column
 * in the original file should be the first row, first column of the V2D.
 *  
 * @param filename The filename of a CSV-formatted text file. 
 */
V2D file_to_V2D(const std::string & filename){
    // Your code here!
    V2D to_return;
    std::string content = file_to_string(filename);
    std::vector<std::string> rows;
    SplitString(content, '\n', rows);
    for (unsigned int i = 0; i < rows.size(); i++) {
        std::vector<std::string> row;
        SplitString(rows.at(i), ',', row);
        to_return.push_back(row);
    }
    for (unsigned int i = 0; i < to_return.size(); i++) {
        for (unsigned int j = 0; j < to_return.at(i).size(); j++) {
            to_return.at(i).at(j) = Trim(to_return.at(i).at(j));
        }
    }
    return to_return;

}

/**
 * Given a course roster and a list of students and their courses, 
 * perform data correction and return a course roster of valid students (and only non-empty courses).
 * 
 * A 'valid student' is a student who is both in the course roster and the student's own listing contains the course
 * A course which has no students (or all students have been removed for not being valid) should be removed
 * 
 * @param cv A 2D vector of strings where each row is a course ID followed by the students in the course
 * @param student A 2D vector of strings where each row is a student ID followed by the courses they are taking
 */
V2D clean(const V2D & cv, const V2D & student){
    // YOUR CODE HERE
    V2D to_return = cv;
    std::map<std::string, std::set<std::string>> stu_data;
    for (unsigned int i = 0; i < student.size(); i++) {
        std::set<std::string> set;
        for (unsigned int j = 1; j < student.at(i).size(); j++) {
            set.insert(student.at(i).at(j));
        }
        stu_data.insert({student.at(i).at(0), set});
    }

    for (unsigned int i = 0; i < to_return.size(); i++) {
        for (unsigned int j = 1; j < to_return.at(i).size(); j++) {
            if (stu_data.find(to_return.at(i).at(j)) == stu_data.end()) {
                to_return.at(i).erase(to_return.at(i).begin() + j);
                j--;
            } else if (stu_data.at(to_return.at(i).at(j)).find(to_return.at(i).at(0)) == stu_data.at(to_return.at(i).at(j)).end()) {
                to_return.at(i).erase(to_return.at(i).begin() + j);
                j--;   
            }

        }
        if (to_return.at(i).size() == 1) {
            to_return.erase(to_return.begin() + i);
            i--;
        }
    }
    return to_return;

}

/**
 * Given a collection of courses and a list of available times, create a valid scheduling (if possible).
 * 
 * A 'valid schedule' should assign each course to a timeslot in such a way that there are no conflicts for exams
 * In other words, two courses who share a student should not share an exam time.
 * Your solution should try to minimize the total number of timeslots but should not exceed the timeslots given.
 * 
 * The output V2D should have one row for each timeslot, even if that timeslot is not used.
 * 
 * As the problem is NP-complete, your first scheduling might not result in a valid match. Your solution should 
 * continue to attempt different schedulings until 1) a valid scheduling is found or 2) you have exhausted all possible
 * starting positions. If no match is possible, return a V2D with one row with the string '-1' as the only value. 
 * 
 * @param courses A 2D vector of strings where each row is a course ID followed by the students in the course
 * @param timeslots A vector of strings giving the total number of unique timeslots
 */
V2D schedule(const V2D &courses, const std::vector<std::string> &timeslots){
    // Your code here!
    std::vector<std::pair<std::string, int>> vertices;
    std::vector<std::vector<bool>> edges(courses.size(), std::vector<bool>(courses.size()));
    //std::map<std::string, std::pair<std::string, int>> graph;
    V2D to_return;

    for (unsigned int i = 0; i < timeslots.size(); i++) {
        to_return.push_back({timeslots.at(i)});
    }

    //populate the graph
    for (unsigned int i = 0; i < courses.size(); i++) {
        vertices.push_back({courses.at(i).at(0), 999});
        for (unsigned int j = i + 1; j < courses.size(); j++) {
            std::set<std::string> first(courses.at(i).begin() + 1, courses.at(i).end());
            std::set<std::string> second(courses.at(j).begin() + 1, courses.at(j).end());
            first.merge(second);
            if (second.size() != 0) {
                edges.at(i).at(j) = true;
                edges.at(j).at(i) = true;
            }
        }

    }
    int slots_num = timeslots.size();



    for (unsigned int i = 0; i < vertices.size(); i++) {
        std::vector<bool> colors(slots_num, true);
        for (unsigned int z = 0; z < edges.size(); z++) {
            if (edges.at(z).at(i) && vertices.at(z).second != 999) {
                colors.at(vertices.at(z).second) = false;
            }
        }
        for (unsigned int z = 0; z < colors.size(); z++) {
            if (colors.at(z)) {
                vertices.at(i).second = z;
                break;
            }
        }
        if (vertices.at(i).second == 999) {
            return {{"-1"}};
        }
    }

    for (unsigned int i = 0; i < vertices.size(); i++) {
        to_return.at(vertices.at(i).second).push_back(vertices.at(i).first);
    }
    
    return to_return;
}