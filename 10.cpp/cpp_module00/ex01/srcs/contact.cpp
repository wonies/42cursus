/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:00:48 by wonhshin          #+#    #+#             */
/*   Updated: 2023/11/17 18:37:02 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pb.hpp"

void	Contact::infoCheck(std::string info)
{
	if (std::cin.eof())
		std::exit(1);
	if (info.empty())
	{
		while (1)
		{
			if (std::cin.eof())
				std::exit(1);
			if (!info.empty())
				break ;
			std::cout << "YOU HAVE TO FILL IT// IF YOU WANT TO GO NEXT STEP\n";
			std::getline(std::cin, info);
		}
	}
}

void	Contact::infoAdd()
{
	std::cout << "[Phone NUMBER]:   ";
	std::getline(std::cin, pnum);
	infoCheck(pnum);
	std::cout << "[First NAME]  :   ";
	std::getline(std::cin, fname);
	infoCheck(fname);
	std::cout << "[Last NAME]   :   ";
	std::getline(std::cin, lname);
	infoCheck(lname);
	std::cout << "[Nick NAME]   :   ";
	std::getline(std::cin, aka);
	infoCheck(aka);
	std::cout << "[Dark Secret {Dont't worry. Its first Secret}]: ";
	std::getline(std::cin, ds);
	infoCheck(ds);
}
