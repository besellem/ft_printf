# ft_printf
Recreating the printf functions in C

## ⚠️ WARNING
This repo is no longer updated. To get the newest version, check my other repo [https://github.com/besellem/libft.git]

## Prototypes
```c
int	ft_printf(const char *format, ...);
int	ft_sprintf(char *str, const char *format, ...);
int	ft_snprintf(char *str, size_t size, const char *format, ...);
int	ft_asprintf(char **ret, const char *format, ...);
int	ft_dprintf(int fd, const char *format, ...);

int	ft_vprintf(const char *format, va_list ap);
int	ft_vsprintf(char *str, const char *format, va_list ap);
int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap);
int	ft_vasprintf(char **ret, const char *format, va_list ap);
int	ft_vdprintf(int fd, const char *format, va_list ap);
```
