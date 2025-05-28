/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:16:05 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/28 16:34:13 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor " << this->getName() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src)
{
	std::cout << "PresidentialPardonForm copy constructor " << this->getName() << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Bureaucrat destructor " << this->getName() << std::endl;
}

PresidentialPardonForm const	&PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	if (this != &src)
		this->_is_signed = src._is_signed;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor)
{
	
}