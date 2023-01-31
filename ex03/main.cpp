#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void check_leak(void)
{
	system("leaks bureaucrat");
}

int main(void)
{
	atexit(check_leak);
	Intern someRandomIntern;
	Bureaucrat a("Marin", 1);
	Bureaucrat b("Mutal", 19);
	AForm *sa;
	AForm *ra;
	AForm *pa;
	AForm *none;

	sa = someRandomIntern.makeForm("shrubbery creation", "ShrubberyA");
	ra = someRandomIntern.makeForm("robotomy request", "RobotA");
	pa = someRandomIntern.makeForm("presidential pardon", "PrisonerA");
	none = someRandomIntern.makeForm("No exist form", "whatever");

//	ShrubberyCreationForm sa("ShrubberyA");
//	RobotomyRequestForm ra("RobotA");
//	PresidentialPardonForm pa("PrisonerA");

	a.signForm(*sa);
	a.signForm(*ra);
	a.signForm(*pa);

	b.executeForm(*sa); // signed and executed
	b.executeForm(*ra); // signed and executed
	b.executeForm(*pa); // signed but not executed

	delete sa;
	delete ra;
	delete pa;

	return 0;
}
