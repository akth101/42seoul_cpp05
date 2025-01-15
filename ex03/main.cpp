
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
   Intern intern;
   
   std::cout << "[valid form creation]" << std::endl;
   {
       AForm* shrubbery = intern.makeForm("shrubberyCreationForm", "form1");
       AForm* robotomy = intern.makeForm("robotomyRequestForm", "form2");
       AForm* presidential = intern.makeForm("presidentialPardonForm", "form3");

       if (shrubbery) {
           std::cout << "Shrubbery form created: " << shrubbery->getName() << std::endl;
           delete shrubbery;
       }
       if (robotomy) {
           std::cout << "Robotomy form created: " << robotomy->getName() << std::endl;
           delete robotomy;
       }
       if (presidential) {
           std::cout << "Presidential form created: " << presidential->getName() << std::endl;
           delete presidential;
       }
   }

   std::cout << "[invalid form creation]" << std::endl;
   {
       AForm* invalid = intern.makeForm("invalidForm", "test");
       if (!invalid) {
           std::cout << "Successfully rejected invalid form name" << std::endl;
       }
   }

   std::cout << "[Testing form in real]" << std::endl;
   {
       Bureaucrat jack("Jack", 1);
       AForm* robotomy = intern.makeForm("robotomyRequestForm", "form1");
       
       if (robotomy) {
           try {
               jack.signForm(*robotomy);
               jack.executeForm(*robotomy);
           } catch (std::exception& e) {
               std::cout << "Exception: " << e.what() << std::endl;
           }
           delete robotomy;
       }
   }
   return 0;
}
