#ifndef DEF_GRID
#define DEF_GRID



#include "enum.h"
#include "square.h"

class Grid
{
private:
  Square grid[10][10];
  Square getSquare(int x, int y);

public:
  Grid();
  ~Grid();

  void add_engine(Engine *, int x, int y, ENGINE_TYPE);

  int normal_shot(int x, int y, float dammage = 1.f);

  int desactivate_square(int x, int y);

  int line_shot(int x, int y, int length, bool IEM, bool horizontal, float dammage = 1.f);

  int vertical_line_shot(int x, int y, int length, bool IEM, float dammage = 1.f);

  int horizontal_line_shot(int x, int y, int length, bool IEM, float dammage = 1.f);

  int rectangular_shot(int x, int y, int large, int length, bool IEM, float damage = 1.f);

  int cross_shot(int x, int y, int length, bool IEM, float damage = 1.f);

  int first_to_drawn(int x, int y, bool horizontal, bool IEM, float damage = 1.f);

  int proximity_check(int x, int y, Engine *);

  std::string get_my_grid();
  std::string get_enemy_grid();
};


#endif
