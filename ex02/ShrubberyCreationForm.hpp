#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <fstream>

class Bureaucrat;

class   ShrubberyCreationForm : public  AForm
{
private:

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& name);
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
    ~ShrubberyCreationForm();

    int execute(Bureaucrat const & executor) const;
};

#endif