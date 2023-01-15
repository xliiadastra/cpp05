#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Scv"), _signed(false), _grade_sign(40), _grade_exec(20)
{
    std::cout << "[AForm] Default name [Scv] constructor called." << std::endl;
}

AForm::AForm(const std::string& name, int _grade_sign, int _grade_exec)
: _name(name), _grade_sign(_grade_sign), _grade_exec(_grade_exec)
{
    std::cout << "[AForm] constructor called." << std::endl;
    if (_grade_sign < highestGrade || _grade_exec < highestGrade)
        throw (GradeTooHighException());
    if (_grade_sign > lowestGrade || _grade_exec > lowestGrade)
        throw (GradeTooLowException());
}

AForm::AForm(const AForm& src)
: _name(src._name), _signed(src._signed), _grade_sign(src._grade_sign), _grade_exec(src._grade_exec)
{
    std::cout << "[AForm] Copy constructor called." << std::endl;
    *this = src;
}

AForm& AForm::operator=(const AForm& src)
{
    std::cout << "[AForm] Copy assignment operator called\n";
//	*const_cast<std::string*>(&_name) = src.getName();
	_signed = src.getSign();
//	*const_cast<int*>(&_grade_sign) = src.getGradeSign();
//	*const_cast<int*>(&_grade_exec) = src.getGradeExec();
	return (*this);
}

AForm::~AForm()
{
	std::cout << "[AForm] Destructor called" << std::endl;
}

void    AForm::beSinged(Bureaucrat& src)
{
    if (src.getGrade() <= this->getGradeSign())
    {
        _signed = true;
		std::cout << this->getName() << " got signed." << std::endl;        
    }
    else
        throw (GradeTooLowException());
}

const std::string&    AForm::getName(void) const
{
    return (_name);
}

bool    AForm::getSign(void) const
{
    return (_signed);
}

int AForm::getGradeSign(void) const
{
    return (_grade_sign);
}

int AForm::getGradeExec(void) const
{
    return (_grade_exec);
}

std::ostream& operator<<(std::ostream& outputStream, const AForm& src)
{
	outputStream << src.getName() << ", required grade to sign is " << src.getGradeSign()
	<< ", required grade to execute is " << src.getGradeExec() << " and signed: " << std::boolalpha << src.getSign() << ".\n";
	return (outputStream);
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
    return ("can no longer upper Bureaucrat grade.\n");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
    return ("can no longer lower Bureaucracy grade.\n");
}
