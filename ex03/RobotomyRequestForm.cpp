#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RForm", 72, 45)
{
//	std::cout << "[RobotomyRequestForm] Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name) : AForm(name, 72, 45)
{
//	std::cout << "[RobotomyRequestForm] constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
: AForm(src)
{
//	std::cout << "[RobotomyRequestForm] Copy constructor called" << std::endl;
//    *this = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
//	std::cout << "[RobotomyRequestForm] Copy assignment constructor called" << std::endl;
    if (this != &src)
        this->setSign(src.getSign());
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
//	std::cout << "[RobotomyRequestForm] Destructor called" << std::endl;
}

int RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	std::random_device rd; // 난수 생성
	std::mt19937 gen(rd()); // 난수 엔진
	std::uniform_int_distribution<int> dis(0, 1);

	if (!getSign())
	{
		std::cout << "Form "<< getName() <<" is not signed so cannot be executed.\n";
	}
	else if (executor.getGrade() > getGradeExec())
	{
		std::cout << "Executor's grade is not high enough to execute " << getName() << '\n';
	}
	else
	{
		std::cout << "[Drilling noises]\n" << getName();
		if (dis(gen))
			std::cout << " has been robotomized successfully\n";
		else
			std::cout << " robotomized has been failed\n";
		return (0);
	}
	return (1);
}