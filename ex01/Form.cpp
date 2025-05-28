/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:18:13 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/28 15:25:43 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "Form default constructor " << this->getName() << std::endl;
}

Form::Form(std::string const &name, int sign_grade, int exec_grade) : _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Form assignment constructor " << this->getName() << std::endl;
	if (this->_sign_grade < 1 || this->_exec_grade < 1)
		throw (Form::GradeTooHighException());
	else if (this->_sign_grade > 150 || this->_exec_grade > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(Form const &src) : _name(src._name), _is_signed(false), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{
	std::cout << "Form copy constructor " << this->getName() << std::endl;
}

Form::~Form()
{
	std::cout << "Bureaucrat destructor " << this->getName() << std::endl;
}

Form const	&Form::operator=(Form const &src)
{
	if (this != &src)
		this->_is_signed = src._is_signed;
	return (*this);
}

void	Form::beSigned(Bureaucrat const &src)
{
	if (src.getGrade() > _sign_grade)
		throw (GradeTooLowException());
	else
		_is_signed = true;
	
}

char const *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

char const *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::string const	&Form::getName() const
{
	return (this->_name);
}

bool const			&Form::getSigned() const
{
	return (this->_is_signed);
}

int const			&Form::getSignGrade() const
{
	return (this->_sign_grade);
}

int const			&Form::getExecGrade() const
{
	return (this->_exec_grade);	
}

std::ostream &operator<<(std::ostream &str, Form const &form)
{
	str << "Form name: " << form.getName() << "\n"
		<< "Signed: " << (form.getSigned() ? "Yes" : "No") << "\n"
		<< "Grade required to sign: " << form.getSignGrade() << "\n"
		<< "Grade required to execute: " << form.getExecGrade() << "\n";
	return (str);
}
