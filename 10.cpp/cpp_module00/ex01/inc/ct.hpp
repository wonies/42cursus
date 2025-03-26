/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ct.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:10:38 by wonhshin          #+#    #+#             */
/*   Updated: 2023/11/17 16:24:36 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class	Contact
{
private:
	std::string pnum;
	std::string fname;
	std::string lname;
	std::string aka;
	std::string ds;
public:
	void	infoAdd();
	void	infoCheck(std::string info);
	std::string getPnum() const { return pnum; }
	std::string getFname() const { return fname; }
	std::string getLname() const { return lname; }
	std::string getAka() const { return aka; }
	std::string getDs() const { return ds; }
};
