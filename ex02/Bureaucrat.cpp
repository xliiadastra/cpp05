#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Scv"), grade(75)
{
    std::cout << "[Bureaucrat] Default name [Scv] constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
    std::cout << "[Bureaucrat] " << '[' << name << ']' << " constructor called." << std::endl;
    if (grade < highestGrade)
        throw(GradeTooHighException());
    if (grade > lowestGrade)
        throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
    std::cout << "[Bureaucrat] Copy constructor called." << std::endl;
    *this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    std::cout << "[Bureaucrat] Copy assignment operator called." << std::endl;

//    *const_cast<std::string*>(&name) = src.getName();
    this->grade = src.getGrade();
    return (*this);
}

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat &src)
{
	outputStream << src.getName() << ", bureaucrat grade " << src.getGrade() << '.' << std::endl;
    return (outputStream);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "[Bureaucrat] " << '[' << this->name << ']' << " Destructor called." << std::endl;
}

const std::string&   Bureaucrat::getName(void) const
{
    return (this->name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

void Bureaucrat::incrementGrade(void)
{
	std::cout << this->getName() << " is increasing grade Form " << getGrade() << std::endl;
    grade--;
    if (this->grade < highestGrade)
        throw (GradeTooHighException());
}

void Bureaucrat::decrementGrade(void)
{
	std::cout << this->getName() << " is decreasing grade Form " << getGrade() << std::endl;
    grade++;
    if (this->grade > lowestGrade)
        throw (GradeTooLowException());
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("can no longer upper Bureaucrat grade.\n");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("can no longer lower Bureaucracy grade.\n");
}

void    Bureaucrat::signForm(AForm& src)
{
    try
    {
        src.beSinged(*this);
        std::cout << this->getName() << " signed " << src.getName() << std::endl;
    }
    catch (const std::exception & e)
    {
        std::cout << this->getName() << " couldn’t sign " << src.getName() \
                    << " because " << e.what();
    }
}
