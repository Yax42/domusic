//
// Key.cpp for src in /home/brunie_j/local/my/domusic/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 01:26:10 2013 Brunier Jean
// Last update Tue May 14 21:01:13 2013 Brunier Jean
//

#include "Key.hh"

# define MPOS(x)			(((x) < 0) ? -(x) : (x))
# define MSIGN(x)			(((x) > 0) ? 1 : (((x) < 0) ? -1 : 0))

Key::Key()
{
}

int	Key::operator[](int i) const
{
  if (i > LAST_STICK)
    return (_delta[i]);
  if (MPOS(*_val[i]) < 500)
    return (0);
  if ((MPOS(*_val[VERT1]) + 200 > MPOS(*_val[HOR1])) ==
      (i == VERT1))
    return (MSIGN(*_val[i]));
  return (0);
}

int	Key::operator()(int i) const
{
  if (i <= LAST_STICK && *_val[i] > -500 && *_val[i] < 500)
    return (0);
  return (*_val[i]);
}

void	Key::update()
{
  for (int i = A; i < COUNT; i++)
    {
      _delta[i] = *_val[i] - _prevVal[i];
      _prevVal[i] = *_val[i];
    }
}

int	Key::cur() const
{
  if (_delta[A] == 1)
    return (A);
  if (_delta[B] == 1)
    return (B);
  if (_delta[X] == 1)
    return (X);
  if (_delta[Y] == 1)
    return (Y);
  return (0);
}
int	*&Key::ptr(int i)
{
  return (_val[i]);
}
