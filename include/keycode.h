/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:17:25 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/28 23:33:33 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

# define K_Escape 0xff1b

# define K_Left 0xff51
# define K_Up 0xff52
# define K_Right 0xff53
# define K_Down 0xff54

# define K_a 0x0061
# define K_d 0x0064
# define K_e 0x0065
# define K_i 0x0069
# define K_p 0x0070
# define K_q 0x0071
# define K_r 0x0072
# define K_s 0x0073
# define K_w 0x0077

# define K_bracketleft 0x005b
# define K_bracketright 0x005d

# define K_minus 0x002d
# define K_equal 0x003d

// Events
# define KEYPRESS 2
# define KEYRELEASE 3
# define DESTROYNOTIFY 17

// Masks
# define NOEVENTMASK 0L
# define KEYPRESSMASK (1L << 0)
# define KEYRELEASEMASK (1L << 1)

#endif
