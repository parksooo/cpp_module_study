#include "Bureaucrat.hpp"

int main(){
	Bureaucrat a;
	Bureaucrat b("b", 0);
	Bureaucrat c("c", 1);
	Bureaucrat d("d", 150);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	c.incrementGrade();
	std::cout << c << std::endl;
	d.decrementGrade();
	std::cout << d << std::endl;
	d.incrementGrade();
	std::cout << d << std::endl;

	
}