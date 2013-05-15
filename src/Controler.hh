//
// Controler.hh for src in /home/brunie_j/local/my/domusic/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 18 17:34:25 2013 Brunier Jean
// Last update Tue May 14 20:40:30 2013 Brunier Jean
//

#ifndef CONTROLER_HH_
# define CONTROLER_HH_

# include "Key.hh"
# include <linux/joystick.h>

class Controler
{
private:
  js_event		_event;
  int			_id;
  int			_fd;
  std::vector<int>	_axe;
  std::vector<int>	_but;
  int			_lastBut;
  char			_name[80];
  int			_null;

public:
  ~Controler();
  Controler(int id);
  void		proc();
  Key		getKey();
  bool		isOk() const;
  void		update();
  int		getLastBut();
};


#endif /* !CONTROLER_HH_ */
