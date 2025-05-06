/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanherr <juanherr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:13:01 by juanherr          #+#    #+#             */
/*   Updated: 2025/05/06 13:06:35 by juanherr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
  public:
	PhoneBook();
	void 	addContact();
	void 	searchContacts() const;

  private:
	Contact contacts[8];
	int 	count;
	int 	oldestIndex;
};

#endif
