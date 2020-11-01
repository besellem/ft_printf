# cd libft
# make bonus && make clean
# cd ..
# -fsanitize=address
clear
gcc -Wall -Wextra -Werror -fsanitize=address test/main.c srcs/*.c -I includes/ft_printf.h libft/libft.a 
./a.out
rm ./a.out
