#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Form;

class Bureaucrat {
    private:
        const std::string name;
        int grade;
        Bureaucrat();

    public:
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class FormAlreadySignedException : public std::exception {
            public:
                const char* what() const throw();
        };

        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade(int value);
        void decrementGrade(int value);
        void signForm(Form& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
