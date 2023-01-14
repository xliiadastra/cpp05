#include "Bureaucrat.hpp"

int main( void )
{
	try
	{
		Bureaucrat terran1;
		Bureaucrat terran2("Marin", 2);
		Bureaucrat terran3("Mutal", 149);

		std::cout << terran1 << terran2 << terran3;
		terran2.incrementGrade();
		terran2.decrementGrade();
		terran2.incrementGrade();
		terran3.decrementGrade();
		terran3.decrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	return 0;
}