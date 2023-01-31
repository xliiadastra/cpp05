#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <random>

class Bureaucrat;

class   RobotomyRequestForm : public  AForm
{
private:

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& name);
    RobotomyRequestForm(const RobotomyRequestForm& src);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
    ~RobotomyRequestForm();

    int execute(Bureaucrat const & executor) const;
};

#endif