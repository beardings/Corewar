/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:36:50 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/05 20:59:26 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../header/libft.h"
# include <stdio.h>

typedef struct	s_arg
{
	int			width;
	int			press;
	int			zero;
	int			hesh;
	int			plus;
	int			minus;
	int			space;
	int			flag;
	char		type;
	void		*tmp;
	int			len;
	int			pro;
	int			h;
}				t_arg;

int				ft_printf(const char *format, ...);
size_t			searcharg(const char *format, va_list arg, t_arg *res);
size_t			startformat(size_t i, const char *format, t_arg *res);
int				checkflags(size_t i, const char *format, t_arg *res);
int				checktype(size_t i, const char *format, t_arg *res);
int				checkhzmp(size_t i, const char *format, t_arg *res);
int				number(const char *format, size_t i);
void			*do_format(t_arg *res);
void			upperarg(t_arg *res);
t_arg			*createres(void);
void			writewidth(t_arg *res);
void			castflag_c(t_arg *res);
void			writezero(t_arg *res);
void			ft_putstrnew(char *tmp, int len, t_arg *res);
void			printhesh(t_arg *res);
int				castflag_s(t_arg *res);
void			castpress_s(t_arg *res, int i, char *tmp);
char			*ft_itoa_base(uintmax_t value, uintmax_t base, t_arg *res);
int				ft_null(char *tmp, t_arg *res, int len);
void			writewchar_t(wchar_t c, t_arg *res);
int				castflag_bigs(t_arg *res);
void			dowchar_t(wchar_t *tmp, t_arg *res, int len);
void			writepress(t_arg *res);
void			castpress_bigs(t_arg *res, int i, wchar_t *tmp, int len);
void			otherutf(wchar_t *tmp, t_arg *res);
int				checkcan(wchar_t *tmp, t_arg *res);
char			*cast_mod(t_arg *res);
void			cast_standart_for_base(t_arg *res);
void			preox(t_arg *res);
char			*base(t_arg *res, uintmax_t mun);
int				cast_mod_base(char *tmp, int len, t_arg *res);
void			finishd(intmax_t num, t_arg *res);
void			ft_putnbr_new(intmax_t n, t_arg *res);
intmax_t		lenintmax(intmax_t num);
void			cast_forlenth(t_arg *res);
void			minusmissing(t_arg *res, intmax_t len, intmax_t num);
void			minuspresent(t_arg *res, intmax_t len, intmax_t num);
int				numnull(t_arg *res);
void			cast_nnnnn(int i, t_arg *res, char *tmp);
int				utflen(wchar_t *tmp);
void			cast_mod_cont(char *tmp, int len, t_arg *res);
void			cast_mod_b(char *tmp, int len, t_arg *res);
void			cast_mod_contn(char *tmp, int len, t_arg *res);
void			cast_modd(char *tmp, int len, t_arg *res);
void			cast_moddd(char *tmp, int len, t_arg *res);
void			cast_modnex(char *tmp, int len, t_arg *res);
void			cast_mod_next(char *tmp, int len, t_arg *res);
void			cast_mod_contnext(char *tmp, int len, t_arg *res);
void			castflag_bigc(t_arg *res);

#endif
