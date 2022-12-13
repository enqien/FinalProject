#include <iostream>
#include "utils.h"
#include "Graph.h"
#include "prerequisites.h"

#include <vector>
#include <string>
#include <sstream>
int main() {
    // backgournd implementation
    Image background; 
    background.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/background.png");
    
    int width = 8000;
    int height = 600;
    background.resize(width,height);
    Output output(background,200);
    

    prerequisites p = prerequisites();
    // std::vector<std::vector<std::string>> file_vec = p.file_to_vector("/workspaces/release-f22/FinalProject/prerequisites-dataset-master/uiuc-prerequisites.csv");
    // for (unsigned int i = 0; i < file_vec.size(); ++i) {
    //     for (unsigned int j = 0; j < file_vec.at(i).size(); ++j) {
    //         std::cout << to_input.at(j);
    //     }
    //     std::cout << "\n" << std::endl;
    // }
    // p.graph.savePNG("/workspaces/release-f22/FinalProject/IMG_1247.png");
    std::string total;
    std::string input;
    std::string target;
   
    std::cout << "Please enter the intended course and the courses taken already: ";
    std::cin >> total;
    bool visited = false;
    std::string intend = "";
    
    for (unsigned int i = 0; i < total.size(); i++) {
        if (visited == false) {
            if (total[i] == ',') {
                visited = true;
            } else {
                intend += total[i];
            }
        }
    }
    target = intend;
    
  
    total.erase(0, target.size() + 1);
    input = total;
    std::vector<std::string> vec;
    std::vector<std::string> splited;
    
    
    std::stringstream s_stream(input);
    while (s_stream.good()) {
        std::string substring;
        getline(s_stream, substring, ',');
        splited.push_back(substring);
    }
    /*std::cout << splited.size();
    for (unsigned int i = 0; i < splited.size(); i++) {
        std::cout << splited.at(i);
    }*/
    for (unsigned int i = 0; i < splited.size(); i++) {
         std::string input2 = splited.at(i);
         
         std::vector<std::string> output = p.get_shortest_path(target, input2);
         
        
         unsigned int size = output.size();
         if (output.at(0) != "-1") {
            for (unsigned int j = 0; j < size; j++) {
                vec.push_back(p.get_shortest_path(target, input2).at(j));
            }
         }
    }
    if (vec.size() == 0) {
        std::cout << "The courses that you've taken are not prerequisites of your intended course." << std::endl;
    } else {
        for (unsigned int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i) << std::endl;
        }
    }
    output.add_all(vec, output, target);
    
    
    const int classes_gap = 1000;
    const int letters_width = 1000;
    unsigned int count = 0;
    for (unsigned int i = 0; i < vec.size(); i++) {
        if (vec.at(i) == target) {
            count++;
        }
    }

    Image image;
    
    unsigned int height_occupied = 25;
    for (unsigned int i = 0; i < count; ++i) {
        std::vector<std::string> to_input;
        unsigned int vertical_gap_each_course =  (height - 50) * (0.5 / (count + ((count - 1) * 0.5)));
        for (unsigned int x = 0 ; x < vec.size();x++) {
            if (vec.at(i) != target) {
                to_input.push_back(vec.at(i));
            } else {
                vec.erase(vec.begin(), vec.begin() + x);
                break;
            }
        }
        unsigned int width_occupied = 50;
        unsigned int horizontal_gap_each_course =  (width - 100) * (0.5 / (to_input.size() + ((to_input.size() - 1) * 0.5))); 
        for (unsigned int j = 0; j < to_input.size(); ++j) {
            for (unsigned int a = 0; a < to_input.at(j).size(); a++ ) {
                std::cout << to_input.at(i).at(j);
            unsigned int horizontal_gap_each_character = horizontal_gap_each_course * 2 / (to_input.at(j).size() * 2 - 1);
            if (to_input.at(j).at(a)== '0')  {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/0.png"); 
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
            } else if (to_input.at(j).at(a)== '1') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/1.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
            } else if (to_input.at(j).at(a)== '2') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/2.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
            } else if (to_input.at(j).at(a)== '3') {
                image.readFromFile( "/workspaces/cs 225/release-f22/FinalProject copy/letter collection/3.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== '4') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/4.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== '5') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/5.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== '6') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/6.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== '7') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/7.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
               
            } else if (to_input.at(j).at(a)== '8') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/8.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== '9') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/9.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'A') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/A.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'B') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/B.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'C') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/C.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'D') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/D.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'E') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/E.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'F') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/F.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'G') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/G.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'H') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/H.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'I') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/I.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'J') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/J.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'K') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/K.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'L') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/L.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
               
            } else if (to_input.at(j).at(a)== 'M') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/M.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'N') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/N.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'O') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/O.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'P') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/P.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'Q') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/Q.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'R') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/R.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'S') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/S.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'T') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/T.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'U') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/U.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'V') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/V.png");
               image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'W') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/W.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
               
            } else if (to_input.at(j).at(a)== 'X') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/X.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'Y') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/Y.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
                
            } else if (to_input.at(j).at(a)== 'Z') {
                image.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/Z.png");
                image.resize(horizontal_gap_each_character, vertical_gap_each_course * 2);
                output.addSticker(image, width_occupied + horizontal_gap_each_character, height_occupied);
                width_occupied +=  2 * horizontal_gap_each_character;
                
               
            } 
            }
        }
        height_occupied += 3 * vertical_gap_each_course;
    }
    output.render().writeToFile("../myImage.png");
}
