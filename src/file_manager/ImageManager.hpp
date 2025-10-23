#ifndef __IMAGE_MANAGER__
    #define __IMAGE_MANAGER__

#include "../pixel_buffer/PixelBuffer.hpp"

#include <filesystem>
#include <string>

class ImageManager {
    public:
        ImageManager(const std::filesystem::path &imageFile);
        ~ImageManager() = default;
        void setFile(const std::filesystem::path &imageFile);
        void save(const PixelBuffer &buffer);
    private:
        std::filesystem::path _imageFile;
        std::string _extension = ".ppm";
};

#endif
