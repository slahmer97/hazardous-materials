//
// Created by sidahmedlahmer on 3/24/19.
//

#ifndef HAZARDOUS_MATERIALS_GRID_TEST_H
#define HAZARDOUS_MATERIALS_GRID_TEST_H
#include <gtest/gtest.h>
#include <Grid.h>
class GridTest : public ::testing::Test
{
  protected:
    Grid * grid_1;
    Grid * grid_2;
    Grid * grid_3;
    Grid * grid_4;
    Engine * engine1;
    Engine * engine2;
    Engine * engine3;
    Engine * engine4;
    Engine * engine5;
    void SetUp() override {
      Test::SetUp();

    }

    void TearDown() override {
      Test::TearDown();
    }

  public:
    GridTest(){
      grid_1 = new Grid();
      grid_2 = new Grid();
      grid_3 = new Grid();
      grid_4 = new Grid();
      engine1 = new Engine(3, ENGINE_TYPE::CONTRE_TORPILLEUR);
      engine2 = new Engine(4, ENGINE_TYPE::TORPILLEUR);
      engine3 = new Engine(2, ENGINE_TYPE::PATROUILE);
      engine4 = new Engine(2, ENGINE_TYPE::CROISEUR);
      engine5 = new Engine(5, ENGINE_TYPE::PORTE_AVION);
    }
    ~GridTest(){
      delete(grid_1);
      delete(grid_2);
      delete(grid_3);
      delete(grid_4);
      delete(engine1);
      delete(engine2);
      delete(engine3);
      delete(engine4);
      delete(engine5);
    }
};

#endif //HAZARDOUS_MATERIALS_GRID_TEST_H

