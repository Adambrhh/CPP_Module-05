/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:57:28 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/30 13:56:41 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &src);
		~Intern();
		Intern			&operator=(Intern const &src);
		AForm			*makeForm(const std::string form, const std::string target);
};

#endif