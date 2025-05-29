/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:13:31 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/29 17:53:32 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "default")
{
	this->setSignGrade(145);
	this->setExecGrade(137);
	std::cout << "RobotomyRequestForm default constructor " << this->getTarget() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
	std::cout << "RobotomyRequestForm destructor for: " << this->getTarget() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", target)
{
	this->setSignGrade(145);
	this->setExecGrade(137);
	std::cout << "RobotomyRequestForm constructor for target: " << target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor " << this->getTarget() << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << "* DRILLING NOISES * Bzzzzz... Vrrrrrr... Drrrrrrr... *" << std::endl;
	std::srand(std::time(NULL));
	if (rand() % 2)
		std::cout << this->getName() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed for " << this->getTarget() << "." << std::endl;
}