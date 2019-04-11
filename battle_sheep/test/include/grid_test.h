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
    Grid g1;
    void SetUp() override {
      Test::Setup();
      grid_1 = new Grid();
      grid_2 = new Grid();
      grid_3 = new Grid();
      engine1 = new Engine(3, ENGINE_TYPE::CONTRE_TORPILLEUR);
      engine2 = new Engine(4, ENGINE_TYPE::TORPILLEUR);
      engine3 = new Engine(1, ENGINE_TYPE::PATROUILLE);
      engine4 = new Engine(2, ENGINE_TYPE::CROISEUR);
      engine5 = new Engine(5, ENGINE_TYPE::PORTE_AVION;

    }

    void TearDown() override {
      Test::TearDown();
    }

    GridTest(){
      grid_1 = new Grid();
    }
    ~GridTest(){
      delete(grid_1);
      delete(grid_2);
      delete(grid_3);
    }
};

#endif //HAZARDOUS_MATERIALS_GRID_TEST_H

