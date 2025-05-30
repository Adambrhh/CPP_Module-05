/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:39:03 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/30 14:11:05 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASHRUBBERYCREATIONFORM_HPP
#define ASHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		virtual	~ShrubberyCreationForm();
		ShrubberyCreationForm const	&operator=(ShrubberyCreationForm const &src);
		void				execute(Bureaucrat const & executor) const;
};

#endif