PUTFD_SRC	=	ft_putchar_fd \
				ft_putchar \
				ft_putendl_fd \
				ft_putnbr_fd \
				ft_putstr_fd \
				ft_putstr\

SRC			+=	$(addprefix $(PUTFD_PATH), $(PUTFD_SRC))