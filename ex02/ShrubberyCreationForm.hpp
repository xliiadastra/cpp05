#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <fstream>

class Bureaucrat;

class   ShrubberyCreationForm : public  AForm
{
private:
    const std::string   _name;

    static const int    _grade_sign = 145;
    static const int    _grade_exec = 137;
    
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& name);
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
    ~ShrubberyCreationForm();

    int execute(Bureaucrat const & executor);
};

#endif