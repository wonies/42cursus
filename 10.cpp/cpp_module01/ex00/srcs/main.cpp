/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:21:18 by wonhshin          #+#    #+#             */
/*   Updated: 2023/11/21 09:56:21 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main(void)
{
    Zombie zb("Foo");
    Zombie *newZomb = newZombie("Wonei");

    zb.announce();
    newZomb->announce();
    randomChump("Konie");

    delete  newZomb;
    return (0);
}
