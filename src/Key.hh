//
// Key.hh for src in /home/brunie_j/local/my/domusic/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 01:21:14 2013 Brunier Jean
// Last update Tue May 14 21:41:39 2013 Brunier Jean
//

#ifndef KEY_HH_
# define KEY_HH_

# include <vector>

# define LAST_STICK	(Key::R2)

class Key
{
public:
  enum
    {
      HOR1,
      VERT1,
      HOR2,
      VERT2,
      L2,
      R2,
      X,
      A,
      B,
      Y,
      L1,
      R1,
      COUNT
    };
private:
  int		_prevVal[Key::COUNT];
  int		*_val[Key::COUNT];
  int		_delta[Key::COUNT];

public:
  Key();
  ~Key(){}
  int	operator[](int i) const;
  int	operator()(int i) const;
  void	update();
  int	cur() const;
  int	*&ptr(int i);
};

#endif /* !KEY_HH_ */
