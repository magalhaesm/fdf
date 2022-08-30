/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:17:25 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/30 00:37:48 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

# define K_ESCAPE 0xff1b

# define K_LEFT 0xff51
# define K_UP 0xff52
# define K_RIGHT 0xff53
# define K_DOWN 0xff54

# define K_A 0x0061
# define K_D 0x0064
# define K_E 0x0065
# define K_I 0x0069
# define K_O 0x006f
# define K_Q 0x0071
# define K_R 0x0072
# define K_S 0x0073
# define K_W 0x0077

# define K_BRACKETLEFT 0x005b
# define K_BRACKETRIGHT 0x005d

# define K_MINUS 0x002d
# define K_EQUAL 0x003d

# define KEYPRESS 2
# define KEYRELEASE 3
# define DESTROYNOTIFY 17

typedef enum e_mlx_mask {
	NOEVENTMASK = 0L,
	KEYPRESSMASK = (1L << 0),
	KEYRELEASEMASK = (1L << 1)
}	t_mlx_mask;

#endif
