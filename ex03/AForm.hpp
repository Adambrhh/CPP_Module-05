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

# include <fstream>
# include <iostream>

class Bureaucrat;

class AForm
{
	protected:
		const std::string 	_name;
		bool				_is_signed;
		const int			_sign_grade;
		const int			_exec_grade;
		std::string			_target;
	public:
		AForm();
		AForm(std::string const &name);
		AForm(AForm const &src);
		AForm(std::string const &name, std::string const &target);
		virtual				~AForm(void);
		AForm const	&operator=(AForm const &src);
		std::string const	&getName() const;
		bool const			&getSigned() const;
		int const			&getSignGrade() const;
		int const			&getExecGrade() const;
		std::string const	&getTarget() const;
		void				setSigned(bool);
		void				setSignGrade(int);
		void				setExecGrade(int);
		void				setTarget(std::string const &target);
		void				beSigned(Bureaucrat const &src);
		virtual void		execute(Bureaucrat const & executor) const = 0;
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
		class FormNotSignedException: public std::exception
		{
			public:
				virtual char const	*what() const throw();
		};
		class FileCreationException: public std::exception
		{
		public:
				virtual char const	*what() const throw();
		};
};

#endif