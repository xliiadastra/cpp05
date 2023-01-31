#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Scv"), _signed(false), _grade_sign(40), _grade_exec(20)
{
    std::cout << "[Form] Default name [Scv] constructor called." << std::endl;
}

Form::Form(const std::string& name, int _grade_sign, int _grade_exec)
: _name(name), _signed(false), _grade_sign(_grade_sign), _grade_exec(_grade_exec)
{
    std::cout << "[Form] constructor called." << std::endl;
    if (_grade_sign < highestGrade || _grade_exec < highestGrade)
        throw (GradeTooHighException());
    if (_grade_sign > lowestGrade || _grade_exec > lowestGrade)
        throw (GradeTooLowException());
}

Form::Form(const Form& src)
: _name(src.getName()), _signed(src.getSign()), _grade_sign(src.getGradeSign()), _grade_exec(src.getGradeExec())
{
    std::cout << "[Form] Copy constructor called." << std::endl;
//    *this = src;
}

Form& Form::operator=(const Form& src)
{
    std::cout << "[Form] Copy assignment operator called\n";
//	*const_cast<std::string*>(&_name) = src.getName();
	if (this != &src)
        _signed = src.getSign();
//	*const_cast<int*>(&_grade_sign) = src.getGradeSign();
//	*const_cast<int*>(&_grade_exec) = src.getGradeExec();
	return (*this);
}

Form::~Form()
{
	std::cout << "[Form] Destructor called" << std::endl;
}

void    Form::beSinged(Bureaucrat& src)
{
    if (src.getGrade() <= this->getGradeSign())
    {
        _signed = true;
		std::cout << this->getName() << " got signed." << std::endl;        
    }
    else
        throw (GradeTooLowException());
}

const std::string&    Form::getName(void) const
{
    return (_name);
}

bool    Form::getSign(void) const
{
    return (_signed);
}

int Form::getGradeSign(void) const
{
    return (_grade_sign);
}

int Form::getGradeExec(void) const
{
    return (_grade_exec);
}

std::ostream& operator<<(std::ostream& outputStream, const Form& src)
{
	outputStream << src.getName() << ", required grade to sign is " << src.getGradeSign()
	<< ", required grade to execute is " << src.getGradeExec() << " and signed: " << std::boolalpha << src.getSign() << ".\n";
	return (outputStream);
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
    return ("can no longer upper Bureaucrat grade.\n");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
    return ("can no longer lower Bureaucracy grade.\n");
}
