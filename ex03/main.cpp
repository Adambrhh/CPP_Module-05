/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:41:10 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/30 16:40:24 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    std::cout << "=== Test with valid forms ===\n";
    try {
        AForm* shrub = someRandomIntern.makeForm("shrubbery form", "Garden");
        AForm* robo = someRandomIntern.makeForm("robotomy form", "Bender");
        AForm* pardon = someRandomIntern.makeForm("presidential form", "Ford Prefect");

        delete shrub;
        delete robo;
        delete pardon;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== Test with invalid form ===\n";
    try {
        AForm* unknown = someRandomIntern.makeForm("unknown form", "Nobody");
        delete unknown;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    return 0;
}
