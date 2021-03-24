#include <exception>
#include <string>

class PointNotWithinBoxException : public std::exception
{
private:
    std::string message;

public:
    PointNotWithinBoxException()
    {
        message = "Point is out of range";
    }
    const char* what() const noexcept override
    {
        return message.c_str();
    }
};