/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:39:03 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/28 16:33:01 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASHRUBBERYCREATIONFORM_HPP
#define ASHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
		bool				_is_signed;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		virtual	~ShrubberyCreationForm(void);
		ShrubberyCreationForm const	&operator=(ShrubberyCreationForm const &src);
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