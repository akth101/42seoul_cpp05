#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
    public:
    	class NoMatchingFormException : public std::exception {
        	public:
	    	    virtual const char* what() const throw();
	    };
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();
        AForm *makeForm(std::string formName, std::string target);
};

#endif