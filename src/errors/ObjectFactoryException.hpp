#ifndef __OBJECT_FACTORY_EXCEPTION__
    #define __OBJECT_FACTORY_EXCEPTION__

#include <exception>
#include <string>

class ObjectFactoryException : public std::exception {
    public:
        ObjectFactoryException() = default;
        ObjectFactoryException(const std::string &msgError) noexcept : _msgError(msgError) {}
        ~ObjectFactoryException() = default;
        const char *what() const noexcept {return _msgError.c_str();}
    private:
        std::string _msgError;
};

#endif
