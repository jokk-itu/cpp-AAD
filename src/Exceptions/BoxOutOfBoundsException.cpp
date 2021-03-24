#ifndef DATASTRUCTURES_LIB_BOXOUTOFBOUNDSEXCEPTION
#define DATASTRUCTURES_LIB_BOXOUTOFBOUNDSEXCEPTION

#include <exception>
#include <string>

class BoxOutOfBoundsException : public std::exception
{
private:
    std::string message;

public:
    BoxOutOfBoundsException()
    {
        message = "Box is out of range";
    }
    const char* what() const noexcept override
    {
        return message.c_str();
    }
};


#endif //DATASTRUCTURES_LIB_BOXOUTOFBOUNDSEXCEPTION
