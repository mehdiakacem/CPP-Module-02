/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:58:55 by makacem           #+#    #+#             */
/*   Updated: 2023/04/20 02:25:14 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : FixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &otherObject)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = otherObject;
}

Fixed   &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignmet operator called" << std::endl;
    if (this != &other)
        this->FixedPoint = other.getRawBits();
    return *this;
}
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->FixedPoint;
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->FixedPoint = raw;
}