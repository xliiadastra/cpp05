#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
	try
	{
		Bureaucrat a("Marin", 1);
		Bureaucrat b("Mutal", 19);
		Bureaucrat c("Prove", 138);
		ShrubberyCreationForm sa("ShrubberyA");
		ShrubberyCreationForm sb("ShrubberyB");
		RobotomyRequestForm ra("RobotA");
		PresidentialPardonForm pa("PrisonerA");
		PresidentialPardonForm pb("PrisonerB");

		std::cout << sa << ra << pa;

		std::cout << "----------------" << std::endl;
		a.signForm(sa);
		a.signForm(ra);
		a.signForm(pa);

		std::cout << "----------------" << std::endl;
		b.executeForm(sa); // signed and executed
		b.executeForm(sb); // not signed and not executed
		c.executeForm(sa); // signed but not executed

		std::cout << "----------------" << std::endl;
		b.executeForm(ra); // signed and executed
		b.executeForm(ra);
		b.executeForm(ra);

		std::cout << "----------------" << std::endl;
		b.executeForm(pa); // signed but not executed
		a.executeForm(pa); // signed and executed
		a.executeForm(pb); // not signed and not executed
	}
	catch(const std::exception &e) // why reference? to avoid copy cost and not to concern allocation and free
	{
		std::cout << e.what();
	}
	return 0;
}
