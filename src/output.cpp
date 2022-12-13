#include "Output.h"

Output::Output (const Image &picture, unsigned max) {
    base_image_ = new Image(picture);
    stickers_ = std::vector<Image*>();
    coordinates_ = std::vector<std::pair<int, int>>();
    max_ = max;
}
Output::~Output () {
    delete base_image_;
    for (unsigned int i = 0; i < stickers_.size(); i++) {
        delete stickers_.at(i);
    }
}
 
Output::Output(const Output &other) {
    base_image_ = new Image(*other.base_image_);
    max_ = other.max_;
    stickers_ = std::vector<Image*>();
    coordinates_ = std::vector<std::pair<int, int>>();
    for (unsigned int i = 0; i < other.stickers_.size(); i++) {
        stickers_.push_back(new Image(*other.stickers_.at(i)));
        coordinates_.push_back(std::make_pair(other.coordinates_.at(i).first, other.coordinates_.at(i).second));
    }
}
 	        
const Output& Output::operator=(const Output &other) {
    delete base_image_;
    for (unsigned int i = 0; i < stickers_.size(); i++) {
        delete stickers_.at(i);
    }
    base_image_ = new Image(*other.base_image_);
    max_ = other.max_;
    stickers_ = std::vector<Image*>();
    coordinates_ = std::vector<std::pair<int, int>>();
    for (unsigned int i = 0; i < other.stickers_.size(); i++) {
        stickers_.push_back(new Image(*other.stickers_.at(i)));
        coordinates_.push_back(std::make_pair(other.coordinates_.at(i).first, other.coordinates_.at(i).second));
    }
    return *this;
}

void Output::changeMaxStickers (unsigned max) {
    if (max < stickers_.size()) {
        for (unsigned int i = max; i < stickers_.size(); i++) {
            delete stickers_.at(i);
        }
        stickers_.erase(stickers_.begin() + max, stickers_.begin() + stickers_.size());
        coordinates_.erase(coordinates_.begin() + max, coordinates_.begin() + coordinates_.size());
    }
    max_ = max;
}

int Output::addSticker (Image &sticker, unsigned x, unsigned y) {
    if(stickers_.size() + 1 > max_) {
        return -1;
    } else {
        stickers_.push_back(new Image(sticker));
        coordinates_.push_back(std::make_pair(x, y));
        return stickers_.size() - 1;
    }
}
 
bool Output::translate (unsigned index, unsigned x, unsigned y) {
    if (index >= stickers_.size()) {
        return false;
    } else {
        coordinates_.at(index).first = x;
        coordinates_.at(index).second = y;
        return true;
    }
    return true;
}
 
void Output::removeSticker (unsigned index) {
    delete stickers_.at(index);
   stickers_.erase(stickers_.begin() + index);
   coordinates_.erase(coordinates_.begin() + index);
}
 
Image* Output::getSticker (unsigned index) {
    if (index >= stickers_.size()) {
        return NULL;
    }
    return stickers_.at(index);
}

Image Output::render () const {
    Image to_return = Image(*base_image_);
    for(unsigned int i = 0; i < stickers_.size(); i++) {
        if (coordinates_.at(i).first + stickers_.at(i)->width() > to_return.width()) {
            to_return.resize(coordinates_.at(i).first + stickers_.at(i)->width(), to_return.height());
        }
        if (coordinates_.at(i).second + stickers_.at(i)->height() > to_return.height()) {
            to_return.resize(to_return.width(), coordinates_.at(i).second + stickers_.at(i)->height());
        }
        
    }


    for(unsigned int i = 0; i < stickers_.size(); i++) {
        for(unsigned int w = 0; w < stickers_.at(i)->width(); w++) {
            for(unsigned int h = 0; h < stickers_.at(i)->height(); h++) {
                if (stickers_.at(i)->getPixel(w, h).a != 0) {
                    to_return.getPixel(w + coordinates_.at(i).first, h + coordinates_.at(i).second) = stickers_.at(i)->getPixel(w, h);
                }
            }
            
        }
    }
    return to_return;
}
unsigned int Output::test() {
    return stickers_.size();
}

void Output::add_all(std::vector<std::string> vec, Output& background, std::string target) {
    int count = 0;
    for (unsigned int i = 0; i < vec.size(); i++) {
        if (vec.at(i) == target) {
            count++;
        }
    }
}