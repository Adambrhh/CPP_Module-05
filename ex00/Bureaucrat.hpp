/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:41:12 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/28 11:34:42 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT
#define BUREAUCRAT

# include <iostream>

class Bureaucrat
{
	private:
		std::string 		_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);
		Bureaucrat const	&operator=(Bureaucrat const &src);
		std::string const	&getName() const;
		int const			&getGrade() const;
		void	gradeUp(void);
		void	gradeDown(void);
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

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat);

#endif