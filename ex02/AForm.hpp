#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool              _signed; // 서명 여부
    const int         _grade_sign; // 서명하는데 필요한 등급
    const int         _grade_exec; // 실행하는데 필요한 등급
    static const int  highestGrade = 1;
    static const int  lowestGrade = 150;

public:
    class   GradeTooHighException : public std::exception
    {
        virtual const char	*what(void) const throw();
    };
    class   GradeTooLowException : public std::exception
    {
        virtual const char	*what(void) const throw();
    };

    AForm();
    AForm(const std::string& name, int _grade_sign, int _grade_exec);
    AForm(const AForm& src);
    AForm&   operator=(const AForm& src);
    ~AForm();

    void    beSinged(Bureaucrat& src);

    const std::string&  getName(void) const;
    bool                getSign(void) const;
    int                 getGradeSign(void) const;
    int                 getGradeExec(void) const;

    void    setSign(bool sign);

    virtual int execute(Bureaucrat const & executor) = 0;
};

std::ostream& operator<<(std::ostream& outputStream, const AForm &src);

#endif
