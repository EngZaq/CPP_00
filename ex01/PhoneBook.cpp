/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zal-qais <zal-qais@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:20:18 by zal-qais          #+#    #+#             */
/*   Updated: 2026/01/01 15:36:09 by zal-qais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

    std::string PhoneBook::format_field(const std::string &s) const
    {
        if (s.size() > 10)
            return s.substr(0, 9) + ".";
        std::string res(10 - s.size(), ' ');
        res += s;
        return res;
    }

    PhoneBook::PhoneBook()
    {
        this->index = 0;
        this->total_contacts = 0;
    }
     
    void PhoneBook::add_contact()
    {
        Contact c;
        std::string str;

        // First name
        while (true)
        {
            std::cout << "enter first name: ";
            if (!std::getline(std::cin, str))
                return; // EOF or error
            if (str.empty())
                std::cout << "First name cannot be empty." << std::endl;
            else
            {
                c.set_first_name(str);
                break;
            }
        }

        // Last name
        while (true)
        {
            std::cout << "enter last name: ";
            if (!std::getline(std::cin, str))
                return;
            if (str.empty())
                std::cout << "Last name cannot be empty." << std::endl;
            else
            {
                c.set_last_name(str);
                break;
            }
        }

        // Nickname
        while (true)
        {
            std::cout << "enter nickname: ";
            if (!std::getline(std::cin, str))
                return;
            if (str.empty())
                std::cout << "Nickname cannot be empty." << std::endl;
            else
            {
                c.set_nickname(str);
                break;
            }
        }

        // Phone number
        while (true)
        {
            std::cout << "enter phone number: ";
            if (!std::getline(std::cin, str))
                return;
            if (str.empty())
            {
                std::cout << "Phone number cannot be empty." << std::endl;
                continue;
            }
            bool valid = true;
            for (size_t i = 0; i < str.length(); i++)
            {
                if (!std::isdigit(str[i]))
                {
                    valid = false;
                    break;
                }
            }
            if (!valid)
                std::cout << "Phone number must contain only digits." << std::endl;
            else
            {
                c.set_phone_number(str);
                break;
            }
        }

        // Darkest secret
        while (true)
        {
            std::cout << "enter darkest secret: ";
            if (!std::getline(std::cin, str))
                return;
            if (str.empty())
                std::cout << "Darkest secret cannot be empty." << std::endl;
            else
            {
                c.set_darkest_secret(str);
                break;
            }
        }

        // Save contact at current index
        contacts[index] = c;
        index = (index + 1) % 8;
        if (total_contacts < 8)
            total_contacts++;
        std::cout << "Contact added." << std::endl;
    }

    void PhoneBook::display_contacts()
    {
        if (total_contacts == 0)
        {
            std::cout << "No contacts to display." << std::endl;
            return;
        }

        std::cout << format_field("Index") << "|" << format_field("First Name") << "|" << format_field("Last Name") << "|" << format_field("Nickname") << std::endl;
        for (int i = 0; i < 43; i++) std::cout << '-';
        std::cout << std::endl;

        for (int i = 0; i < total_contacts; i++)
        {
            std::ostringstream oss;
            oss << (i + 1);
            std::string idx = oss.str();
            std::cout << format_field(idx) << "|"
                        << format_field(contacts[i].get_first_name()) << "|"
                        << format_field(contacts[i].get_last_name()) << "|"
                        << format_field(contacts[i].get_nickname()) << std::endl;
        }
    }

    void PhoneBook::display_contact_details(int idx)
    {
        if (idx < 1 || idx > total_contacts)
        {
            std::cout << "Invalid index." << std::endl;
            return;
        }
        Contact c = contacts[idx - 1];
        std::cout << "First Name: " << c.get_first_name() << std::endl;
        std::cout << "Last Name: " << c.get_last_name() << std::endl;
        std::cout << "Nickname: " << c.get_nickname() << std::endl;
        std::cout << "Phone Number: " << c.get_phone_number() << std::endl;
        std::cout << "Darkest Secret: " << c.get_darkest_secret() << std::endl;
    }

    void PhoneBook::seach_contact()
    {
        if (total_contacts == 0)
        {
            std::cout << "No contacts available." << std::endl;
            return;
        }
        display_contacts();
        std::cout << "Enter the index of the contact to view details: ";
        std::string line;
        if (!std::getline(std::cin, line))
        {
            std::cout << "Invalid index." << std::endl;
            return;
        }
        std::istringstream iss(line);
        int idx;
        if (!(iss >> idx) || !iss.eof())
        {
            std::cout << "Invalid index." << std::endl;
            return;
        }
        display_contact_details(idx);
    }
