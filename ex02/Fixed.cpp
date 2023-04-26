/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 02:41:16 by makacem           #+#    #+#             */
/*   Updated: 2023/04/26 00:38:17 by makacem          ###   ########.fr       */
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

bool    Fixed::operator>(const Fixed &n) const
{
    return this->FixedPoint > n.getRawBits();
}

bool    Fixed::operator<(const Fixed &n) const
{
    return this->FixedPoint < n.getRawBits();
}

bool    Fixed::operator>=(const Fixed &n) const
{
    return this->FixedPoint >= n.getRawBits();
}

bool    Fixed::operator<=(const Fixed &n) const
{
    return this->FixedPoint <= n.getRawBits();
}

bool    Fixed::operator==(const Fixed &n) const
{
    return this->FixedPoint == n.getRawBits();
}

bool    Fixed::operator!=(const Fixed &n) const
{
    return this->FixedPoint != n.getRawBits();
}

Fixed   Fixed::operator+(const Fixed &n)
{
    return (this->toFloat() + n.toFloat());
}

Fixed   Fixed::operator-(const Fixed &n)
{
    return (this->toFloat() - n.toFloat());
}

Fixed   Fixed::operator*(const Fixed &n)
{
    return (this->toFloat() * n.toFloat());
}

Fixed   Fixed::operator/(const Fixed &n)
{
    return (this->toFloat() / n.toFloat());
}

Fixed   &Fixed::operator++(void)
{
    this->FixedPoint += 1;
    return *this;
}

Fixed   Fixed::operator++(int)
{
    Fixed old(*this);
    operator++();
    return old;
}

Fixed   &Fixed::operator--(void)
{
    this->FixedPoint -= 1;
    return *this;
}

Fixed   Fixed::operator--(int)
{
    Fixed old(*this);
    operator--();
    return old;
}

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

const Fixed   &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

const Fixed   &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}