/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 02:41:06 by makacem           #+#    #+#             */
/*   Updated: 2023/04/26 00:38:21 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int FixedPoint;
        static const int FractionalBits = 8;
    public:
        Fixed(void);
        Fixed(const int n);
        Fixed(const float n);
        Fixed(const Fixed &otherObject);
        Fixed   &operator=(const Fixed &other);
        ~Fixed(void);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
        bool    operator>(const Fixed &n) const;
        bool    operator<(const Fixed &n) const;
        bool    operator>=(const Fixed &n) const;
        bool    operator<=(const Fixed &n) const;
        bool    operator==(const Fixed &n) const;
        bool    operator!=(const Fixed &n) const;
        Fixed   operator+(const Fixed &n);
        Fixed   operator-(const Fixed &n);
        Fixed   operator*(const Fixed &n);
        Fixed   operator/(const Fixed &n);
        Fixed   &operator++(void);
        Fixed   operator++(int);
        Fixed   &operator--(void);
        Fixed   operator--(int);
        static Fixed   &min(Fixed &a, Fixed &b);
        static const Fixed   &min(Fixed const &a, Fixed const &b);
        static Fixed   &max(Fixed &a, Fixed &b);
        static const Fixed   &max(Fixed const &a, Fixed const &b);
};

std::ostream   &operator<<(std::ostream &output, Fixed const &src);


#endif