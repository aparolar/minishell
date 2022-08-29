MEM_SRC		=	ft_bzero \
				ft_calloc \
				ft_memccpy \
				ft_memchr \
				ft_memcmp \
				ft_memcpy \
				ft_memmove \
				ft_memset \

SRC			+=	$(addprefix $(MEM_PATH), $(MEM_SRC))