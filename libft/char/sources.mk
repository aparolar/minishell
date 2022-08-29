CHAR_SRC	=	ft_isalnum \
				ft_isalpha \
				ft_isascii \
				ft_isdigit \
				ft_isprint \
				ft_tolower \
				ft_toupper \

SRC			+=	$(addprefix $(CHAR_PATH), $(CHAR_SRC))