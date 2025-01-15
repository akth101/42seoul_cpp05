
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

const char* Intern::NoMatchingFormException::what() const throw() {
    return "No matching form found!";
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    const char* forms[] = {"shrubberyCreationForm", "robotomyRequestForm", "presidentialPardonForm"};
    int formIndex = 0;
    
    while (formIndex < 3 && formName != forms[formIndex])
        ++formIndex;
    try {
        if (formIndex == 3)
            throw NoMatchingFormException();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return NULL;
    }
    std::cout << "Intern creates " << formName << std::endl;
    switch (formIndex) {
        case 0:
            return new ShrubberryCreationForm(target);
        case 1:
            return new RobotomyRequestForm(target);
        case 2:
            return new PresidentialPardonForm(target);
    }
    return NULL;
}

