void		ft_sign(t_printf s*)
{
	if (s->sign == 1)
		write(1, '-', 1);
	else if (s->plus == 1 && s->sign == 0)
		write(1, '+', 1);
	return ;
}

void		ft_write_str(t_printf s*)
{
		ft_putstr_fd(s->tmp);
		s->michel += ft_strlen(s->tmp);
		return;
}

void		ft_write_width(t_printf s*)
{
	
}

void		ft_write_width(t_printf s*)
{

}
