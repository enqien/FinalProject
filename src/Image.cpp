#include "Image.h"
#include <vector>
void Image::lighten() {
    for (unsigned i = 0; i < width(); i++) {
        for (unsigned j = 0; j < height(); j++) {
            
            if (getPixel(i, j).l  + 0.1 > 1.0) {
                getPixel(i, j).l = 1.0;
            } else {
                
                getPixel(i, j).l += 0.1;
        
            }
        }
    }
}
void Image::lighten(double amount) {
    for (unsigned int i = 0; i <  width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            
            if (getPixel(i, j).l  + amount > 1.0) {
                getPixel(i, j).l = 1.0;
            } else{
                getPixel(i, j).l += amount;
            }
        }
    }
}
void Image::darken() {
    for (unsigned int i = 0; i <  width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            if (getPixel(i, j).l  - 0.1 < 0) {
                getPixel(i, j).l = 0;
            } else{
                getPixel(i, j).l -= 0.1;
            }
        }
    }
}
void Image::darken(double amount) {
    for (unsigned int i = 0; i <  width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            if (getPixel(i, j).l  - amount < 0) {
                getPixel(i, j).l = 0;
            } else{
                getPixel(i, j).l -= amount;
            }
        }
    }
}
void Image::saturate() {
    for (unsigned int i = 0; i <  width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            if (getPixel(i, j).s  + 0.1 > 1.0) {
                continue;
            } else{
                getPixel(i, j).s += 0.1;
            }
        }
    }
}
void Image::saturate(double amount) {
    for (unsigned int i = 0; i <  width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            if (getPixel(i, j).s  + amount > 1.0) {
                continue;
            } else{
                getPixel(i, j).s += amount;
            }
        }
    }
}
void Image::desaturate() {
    for (unsigned int i = 0; i <  width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            if (getPixel(i, j).s  - 0.1 < 0) {
                continue;
            } else{
                getPixel(i, j).s -= 0.1;
            }
        }
    }
}
void Image::desaturate(double amount) {
    for (unsigned int i = 0; i <  width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            if (getPixel(i, j).s  - amount < 0) {
                continue;
            } else{
                getPixel(i, j).s -= amount;
            }
        }
    }
}
void Image::grayscale() {
    for (unsigned int i = 0; i < width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            getPixel(i, j).s = 0;
        }
    }
}
void Image::rotateColor(double degrees) {
    for (unsigned int i = 0; i < width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            if (getPixel(i, j).h + degrees > 360) {
                auto temp = getPixel(i, j).h;
                getPixel(i, j).h = degrees - (360 - temp);
            } else if (getPixel(i, j).h +degrees < 0) {
                auto temp = getPixel(i, j).h;
                getPixel(i, j).h = 360 + (degrees + temp);
            } else {
                getPixel(i, j).h += degrees;
            }
        }
    }
}
void Image::illinify() {
    for (unsigned int i = 0; i < width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            if (absolute(11, getPixel(i, j).h) < absolute(216, getPixel(i, j).h)) {
                getPixel(i, j).h = 11;
            } else {
                getPixel(i, j).h = 216;
            }
        }
    }
}
void Image::scale(double factor) {
    double new_height = height() * factor;
    double new_width = width() * factor;
    auto fill = cs225::HSLAPixel();
    std::vector<cs225::HSLAPixel> row(height(), fill);
    std::vector<std::vector<cs225::HSLAPixel>> temp(width(), row);
    for (unsigned int i = 0; i < width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            temp.at(i).at(j) = getPixel(i, j);
        }
    }
    resize(new_width, new_height);
    for (unsigned int i = 0; i < width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            getPixel(i, j) = temp.at(i/factor).at(j/factor);
        }
    }
}
void Image::scale(unsigned w, unsigned h) {
    double factor1 = 1.0 * w / width();
    double factor2 = 1.0 * h / height();
    if (factor1 < factor2) {
        scale(factor1);
    } else {
        scale(factor2);
    }
}

double Image::absolute(double d1, double d2) {
    double difference = d1 - d2;
    if (difference < 0) {
        return d2 - d1;
    } else {
        return difference;
    }
}

Image Image::letter_output(char letter) const{
    Image to_return;
    if (letter == '0')  {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/0.png");
    } else if (letter == '1') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/1.png");
    } else if (letter == '2') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/2.png");
    } else if (letter == '3') {
        to_return.readFromFile( "/workspaces/cs 225/release-f22/FinalProject copy/letter collection/3.png");
    } else if (letter == '4') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/4.png");
    } else if (letter == '5') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/5.png");
    } else if (letter == '6') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/6.png");
    } else if (letter == '7') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/7.png");
    } else if (letter == '8') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/8.png");
    } else if (letter == '9') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/9.png");
    } else if (letter == 'A') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/A.png");
    } else if (letter == 'B') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/B.png");
    } else if (letter == 'C') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/C.png");
    } else if (letter == 'D') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/D.png");
    } else if (letter == 'E') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/E.png");
    } else if (letter == 'F') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/F.png");
    } else if (letter == 'G') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/G.png");
    } else if (letter == 'H') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/H.png");
    } else if (letter == 'I') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/I.png");
    } else if (letter == 'J') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/J.png");
    } else if (letter == 'K') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/K.png");
    } else if (letter == 'L') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/L.png");
    } else if (letter == 'M') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/M.png");
    } else if (letter == 'N') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/N.png");
    } else if (letter == 'O') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/O.png");
    } else if (letter == 'P') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/P.png");
    } else if (letter == 'Q') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/Q.png");
    } else if (letter == 'R') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/R.png");
    } else if (letter == 'S') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/S.png");
    } else if (letter == 'T') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/T.png");
    } else if (letter == 'U') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/U.png");
    } else if (letter == 'V') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/V.png");
    } else if (letter == 'W') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/W.png");
    } else if (letter == 'X') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/X.png");
    } else if (letter == 'Y') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/Y.png");
    } else if (letter == 'Z') {
        to_return.readFromFile("/workspaces/cs 225/release-f22/FinalProject copy/letter collection/Z.png");
    } 
    return to_return;
 }