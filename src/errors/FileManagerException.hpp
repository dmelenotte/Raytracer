#ifndef __FILE_MANAGER_EXCEPTION__
    #define __FILE_MANAGER_EXCEPTION__

#include <exception>
#include <string>

class FileManagerException : public std::exception {
    public:
        FileManagerException() = default;
        FileManagerException(const std::string &msgError) noexcept : _msgError(msgError) {}
        ~FileManagerException() = default;
        const char *what() const noexcept {return _msgError.c_str();}
    private:
        std::string _msgError;
};

#endif
