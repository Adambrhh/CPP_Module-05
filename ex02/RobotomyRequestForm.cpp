/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:13:31 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/28 16:33:50 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor " << this->getName() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
	std::cout << "RobotomyRequestForm copy constructor " << this->getName() << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Bureaucrat destructor " << this->getName() << std::endl;
}

RobotomyRequestForm const	&RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	if (this != &src)
		this->_is_signed = src._is_signed;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	
}