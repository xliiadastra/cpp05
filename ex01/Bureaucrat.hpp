#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class From;

class Bureaucrat
{
private:
    std::string name;
    int         grade;
    static const int highestGrade = 1;
    static const int lowestGrade = 150;

public:
    class   GradeTooHighException : public std::exception
    {
        virtual const char	*what(void) const throw();
    };
    class   GradeTooLowException : public std::exception
    {
        virtual const char	*what(void) const throw();
    };

    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat& src);
    Bureaucrat& operator=( const Bureaucrat& src );
    ~Bureaucrat();

    const std::string& getName(void) const;
    int                getGrade(void) const;
	
    void    incrementGrade(void);
	void    decrementGrade(void);

    void    signForm(From& src);
};

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat &src);

#endif