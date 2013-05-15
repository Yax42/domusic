//
// Piano.hh for src in /home/brunie_j/local/my/domusic/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue May 14 21:49:57 2013 Brunier Jean
// Last update Wed May 15 08:56:28 2013 Brunier Jean
//

#ifndef PIANO_HH_
# define PIANO_HH_

# include "Sound.hh"

class Piano
{
private:
  Sound		*_sound;
  int		_keys[4][Sound::COUNT];
public:
  Piano(int pattern = 0);
  ~Piano();
  void		proc();
};

#endif /* !PIANO_HH_ */
