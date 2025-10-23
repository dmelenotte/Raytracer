#ifndef __GETTERS_EXCEPTION__
    #define __GETTERS_EXCEPTION__

#include <exception>
#include <string>

class GetterException : public std::exception {
    public:
        enum ErrorType {
            ERROR,
            WARNING
        };

        GetterException() = default;
        GetterException(const std::string &msgError, ErrorType errorType) noexcept :
            _msgError(msgError), _errorType(errorType) {}
        ~GetterException() = default;
        const char *what() const noexcept {return _msgError.c_str();}
        ErrorType getErrorType() const {return _errorType;}
    private:
        std::string _msgError;
        ErrorType _errorType;
};

#endif
