#ifndef __JSON_PARSER_EXCEPTION__
    #define __JSON_PARSER_EXCEPTION__

#include <exception>
#include <string>

class JsonParserException : public std::exception {
    public:
        JsonParserException() = default;
        JsonParserException(const std::string &msgError) noexcept : _msgError(msgError) {}
        ~JsonParserException() = default;
        const char *what() const noexcept {return _msgError.c_str();}
    private:
        std::string _msgError;
};

#endif
