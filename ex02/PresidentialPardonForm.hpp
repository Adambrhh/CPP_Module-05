/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:16:49 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/28 16:32:46 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		bool				_is_signed;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &src);
		virtual	~PresidentialPardonForm(void);
		PresidentialPardonForm const	&operator=(PresidentialPardonForm const &src);
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