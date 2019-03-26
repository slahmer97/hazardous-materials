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
    void set();
};

#endif //HAZARDOUS_MATERIALS_GRID_TEST_H
