/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:14:16 by hhattaki          #+#    #+#             */
/*   Updated: 2023/05/11 18:29:58 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <ctype.h>
#include <stdlib.h>

int	all_numeric(std::string str)
{
	int i = 0;

	while (str[i])
	{
		if (!isdigit(str[i]) && !(!i && str[i] == '+' && str[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

std::string	get_str(std::string str, std::string s)
{
	int i = 0, j = str.length() - 1;
	std::string	final;

	while (1)
	{
		while(str[i] && isspace(str[i]))
			i++;
		while(j >= 0 && isspace(str[j]))
			j--;
		final = str.substr(i, j - i + 1);
		if (final.empty() || !final.length())
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << s;
			str.clear();
			std::getline(std::cin, str);
			i = 0;
			j = str.length() - 1;
		}
		else
			break;
	}
	return (final);
}

void	PhoneBook::fillcontact(void)
{
	std::string line;

	std::cout << "Enter first name: ";
	std::getline(std::cin, line);
	c[spot].First_Name = get_str(line, "Enter first name: ");
	std::cout << "Enter last name: ";
	std::getline(std::cin, line);
	c[spot].Last_Name = get_str(line, "Enter last name: ");
	std::cout << "Enter nickname: ";
	std::getline(std::cin, line);
	c[spot].Nickname = get_str(line, "Enter nickname: ");
	std::cout << "Enter phone number: ";
	std::getline(std::cin, c[spot].Phone_Number);
	while (!all_numeric(c[spot].Phone_Number) || c[spot].Phone_Number.empty())
	{
		std::cout << "Numeric argument required" <<std::endl;
		std::cout << "Enter phone number: ";
		std::getline(std::cin, c[spot].Phone_Number);
	}
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, line);
	c[spot].Darkest_Secret = get_str(line, "Enter darkest secret: ");
	spot++;
	if (spot >= 8)
	{
		spot = 0;
		full = 1;
	}
}

void	print_ten(std::string str)
{
	int len, i = 0;

	len = str.length();
	if (len < 10)
	{
		std::cout << str;
		while (len < 10)
		{
			std::cout << " ";
			len++;
		}
	}
	else
	{
		while (i < 9)
		{
			std::cout << str[i];
			i++;
		}
		std::cout << ".";
	}
	std::cout << "|";
}

void	display_contact(Contact c, int i)
{
	print_ten(std::to_string(i));
	print_ten(c.First_Name);
	print_ten(c.Last_Name);
	print_ten(c.Nickname);
	std::cout << std::endl;
}

void	PhoneBook::search_contact(void)
{
	std::string num;
	int	i, n;

	print_ten("index");
	print_ten("first name");
	print_ten("last name");
	print_ten("nickname");
	std::cout << std::endl;
	int iterate = full ? 8 : spot;
	for(i = 0; i < iterate ;i++)
		display_contact(c[i], i);
	std::cout << "Enter index to display: ";
	std::getline(std::cin, num);
	if (num.empty() || !all_numeric(num))
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	n = std::atoi(num.c_str());
	if ((full && n >= 0 && n <= 7) || (!full && n >= 0 && n <= spot - 1))
	{
		print_ten("index");
		print_ten("first name");
		print_ten("last name");
		print_ten("nickname");
		std::cout << std::endl;
		display_contact(c[n], n);
	}
	else
		std::cout << "Invalid index" << std::endl;
}
