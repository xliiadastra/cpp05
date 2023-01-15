#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <iostream>

class Bureaucrat;

class   PresidentiaPardonForm : public  AForm
{
private:
    const std::string   _name;

    static const int    _grade_sign = 145;
    static const int    _grade_exec = 137;
    
public:
    PresidentiaPardonForm();
    PresidentiaPardonForm(const std::string& name);
    PresidentiaPardonForm(const PresidentiaPardonForm& src);
    PresidentiaPardonForm& operator=(const PresidentiaPardonForm& src);
    ~PresidentiaPardonForm();

    int execute(Bureaucrat const & executor);
};

#endif