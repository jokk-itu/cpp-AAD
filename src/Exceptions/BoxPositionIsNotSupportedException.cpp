#ifndef DATASTRUCTURES_LIB_BOXPOSITIONISNOTSUPPORTEDEXCEPTION
#define DATASTRUCTURES_LIB_BOXPOSITIONISNOTSUPPORTEDEXCEPTION

#include <exception>
#include <string>

class BoxPositionIsNotSupportedException : public std::exception
{
private:
    std::string message;

public:
    BoxPositionIsNotSupportedException()
    {
        message = "Box Position is not supported";
    }
    const char* what() const noexcept override
    {
        return message.c_str();
    }
};


#endif //DATASTRUCTURES_LIB_BOXPOSITIONISNOTSUPPORTEDEXCEPTION

