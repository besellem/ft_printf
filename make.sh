# cd libft
# make bonus && make clean
# cd ..
# -fsanitize=address
gcc -fsanitize=address test/main.c srcs/*.c -I includes/ft_printf.h libft/libft.a 
./a.out
