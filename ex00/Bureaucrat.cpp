/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:41:14 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/28 11:12:59 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor " << this->getName() << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	this->_grade = grade;
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	std::cout << "Bureaucrat assignment constructor " << this->getName() << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	std::cout << "Bureaucrat copy constructor " << this->getName() << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor " << this->getName() << std::endl;	
}

Bureaucrat const	&Bureaucrat::operator=(const Bureaucrat &src)
{
	this->_name = src._name;
	this->_grade = src._grade;
	return (*this);
}

std::string const	&Bureaucrat::getName() const
{
	return (this->_name);
}

int const	&Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::gradeUp()
{
	this->_grade--;
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}

void	Bureaucrat::gradeDown()
{
	this->_grade++;
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

char const	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

char const	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat)
{
	return (str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}
