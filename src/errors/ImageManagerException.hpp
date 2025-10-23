#ifndef __IMAGE_MANAGER_EXCEPTION__
    #define __IMAGE_MANAGER_EXCEPTION__

#include <exception>
#include <string>

class ImageManagerException : public std::exception {
    public:
        ImageManagerException() = default;
        ImageManagerException(const std::string &msgError) noexcept : _msgError(msgError) {}
        ~ImageManagerException() = default;
        const char *what() const noexcept {return _msgError.c_str();}
    private:
        std::string _msgError;
};

#endif
