/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:16:49 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/30 14:11:13 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &name);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		virtual	~PresidentialPardonForm();
		PresidentialPardonForm const	&operator=(PresidentialPardonForm const &src);
		void				execute(Bureaucrat const & executor) const;
};

#endif