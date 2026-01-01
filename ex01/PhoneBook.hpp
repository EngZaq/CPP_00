/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zal-qais <zal-qais@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:29:08 by zal-qais          #+#    #+#             */
/*   Updated: 2026/01/01 14:55:08 by zal-qais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <sstream>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int index;
        int total_contacts;

        std::string format_field(const std::string &s) const;

    public:
        PhoneBook();

        void add_contact();

        void display_contacts();

        void display_contact_details(int idx);

        void seach_contact();

};

#endif