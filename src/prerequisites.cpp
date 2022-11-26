#include "prerequisites.h"

std::vector file_to_vector(const std::string & filename){
    // Your code here!
    std::vector to_return;
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