//
// Created by sidahmedlahmer on 3/24/19.
//

#include <grid_test.h>

TEST_F(GridTest, GRID_Engine)
{
    //putable and add_engine
    ASSERT_EQ(grid_1->check_putable(engine1, true, 3, -1, -1), -100);
    ASSERT_EQ(grid_1->add_engine(nullptr, true, -1, -1), -100);
    ASSERT_EQ(grid_1->check_putable(engine1, true, 3, 1, 1), 1);
    ASSERT_EQ(grid_1->add_engine(engine1, true, 1, 1), 1);
    ASSERT_EQ(grid_1->check_putable(engine2, true, 4, 1, 1), -1);

    //proximity_check
    ASSERT_EQ(proximity_check(1, 1, nullptr), -100);
    ASSERT_EQ(proximity_check(-1, -1, engine1), -1);
    ASSERT_EQ(proximity_check(1, 1, engine1), 1);

    //get_engine
    ASSERT_EQ(grid_1->get_engine_x_y(1, 1), engine1);
    ASSERT_EQ(grid_1->get_engine_x_y(9, 9), nullptr);
    ASSERT_EQ(grid_1->get_engine_x_y(-1, -1), nullptr);

    //remove_engine
    ASSERT_EQ(grid_1->remove_engine(nullptr), -100);
    ASSERT_EQ(grid_1->remove_engine(engine1), 1);
    //pb: ASSERT_EQ(grid_1->remove_engine(engine2),-1);
}

TEST_F(GridTest, GRID_Shot)
{

    //check_one_position
    ASSERT_EQ(grid2->check_one_position(3, 3), 1);
    ASSERT_EQ(grid2->check_one_position(0, 0), 1);
    ASSERT_EQ(grid2->check_one_position(-4, 8), -1);
    ASSERT_EQ(grid2->check_one_position(10, 10), -1);

    //add engine to test shot
    ASSERT_EQ(grid_2->add_engine(engine1, true, 1, 1), 1);
    ASSERT_EQ(grid_2->add_engine(engine2, true, 3, 1), 1);
    ASSERT_EQ(grid_2->add_engine(engine3, true, 5, 1), 1);
    ASSERT_EQ(grid_2->add_engine(engine4, true, 7, 1), 1);
    ASSERT_EQ(grid_2->add_engine(engine5, true, 9, 1), 1);

    //normal_shot
    ASSERT_EQ(grid_2->normal_shot(1, 1, 1.0), 1);
    ASSERT_EQ(grid_2->normal_shot(1, 2, 1.0), 1);
    ASSERT_EQ(grid_2->normal_shot(1, 2, 1.0), 0);
    ASSERT_EQ(grid_1->normal_shot(1, 1, 1.0), 0);

    //incendiary shot
    ASSERT_EQ(grid_2->incendiary_shot(3, 1, 1.0), 1);
    ASSERT_EQ(grid_2->incendiary_shot(3, 0, 0.0), 0);
    ASSERT_EQ(grid_1->incendiary_shot(3, 0, 0.0), 0);

    //perforating_shot
    ASSERT_EQ(grid_2->perforating_shot(5, 1, 1.0), 1);
    ASSERT_EQ(grid_2->perforating_shot(5, 0, 0.0), 0);
    ASSERT_EQ(grid_1->perforating_shot(5, 0, 0.0), 0);

    //desactivate_square
    ASSERT_EQ(grid_2->desactivate_square(7, 0), 0);
    ASSERT_EQ(grid_2->desactivate_square(7, 1), 1);
    ASSERT_EQ(grid_1->desactivate_square(7, 1), 0);

    //burn_square
    ASSERT_EQ(grid_2->burn_square(9, 1), 1);
    ASSERT_EQ(grid_1->burn_square(9, 1), 0);

    //perforate_square
    ASSERT_EQ(grid_2->perforate_square(9, 2), 1);
    ASSERT_EQ(grid_1->perforate_square(9, 2), 0);
}

TEST_F(GridTest, GRID_Mutiple_shot)
{
    //add engine to test shot
    ASSERT_EQ(grid_3->add_engine(engine1, true, 1, 1), 1);
    ASSERT_EQ(grid_3->add_engine(engine2, true, 3, 1), 1);
    ASSERT_EQ(grid_3->add_engine(engine3, true, 5, 1), 1);
    ASSERT_EQ(grid_3->add_engine(engine4, true, 7, 1), 1);
    ASSERT_EQ(grid_3->add_engine(engine5, true, 9, 1), 1);

    //line_shot
    ASSERT_EQ(grid_3->line_shot(0, 0, 3, false, true, 1.0), 0);
    ASSERT_EQ(grid_3->line_shot(1, 1, 3, false, true, 1.0), 3);

    //vertical_line_shot
    ASSERT_EQ(grid_3->vertical_line_shot(7, 6, 3, false, 1.0), 1);
    ASSERT_EQ(grid_1->vertical_line_shot(7, 6, 3, false, 1.0), 0);

    //horizontal_line_shot
    ASSERT_EQ(grid_3->horizontal_line_shot(2, 2, 5, false, 1.0), 0);
    ASSERT_EQ(grid_3->horizontal_line_shot(3, 1, 5, false, 1.0), 4);

    //rectangular_shot
    ASSERT_EQ(grid_1->rectangular_shot(0, 0, 9, 9, false, 1.0), 0);
    ASSERT_EQ(grid_3->rectangular_shot(5, 1, 3, 9, true, 1.0), 3);

    //cross_shot
    ASSERT_EQ(grid_1->cross_shot(5, 5, 4, false, 1.0), 0);
    ASSERT_EQ(grid_3->cross_shot(9, 3, 2, false, 1.0), 3);

    //first_to_drawn
    grid_4->add_engine(engine4, false, 1, 4);
    grid_4->add_engine(engine5, false, 1, 6);
    ASSERT_EQ(grid_4->first_to_drawn(9, 9, true, false, 1.0), 0);
    ASSERT_EQ(grid_4->first_to_drawn(1, 0, true, false, 1.0), 1);
    ASSERT_EQ(grid_4->first_to_drawn(9, 6, false, false, 1.0), 2);
    ASSERT_EQ(grid_4->first_to_drawn(9, 7, false, false, 1.0), 0);
    ASSERT_EQ(grid_4->first_to_drawn(3, 0, true, false, 1.0), 1);
}

TEST_F(GridTest, GRID_Radar)
{

    //radar_one_square
    ASSERT_EQ(grid4->radar_one_square(1, 6), grid4[1][6]);
    ASSERT_EQ(grid4->radar_one_square(0, 9), grid4[0][9]);
    ASSERT_EQ(grid4->radar_one_square(-1, -1), nullptr);
}