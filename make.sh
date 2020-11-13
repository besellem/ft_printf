# -fsanitize=address
clear
gcc -Wall -Wextra -Werror -fsanitize=address test/main.c ft_printf_family/*.c srcs/*.c -I includes/ft_printf.h libft/libft.a 
# leaks -atExit -- ./a.out
./a.out
rm ./a.out
