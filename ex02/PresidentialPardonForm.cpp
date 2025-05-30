/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:16:05 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/30 14:21:45 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "default")
{
	this->setSignGrade(25);
	this->setExecGrade(5);
	std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src)
{
	std::cout << "PresidentialPardonForm copy constructor for: " << this->getTarget() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", target)
{
	this->setSignGrade(25);
	this->setExecGrade(5);
	std::cout << "PresidentialPardonForm constructor for target: " << target << std::endl;
}

PresidentialPardonForm const	&PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	if (this != &src)
	{
		this->setSignGrade(src.getSignGrade());
		this->setExecGrade(src.getExecGrade());
		this->setSigned(false);
		this->setTarget(src.getTarget());
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor " << this->getTarget() << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}