/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zal-qais <zal-qais@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:42:30 by zal-qais          #+#    #+#             */
/*   Updated: 2026/01/01 14:44:28 by zal-qais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <sstream>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        void    set_first_name(std::string str);

        void   set_last_name(std::string str);

        void   set_nickname(std::string str);

        void   set_phone_number(std::string str);

        void   set_darkest_secret(std::string str);

        std::string get_first_name();

        std::string get_last_name();

        std::string get_nickname();

        std::string get_phone_number();

        std::string get_darkest_secret();

};


#endif