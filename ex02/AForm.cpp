/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:18:13 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/28 15:25:43 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "AForm default constructor " << this->getName() << std::endl;
}

AForm::AForm(std::string const &name, int sign_grade, int exec_grade) : _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "AForm assignment constructor " << this->getName() << std::endl;
	if (this->_sign_grade < 1 || this->_exec_grade < 1)
		throw (AForm::GradeTooHighException());
	else if (this->_sign_grade > 150 || this->_exec_grade > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(AForm const &src) : _name(src._name), _is_signed(false), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{
	std::cout << "AForm copy constructor " << this->getName() << std::endl;
}

AForm::~AForm()
{
	std::cout << "Bureaucrat destructor " << this->getName() << std::endl;
}

AForm const	&AForm::operator=(AForm const &src)
{
	if (this != &src)
		this->_is_signed = src._is_signed;
	return (*this);
}

void	AForm::beSigned(Bureaucrat const &src)
{
	if (src.getGrade() > _sign_grade)
		throw (GradeTooLowException());
	else
		_is_signed = true;
	
}

char const *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

char const *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::string const	&AForm::getName() const
{
	return (this->_name);
}

bool const			&AForm::getSigned() const
{
	return (this->_is_signed);
}

int const			&AForm::getSignGrade() const
{
	return (this->_sign_grade);
}

int const			&AForm::getExecGrade() const
{
	return (this->_exec_grade);	
}

std::ostream &operator<<(std::ostream &str, AForm const &Aform)
{
	str << "AForm name: " << Aform.getName() << "\n"
		<< "Signed: " << (Aform.getSigned() ? "Yes" : "No") << "\n"
		<< "Grade required to sign: " << Aform.getSignGrade() << "\n"
		<< "Grade required to execute: " << Aform.getExecGrade() << "\n";
	return (str);
}
