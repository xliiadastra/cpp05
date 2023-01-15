#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
	try
	{
		Bureaucrat a;
		Bureaucrat b("Marin", 19);
		Bureaucrat c("Mutal", 38);
		Form fa("form_a", 20, 20);
		Form fb("form_b", 40, 40);

		std::cout << a << b << c;
		std::cout << fa << fb;
		b.signForm(fa);
		b.signForm(fb);
		c.signForm(fa);
		c.signForm(fb);
	}
	catch(const std::exception & e) // why reference? to avoid copy cost and not to concern allocation and free
	{
		std::cout << e.what();
	}
	return 0;
}