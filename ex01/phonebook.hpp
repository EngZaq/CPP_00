////add 42 header or you will fail the project /////

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <sstream>

class contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        void    set_first_name(std::string str)
        {
            this->first_name = str;
        }

        void   set_last_name(std::string str)
        {
            this->last_name = str;
        }

        void   set_nickname(std::string str)
        {
            this->nickname = str;
        }

        void   set_phone_number(std::string str)
        {
            this->phone_number = str;
        }

        void   set_darkest_secret(std::string str)
        {
            this->darkest_secret = str;
        }

        std::string get_first_name()
        {
            return this->first_name;
        }

        std::string get_last_name()
        {
            return this->last_name;
        }

        std::string get_nickname()
        {
            return this->nickname;
        }

        std::string get_phone_number()
        {
            return this->phone_number;
        }

        std::string get_darkest_secret()
        {
            return this->darkest_secret;
        }

};

class PhoneBook
{
    private:
        contact contacts[8];
        int index;
        int total_contacts;

        std::string format_field(const std::string &s) const
        {
            if (s.size() > 10)
                return s.substr(0, 9) + ".";
            std::string res(10 - s.size(), ' ');
            res += s;
            return res;
        }

    public:
        PhoneBook()
        {
            this->index = 0;
            this->total_contacts = 0;
        }

        void add_contact()
        {
            contact c;
            std::string str;

            // First name
            while (true)
            {
                std::cout << "enter first name: ";
                if (!(std::cin >> str))
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
                if (!(std::cin >> str))
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
                if (!(std::cin >> str))
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
                if (!(std::cin >> str))
                    return;
                if (str.empty())
                    std::cout << "Phone number cannot be empty." << std::endl;
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
                if (!(std::cin >> str))
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

        void display_contacts()
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

        void display_contact_details(int idx)
        {
            if (idx < 1 || idx > total_contacts)
            {
                std::cout << "Invalid index." << std::endl;
                return;
            }
            contact c = contacts[idx - 1];
            std::cout << "First Name: " << c.get_first_name() << std::endl;
            std::cout << "Last Name: " << c.get_last_name() << std::endl;
            std::cout << "Nickname: " << c.get_nickname() << std::endl;
            std::cout << "Phone Number: " << c.get_phone_number() << std::endl;
            std::cout << "Darkest Secret: " << c.get_darkest_secret() << std::endl;
        }

        void seach_contact()
        {
            if (total_contacts == 0)
            {
                std::cout << "No contacts available." << std::endl;
                return;
            }
            display_contacts();
            std::cout << "Enter the index of the contact to view details: ";
            int idx;
            if (!(std::cin >> idx))
            {
                std::cout << "Invalid index." << std::endl;
                std::cin.clear();
                std::string dummy;
                std::cin >> dummy; // consume bad token
                return;
            }
            display_contact_details(idx);
        }

};

#endif