#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Scv"), grade(75)
{
    std::cout << "[Bureaucrat] Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
    std::cout << "[Bureaucrat] " << '[' << name << ']' << "constructor called." << std::endl;
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
    std::cout << "[Bureaucrat] Copy assignment operator called" << std::endl;

    this->name = src.getName();
    this->grade = src.getGrade();
    return (*this);
}

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat &src)
{
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] Destructor called" << std::endl;
}

const std::string&   Bureaucrat::getName(void) const
{
}

int Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

void Bureaucrat::incrementGrade()
{
}

void Bureaucrat::decrementGrade()
{
}
