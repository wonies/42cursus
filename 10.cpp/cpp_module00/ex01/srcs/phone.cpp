/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:00:53 by wonhshin          #+#    #+#             */
/*   Updated: 2023/11/17 16:24:41 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "../inc/pb.hpp"

void	PhoneBook::addContact()
{
	total_idx++;
	if (total_idx >= INFO_CONST::MAX_LEN)
		total_idx = INFO_CONST::MAX_LEN;
	if (idx >= INFO_CONST::MAX_LEN)
		idx = idx % INFO_CONST::MAX_LEN ; 
	ct[idx].infoAdd();	
	idx++;
}

void	PhoneBook::printPB(int i)
{
	std::cout << "[Phone num]      : " << ct[i].getPnum() << std::endl;
	std::cout << "[Last Name]      : " << ct[i].getLname() << std::endl;
	std::cout << "[A.k.a]          : " << ct[i].getAka() << std::endl;
	std::cout << "[First Name]     : " << ct[i].getFname() << std::endl;
	std::cout << "[Darkest Secret] : " << ct[i].getDs() << std::endl;
}

void	PhoneBook::rulePB(std::string text)
{
	if (text.length() <= 10)
		std::cout << std::setw(10) << text;
	else
		std::cout << std::setw(10) << text.substr(0, 9) + ".";
}

void	PhoneBook::searchPB()
{
	if (this->idx == 0)
		std::cout << "❗️PhoneBook IS EMPTY💌 YOU CAN FILL IT UP\n" << std::endl;
	else 
	{
		int i = -1;
		int selectIdx;

		while (++i < total_idx)
		{
			std::cout << "|";
			std::cout << std::setw(10) << i + 1 << "|";
			rulePB(ct[i].getFname());
			std::cout << "|";
			rulePB(ct[i].getLname());
			std::cout << "|";
			rulePB(ct[i].getAka());
			std::cout << "|" << std::endl;
		}
		std::cout << "SELECT -I-N-D-E-X-🧢: "<< std::endl;
		std::cin >> selectIdx;
		while (std::cin.fail() || selectIdx > total_idx || selectIdx <= 0 || std::cin.peek() != '\n') 
		{
			if (std::cin.eof())
				std::exit(1);
			std::cin.clear();
			std::cin.ignore(1000, '\n'); 
			std::cout << "SELECT JUST NUMERIC OR -R-I-G-H-T-🧵-I-N-D-E-X" << std::endl;
			std::cin >> selectIdx;
		}
		if (std::cin.eof())
			std::exit(1);
		std::cin.ignore(1000, '\n');
		std::cin.clear();
		printPB(selectIdx - 1);
	}
}

PhoneBook:: PhoneBook()
{
	idx = 0;
	total_idx = 0;
};

PhoneBook:: ~PhoneBook()
{
};