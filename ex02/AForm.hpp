/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:18:15 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/28 15:37:15 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAFORM_HPP
#define AAFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string 	_name;
		bool				_is_signed;
		const int			_sign_grade;
		const int			_exec_grade;
	public:
		AForm();
		AForm(std::string const &name, int sign_grade, int exec_grade);
		AForm(AForm const &src);
		virtual				~AForm(void);
		AForm const	&operator=(AForm const &src);
		std::string const	&getName() const;
		bool const			&getSigned() const;
		int const			&getSignGrade() const;
		int const			&getExecGrade() const;
		void				beSigned(Bureaucrat const &src);
		virtual void		execute(Bureaucrat const & executor) = 0;
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