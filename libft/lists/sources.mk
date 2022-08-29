LISTS_SRC	=	ft_lstadd_back \
				ft_lstadd_front \
				ft_lstclear \
				ft_lstdelone \
				ft_lstinsert_next \
				ft_lstiter_bpa_if \
				ft_lstiter_if \
				ft_lstiter_var \
				ft_lstiter \
				ft_lstlast \
				ft_lstmap \
				ft_lstnew \
				ft_lstsize \
				ft_lstiter_count \

SRC			+=	$(addprefix $(LISTS_PATH), $(LISTS_SRC))