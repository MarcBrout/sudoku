/*
** error.c for error in /home/duhieu_b/Prog_elem/sudoki-bi/res
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Feb 27 12:02:00 2016 benjamin duhieu
** Last update Sat Feb 27 23:17:40 2016 benjamin duhieu
*/

#include <unistd.h>

int	my_strlen(const char *str)
{
  int	i;

  i = -1;
  while (str && str[++i]);
  return (i);
}

int	my_puterror(const char *str)
{
  write(2, str, my_strlen(str));
  return (1);
}
