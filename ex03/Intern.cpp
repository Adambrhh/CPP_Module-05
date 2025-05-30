/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:57:30 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/30 16:41:09 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(Intern const &src)
{
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern destructor"<< std::endl;
}

Intern			&Intern::operator=(Intern const &src)
{
	std::cout << "Intern assignment operator called" << std::endl;
	if (this != &src)
		return (*this);
	return (*this);
}

static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm			*Intern::makeForm(const std::string form, const std::string target)
{
	int i;

	i = 0;
	AForm	*(*forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string formsName[] = {"presidential form", "robotomy form", "shrubbery form"};
	while (i < 3)
	{
		if (form == formsName[i]) 
		{
			std::cout << "Intern creates " << formsName[i] << std::endl;
			return (forms[i](target));
		}
		i++;
	}
	std::cout << "Interns are good for nothing!" << std::endl;
	return (NULL);
}