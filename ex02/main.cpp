/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:41:10 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/29 14:54:11 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat gardener("Gardener", 137);
        ShrubberyCreationForm shrub("garden");
        std::cout << "\n=== Testing ShrubberyCreationForm ===\n" << std::endl;
        gardener.signForm(shrub);
        gardener.executeForm(shrub);
        std::cout << "\n=== Testing RobotomyRequestForm ===\n" << std::endl;
        Bureaucrat technician("Technician", 45);
        RobotomyRequestForm robot("Human");
        technician.signForm(robot);
        technician.executeForm(robot);
        technician.executeForm(robot);
        std::cout << "\n=== Testing PresidentialPardonForm ===\n" << std::endl;
        Bureaucrat president("President", 5);
        PresidentialPardonForm pardon("Criminal");
        president.signForm(pardon);
        president.executeForm(pardon);
        std::cout << "\n=== Testing Failure Cases ===\n" << std::endl;
        Bureaucrat intern("Intern", 150);
        intern.signForm(shrub);
        intern.executeForm(robot);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return (0);
}