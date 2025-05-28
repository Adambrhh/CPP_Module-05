/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:18:15 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/28 15:00:58 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string 	_name;
		bool				_is_signed;
		const int			_sign_grade;
		const int			_exec_grade;
	public:
		Form();
		Form(std::string const &name, int sign_grade, int exec_grade);
		Form(Form const &src);
		~Form(void);
		Form const	&operator=(Form const &src);
		std::string const	&getName() const;
		bool const			&getSigned() const;
		int const			&getSignGrade() const;
		int const			&getExecGrade() const;
		void				beSigned(Bureaucrat const &src);
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

std::ostream	&operator<<(std::ostream &str, Form const &form);

#endif