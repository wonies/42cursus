/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:09:36 by wonhshin          #+#    #+#             */
/*   Updated: 2023/11/17 16:24:38 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "ct.hpp"

namespace INFO_CONST
{
	enum
	{
		MAX_LEN = 8
	};
}

class	PhoneBook
{
private:
	Contact ct[INFO_CONST::MAX_LEN];
public:
	int idx;
	int total_idx;
	std::string input;
	PhoneBook();
	~PhoneBook( void );
	void	addContact();
	void	printPB(int idx);
	void	rulePB(std::string text);
	void	searchPB();
};
