//
// Input.hh for src in /home/brunie_j/local/my/domusic/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 13 22:34:54 2013 Brunier Jean
// Last update Tue May 14 20:59:43 2013 Brunier Jean
//

#ifndef INPUT_HH_
# define INPUT_HH_

# include <SDL/SDL.h>
# include <vector>

# include "Key.hh"
# include "Controler.hh"

# define InputI		(*Input::get())

#define NB_CTRL		20

class Input
{
private:
  bool				_quitKey;
  int				_kb[SDLK_LAST];
  SDL_Event			_event;
  std::vector<Controler *>	_ctrl;
  int				_axe[2];

/* SINGLETON */
private:
  static Input		*_inst;
private:
  virtual ~Input();
  Input();
  Input(const Input &other);
  Input &operator=(const Input &other);
public:
  static void		create();
  static Input		*get();
  static void		destroy();
/******/

public:
  bool		operator[](int i);
  bool		operator()(int i);
  bool		isQuit();
  int		update();
  int		nbCtrl() const;
  Key		getKBKey();
  Key		getCtrlKey(int id);
  void		proc();
  int		getLastBut(int id);
};

#endif /* !INPUT_HH_ */
