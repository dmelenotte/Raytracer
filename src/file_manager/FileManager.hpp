#ifndef __FILE_MANAGER__
    #define __FILE_MANAGER__

#include <filesystem>
#include <string>

class FileManager {
    public:
        FileManager() = default;
        ~FileManager() = default;
        FileManager(const std::string &extension);
        FileManager(const std::filesystem::path &filePath, const std::string &extension);
        void read(const std::string &extension);
        void read(const std::filesystem::path &filePath);
        void read(const std::filesystem::path &filePath, const std::string &extension);
        void read();
        const std::string &getContent() const;
    private:
        std::filesystem::path _filePath;
        std::string _extension;
        std::string _content;
};

#endif
