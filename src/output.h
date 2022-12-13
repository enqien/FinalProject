#include "Image.h"
#include <iostream>
#include <vector>
class Output {
    public:
        Output(const Image &picture, unsigned max);
        ~Output();
        Output(const Output &other);
        const Output& operator= (const Output &other);
        void changeMaxStickers(unsigned max);
        int addSticker(Image &sticker, unsigned x, unsigned y);
        bool translate(unsigned index, unsigned x, unsigned y);
        void removeSticker(unsigned index);
        Image* getSticker(unsigned index);
        Image render() const;
        unsigned int test();
        void add_all(std::vector<std::string> vec, Output& background, std::string target);

    private:
        Image* base_image_;
        std::vector<Image*> stickers_;
        std::vector<std::pair<int, int>> coordinates_;
        unsigned int max_;
};