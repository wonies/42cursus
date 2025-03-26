/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:00:50 by wonhshin          #+#    #+#             */
/*   Updated: 2023/11/17 16:24:42 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pb.hpp"

int main(void)
{
	PhoneBook pb;
	
	std::cout << "\t💘 ☪️[MISSION] COMPLETE MY PHONE BOOK📱🍑\n" << std::endl;
	while (1)
	{
		std::cout << "COMMAND [ADD] [SEARCH] [EXIT] \n YOU MUST CHOOSE THIS ORDER __ IF NOT,, YOU DESERVE IT🐣" << std::endl;
		if (std::cin.eof())
			std::exit(1);
		std::cin>>pb.input;
		std::cin.ignore();
		if (pb.input == "ADD" || pb.input == "add")
			pb.addContact();
		else if (pb.input == "SEARCH" || pb.input == "search")
			pb.searchPB();
		else if (pb.input == "EXIT" || pb.input == "exit")
			break ;
		else
		{
			std::cout<< "------😈-------NOT VERIFY COMMAND------😈--------" << std::endl;
			std::cout<< "😈😈😈😈😈😈😈😈😈😈😈😈😈😈😈😈😈👿😈😈😈😈😈😈😈😈😈😈😈\n\n" << std::endl;
		}
	}
	return 0;
}
