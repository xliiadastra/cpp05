#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <iostream>

class Bureaucrat;

class   PresidentialPardonForm : public  AForm
{
private:
    const std::string   _name;

    static const int    _grade_sign = 25;
    static const int    _grade_exec = 5;
    
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& name);
    PresidentialPardonForm(const PresidentialPardonForm& src);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
    ~PresidentialPardonForm();

    int execute(Bureaucrat const & executor) const;
};

#endif