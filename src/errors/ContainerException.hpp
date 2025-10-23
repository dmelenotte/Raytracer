#ifndef __CONTAINER_EXCEPTION__
    #define __CONTAINER_EXCEPTION__

#include <exception>
#include <string>

class ContainerException : public std::exception {
    public:
        ContainerException() = default;
        ContainerException(const std::string &msgError) noexcept : _msgError(msgError) {}
        ~ContainerException() = default;
        const char *what() const noexcept {return _msgError.c_str();}
    private:
        std::string _msgError;
};

#endif
