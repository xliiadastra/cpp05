#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
private:
    std::string name;
    int         grade;
    static const int highestGrade = 1;
    static const int lowestGrade = 150;

public:
    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat& src);
    Bureaucrat& operator=( const Bureaucrat& src );
    ~Bureaucrat();

    class   GradeTooHighException : public std::exception
    {
        virtual const char	*what(void) const throw();
    };
    class   GradeTooLowException : public std::exception
    {
        virtual const char	*what(void) const throw();
    };

    const std::string& getName(void) const;
    int                getGrade(void) const;
	
    void    incrementGrade(void);
	void    decrementGrade(void);
};

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat &src);

#endif