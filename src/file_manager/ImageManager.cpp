#include "ImageManager.hpp"

#include "../errors/ImageManagerException.hpp"

#include <fstream>

ImageManager::ImageManager(const std::filesystem::path &imageFile)
{
    if (imageFile.has_extension()) {
        if (imageFile.extension() != _extension) {
            throw ImageManagerException("-E- >> Cannot save image with '" +
                imageFile.extension().string() + "'. Only with '" + _extension + "'.");
        }
        _imageFile = imageFile;
    } else {
        _imageFile = imageFile;
        _imageFile += _extension;
    }
}

void ImageManager::setFile(const std::filesystem::path &imageFile)
{
    if (imageFile.has_extension()) {
        if (imageFile.extension() != _extension) {
            throw ImageManagerException("-E- >> Cannot save image with '" +
                imageFile.extension().string() + "'. Only with '" + _extension + "'.");
        }
    } else {
        _imageFile = imageFile;
        _imageFile += _extension;
    }
}

void ImageManager::save(const PixelBuffer &buffer)
{
    if (_imageFile.empty()) {
        throw ImageManagerException("-E- >> Impossible save image without filepath.");
    }
    std::ofstream file;
    file.open(_imageFile);
    if (!file.is_open()) {
        throw ImageManagerException("-E- >> Cannot open file to save image.");
    }
    if (buffer.getBuffer().empty()) {
        return;
    }
    file << "P3\n" << buffer.getBufferWidth() << " " << buffer.getBufferHeight() << "\n255\n";
    for (auto it = buffer.getBuffer().begin(); it != buffer.getBuffer().end(); ++it) {
        file << (int)(*it).get(Color::R) << " " << (int)(*it).get(Color::G) << " " <<
            " " << (int)(*it).get(Color::B) << "\n";
    }
    file.close();
}
