#include "FileManager.hpp"

#include "../errors/FileManagerException.hpp"

#include <fstream>

FileManager::FileManager(const std::string &extension) : _extension(extension) {}

FileManager::FileManager(const std::filesystem::path &filePath, const std::string &extension) :
    _filePath(filePath), _extension(extension) {}

void FileManager::read(const std::string &extension)
{
    _extension = extension;
    if (_filePath.empty()) {
        throw FileManagerException("-E- >> Cannot open file without file path.");
    }
    if (!_extension.empty()) {
        if (_extension.at(0) != '.' || _extension.length() < 2) {
            throw FileManagerException("-E- >> Extension '" + _extension + "' not valid.");
        }
        if (!_filePath.has_extension() || _filePath.extension() != _extension) {
            throw FileManagerException("-E- >> Extension '" + _extension + "' no match with the file path.");
        }
    }
    std::ifstream file;
    file.open(_filePath.c_str());
    if (!file.is_open()) {
        throw FileManagerException("-E- >> Failed to open file. Invalid file path or no goods rights.");
    }
    std::ostringstream fileStream;
    fileStream << file.rdbuf();
    _content = fileStream.str();
    file.close();
}

void FileManager::read(const std::filesystem::path &filePath)
{
    _filePath = filePath;
    if (_filePath.empty()) {
        throw FileManagerException("-E- >> Cannot open file without file path.");
    }
    if (!_extension.empty()) {
        if (_extension.at(0) != '.' || _extension.length() < 2) {
            throw FileManagerException("-E- >> Extension '" + _extension + "' not valid.");
        }
        if (!_filePath.has_extension() || _filePath.extension() != _extension) {
            throw FileManagerException("-E- >> Extension '" + _extension + "' no match with the file path.");
        }
    }
    std::ifstream file;
    file.open(_filePath.c_str());
    if (!file.is_open()) {
        throw FileManagerException("-E- >> Failed to open file. Invalid file path or no goods rights.");
    }
    std::ostringstream fileStream;
    fileStream << file.rdbuf();
    _content = fileStream.str();
    file.close();
}

void FileManager::read(const std::filesystem::path &filePath, const std::string &extension)
{
    _filePath = filePath;
    _extension = extension;
    if (_filePath.empty()) {
        throw FileManagerException("-E- >> Cannot open file without file path.");
    }
    if (!_extension.empty()) {
        if (_extension.at(0) != '.' || _extension.length() < 2) {
            throw FileManagerException("-E- >> Extension '" + _extension + "' not valid.");
        }
        if (!_filePath.has_extension() || _filePath.extension() != _extension) {
            throw FileManagerException("-E- >> Extension '" + _extension + "' no match with the file path.");
        }
    }
    std::ifstream file;
    file.open(_filePath.c_str());
    if (!file.is_open()) {
        throw FileManagerException("-E- >> Failed to open file. Invalid file path or no goods rights.");
    }
    std::ostringstream fileStream;
    fileStream << file.rdbuf();
    _content = fileStream.str();
    file.close();
}

void FileManager::read()
{
    if (_filePath.empty()) {
        throw FileManagerException("-E- >> Cannot open file without file path.");
    }
    if (!_extension.empty()) {
        if (_extension.at(0) != '.' || _extension.length() < 2) {
            throw FileManagerException("-E- >> Extension '" + _extension + "' not valid.");
        }
        if (!_filePath.has_extension() || _filePath.extension() != _extension) {
            throw FileManagerException("-E- >> Extension '" + _extension + "' no match with the file path.");
        }
    }
    std::ifstream file;
    file.open(_filePath.c_str());
    if (!file.is_open()) {
        throw FileManagerException("-E- >> Failed to open file. Invalid file path or no goods rights.");
    }
    std::ostringstream fileStream;
    fileStream << file.rdbuf();
    _content = fileStream.str();
    file.close();
}

const std::string &FileManager::getContent() const
{
    return _content;
}
