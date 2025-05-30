/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:13:24 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/30 14:11:09 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AROBOTOMYREQUESTFORM_HPP
#define AROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		virtual	~RobotomyRequestForm();
		RobotomyRequestForm const	&operator=(RobotomyRequestForm const &src);
		void				execute(Bureaucrat const & executor) const;
};

#endif