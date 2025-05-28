/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:13:24 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/28 16:32:58 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AROBOTOMYREQUESTFORM_HPP
#define AROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		bool				_is_signed;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &src);
		virtual	~RobotomyRequestForm(void);
		RobotomyRequestForm const	&operator=(RobotomyRequestForm const &src);
		std::string const	&getName() const;
		bool const			&getSigned() const;
		int const			&getSignGrade() const;
		int const			&getExecGrade() const;
		void				execute(Bureaucrat const & executor);
		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what() const throw();
		};
};

#endif