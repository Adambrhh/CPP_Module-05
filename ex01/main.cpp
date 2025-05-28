/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:41:10 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/28 15:20:24 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form invalidForm("InvalidForm", 0, 50);
    }
    catch (std::exception &e)
    {
        std::cerr<< e.what() << std::endl;
    }
    try
    {
        Bureaucrat alain("Alain", 50);
        Form validForm("ValidForm", 100, 50);
        std::cout << alain << std::endl;
        std::cout << validForm << std::endl;
        alain.signForm(validForm);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bernard("Bernard", 10);
        Form importantForm("ImportantForm", 20, 10);
        std::cout << bernard << std::endl;
        std::cout << importantForm << std::endl;
        bernard.signForm(importantForm);
        std::cout << importantForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat charles("Charles", 15);
        Form criticalForm("CriticalForm", 10, 5);
        std::cout << charles << std::endl;
        std::cout << criticalForm << std::endl;
        charles.gradeDown();
        std::cout << charles << std::endl;
        charles.signForm(criticalForm);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}