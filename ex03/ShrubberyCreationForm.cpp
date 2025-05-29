/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:39:05 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/29 17:53:23 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "default")
{
	this->setSignGrade(145);
	this->setExecGrade(137);
	std::cout << "ShrubberyCreationForm default constructor " << this->getTarget() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
	std::cout << "ShrubberyCreationForm destructor for: " << this->getTarget() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", target)
{
	this->setSignGrade(145);
	this->setExecGrade(137);
	std::cout << "ShrubberyCreationForm constructor for target: " << target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor " << this->getTarget() << std::endl;
}


void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
 	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream outFile(filename.c_str());
	if (!outFile.is_open())
		throw AForm::FileCreationException();
	outFile << "               ,@@@@@@@," << std::endl;
	outFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	outFile << "    ,&&%&%&&%,@@@@@/@@@@@@,8888888/8o" << std::endl;
	outFile << "   ,%&&%&&%&&%,@@@/@@@/@@@88/88888/88'" << std::endl;
	outFile << "   %&&%&%&/%&&%@@/@@/ /@@@88888/88888'" << std::endl;
	outFile << "   %&&%/ %&&%&&@@/ V /@@' `88/8 `/88'" << std::endl;
	outFile << "   ``%&/` /%&'    |.|         |'|8'" << std::endl;
	outFile << "       |o|        | |         | |" << std::endl;
	outFile << "       |.|        | |         | |" << std::endl;
	outFile << "    ///  |///_/__/  |,_//__||/. |_//__/_" << std::endl;
	outFile.close();
}