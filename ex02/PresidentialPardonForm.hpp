/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:16:49 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/29 17:22:19 by abarahho         ###   ########.fr       */
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
		virtual	~PresidentialPardonForm(void);
		PresidentialPardonForm const	&operator=(PresidentialPardonForm const &src);
		void				execute(Bureaucrat const & executor) const;
};

#endif