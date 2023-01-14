#include "From.hpp"

From::From() : _name("Scv"), _signed(false), _grade_sign(40), _grade_exec(20)
{
    std::cout << "[From] Default name [Scv] constructor called." << std::endl;
}

From::From(const std::string& name, int _grade_sign, int _grade_exec) : _name(name), _grade_sign(_grade_sign), _grade_exec(_grade_exec)
{

}

From::From(const From& src) : _name(src._name), _signed(src._signed), _grade_sign(src._grade_sign), _grade_exec(src._grade_exec)
{

}

From::From& From::operator=(const From& src)
{
}

From::~From()
{

}

void    From::beSinged(Bureaucrat& src)
{

}

const std::string&    From::getName(void) const
{

}

bool    From::getSign(void) const
{

}

int From::getGradeSign(void) const
{

}

int From::getGradeExec(void) const
{

}

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat &src)
{

}

const char	*From::GradeTooHighException::what(void) const throw()
{
    return ("can no longer upper Bureaucrat grade.\n");
}

const char	*From::GradeTooLowException::what(void) const throw()
{
    return ("can no longer lower Bureaucracy grade.\n");
}
