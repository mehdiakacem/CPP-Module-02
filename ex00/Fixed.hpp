/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:58:52 by makacem           #+#    #+#             */
/*   Updated: 2023/04/20 02:05:25 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
    int FixedPoint;
    static const int FractionalBits = 8;
public:
    Fixed(void);
    Fixed(Fixed const &otherObject);
    Fixed   &operator=(const Fixed &other);
    ~Fixed(void);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};




#endif