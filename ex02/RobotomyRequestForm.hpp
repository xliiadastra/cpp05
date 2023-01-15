#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <iostream>

class Bureaucrat;

class   RobotomyRequestForm : public  AForm
{
private:
    const std::string   _name;

    static const int    _grade_sign = 145;
    static const int    _grade_exec = 137;
    
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& name);
    RobotomyRequestForm(const RobotomyRequestForm& src);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
    ~RobotomyRequestForm();

    int execute(Bureaucrat const & executor);
};

#endif