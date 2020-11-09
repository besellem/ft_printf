clear
gcc -Wall -Wextra -Werror  test/main.c srcs/*.c -I includes/ft_printf.h libft/libft.a 
# leaks -atExit -- ./a.out
./a.out
rm ./a.out
