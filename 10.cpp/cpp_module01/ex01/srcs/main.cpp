/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:21:18 by wonhshin          #+#    #+#             */
/*   Updated: 2023/11/21 11:20:43 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main(void)
{
    Zombie *horde;
    horde = zombieHorde(Zombie::HordeSize, "twits");
    
    for (int i=0; i<Zombie::HordeSize; i++)
        horde[i].announce(i);
    // std::cout << "first add : " << horde->getName() << std::endl;
    delete [] horde;
    return (0);
}
