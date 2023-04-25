/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 02:41:16 by makacem           #+#    #+#             */
/*   Updated: 2023/04/25 13:44:26 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : FixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : FixedPoint(n << this->FractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : FixedPoint(roundf(n * 256))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &otherObject)
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

std::ostream   &operator<<(std::ostream &output, Fixed const &src)
{
    output << src.toFloat();
    return output;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return this->FixedPoint;
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->FixedPoint = raw;
}

float   Fixed::toFloat(void) const
{
    return (float)this->FixedPoint / 256;
}

int   Fixed::toInt(void) const
{
    return (this->FixedPoint / 256);
}