/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovoa <anovoa@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:22:15 by anovoa            #+#    #+#             */
/*   Updated: 2023/04/16 14:15:32 by anovoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

unsigned int	ft_atoi(char *str);
void			ft_check_argc(int argc, char *argv[]);
int				ft_count_nospace(char *str);
int				ft_is_valid_input(char *str);
int				ft_is_valid_dict(char *str);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_puterror(void);
void			ft_putdict_error(void);
int				ft_read_local_dict(void);
char			*ft_remove_spaces(char *str);

#endif
