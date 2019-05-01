//
// Created by sidahmedlahmer on 3/24/19.
//

#include <grid_test.h>
#include <iostream>

TEST_F(GridTest, GRID_Engine)
{
    //putable and add_engine
    ASSERT_EQ(grid_1->check_putable(engine1, true, -1, -1), -1);
    ASSERT_EQ(grid_1->add_engine(nullptr, true, -1, -1), -100);
    ASSERT_EQ(grid_1->check_putable(engine1, true,1, 1), 1);
    ASSERT_EQ(grid_1->add_engine(engine1, true, 1, 1), 1);
    ASSERT_EQ(grid_1->check_putable(engine2, true, 1, 1), -1);
    ASSERT_EQ(grid_1->add_engine(engine2, false, 1, 1), -1);
    //proximity_check
    ASSERT_EQ(grid_1->proximity_check(1, 1, nullptr), -100);
    ASSERT_EQ(grid_1->proximity_check(-1, -1, engine1), -1);
    ASSERT_EQ(grid_1->proximity_check(1, 1, engine1), 1);
    ASSERT_EQ(grid_1->proximity_check(1, 1, engine2), -1);

    //get_engine
    ASSERT_EQ(grid_1->get_engine_x_y(1, 1), engine1);
    ASSERT_EQ(grid_1->get_engine_x_y(9, 9), nullptr);
    ASSERT_EQ(grid_1->get_engine_x_y(-1, -1), nullptr);

    //remove_engine
    ASSERT_EQ(grid_1->add_engine(engine1, true, 5, 5), -1);
    ASSERT_EQ(grid_1->remove_engine(nullptr), -100);
    ASSERT_EQ(grid_1->remove_engine(engine1), 1);
    ASSERT_EQ(grid_1->remove_engine(engine2), -1);
}

TEST_F(GridTest, GRID_Shot)
{

    //check_one_position
    ASSERT_EQ(grid_2->check_one_position(3, 3), 1);
    ASSERT_EQ(grid_2->check_one_position(0, 0), 1);
    ASSERT_EQ(grid_2->check_one_position(-4, 8), -1);
    ASSERT_EQ(grid_2->check_one_position(10, 10), -1);

    //add engine to test shot
    ASSERT_EQ(grid_2->check_putable(engine1, true, 1, 1), 1);
    ASSERT_EQ(grid_2->add_engine(engine1, true, 1, 1), 1);
    ASSERT_EQ(grid_2->check_putable(engine2, true, 1, 3), 1);
    ASSERT_EQ(grid_2->add_engine(engine2, true, 1, 3), 1);
    ASSERT_EQ(grid_2->check_putable(engine3, true, 1, 5), 1);
    ASSERT_EQ(grid_2->add_engine(engine3, true, 1, 5), 1);
    ASSERT_EQ(grid_2->check_putable(engine4, true, 1, 7), 1);
    ASSERT_EQ(grid_2->add_engine(engine4, true, 1, 7), 1);
    ASSERT_EQ(grid_2->check_putable(engine5, true, 1, 9), 1);
    ASSERT_EQ(grid_2->add_engine(engine5, true, 1, 9), 1);

    //normal_shot
    ASSERT_EQ(grid_2->normal_shot(-1, -1, 1.0), 0);
    ASSERT_EQ(grid_2->normal_shot(1, 1, 1.0), 1);
    ASSERT_EQ(grid_2->normal_shot(2, 1, 1.0), 1);
    ASSERT_EQ(grid_2->normal_shot(2, 1, 1.0), 0);
    ASSERT_EQ(grid_1->normal_shot(1, 1, 1.0), 0);

    //incendiary shot
    /*ASSERT_EQ(grid_2->incendiary_shot(3, 1, 1.0), 1);
    ASSERT_EQ(grid_2->incendiary_shot(3, 0, 0.0), 0);
    ASSERT_EQ(grid_1->incendiary_shot(3, 0, 0.0), 0);

    //perforating_shot
    ASSERT_EQ(grid_2->perforating_shot(5, 1, 1.0), 1);
    ASSERT_EQ(grid_2->perforating_shot(5, 0, 0.0), 0);
    ASSERT_EQ(grid_1->perforating_shot(5, 0, 0.0), 0);*/

    //desactivate_square
    ASSERT_EQ(grid_2->desactivate_square(0, 7), 0);
    ASSERT_EQ(grid_2->desactivate_square(1, 7), 1);
    ASSERT_EQ(grid_1->desactivate_square(1, 7), 0);

    //burn_square
   /* ASSERT_EQ(grid_2->burn_square(9, 1), 1);
    ASSERT_EQ(grid_1->burn_square(9, 1), 0);

    //perforate_square
    ASSERT_EQ(grid_2->perforate_square(9, 2), 1);
    ASSERT_EQ(grid_1->perforate_square(9, 2), 0);*/
}

TEST_F(GridTest, GRID_Mutiple_shot)
{
    //add engine to test shot
    ASSERT_EQ(grid_3->check_putable(engine1, true, 1, 1), 1);
    
    
    
    
    ASSERT_EQ(grid_3->add_engine(engine1, true, 1, 1), 1);
    ASSERT_EQ(grid_3->check_putable(engine2, true, 1, 3), 1);
    ASSERT_EQ(grid_3->add_engine(engine2, true, 1, 3), 1);
    ASSERT_EQ(grid_3->check_putable(engine3, true, 1, 5), 1);
    ASSERT_EQ(grid_3->add_engine(engine3, true, 1, 5), 1);
    ASSERT_EQ(grid_3->check_putable(engine4, true, 1, 7), 1);
    ASSERT_EQ(grid_3->add_engine(engine4, true, 1, 7), 1);
    ASSERT_EQ(grid_3->check_putable(engine5, true, 1, 9), 1);
    ASSERT_EQ(grid_3->add_engine(engine5, true, 1, 9), 1);

    //line_shot
    ASSERT_EQ(grid_3->line_shot(-1, -1, 3, false, true, 1.0), 0);
    ASSERT_EQ(grid_3->line_shot(0, 0, 3, false, true, 1.0), 0);
    ASSERT_EQ(grid_3->line_shot(1, 1, 3, false, true, 1.0), 3);

    //vertical_line_shot
    ASSERT_EQ(grid_3->vertical_line_shot(-1, -1, 3, false, 1.0), 0);
    ASSERT_EQ(grid_3->vertical_line_shot(1, 6, 3, false, 1.0), 1);
    ASSERT_EQ(grid_1->vertical_line_shot(1, 6, 3, false, 1.0), 0);

    //horizontal_line_shot
    ASSERT_EQ(grid_3->horizontal_line_shot(-1, -1, 5, false, 1.0), 0);
    ASSERT_EQ(grid_3->horizontal_line_shot(2, 2, 5, false, 1.0), 0);
    ASSERT_EQ(grid_3->horizontal_line_shot(1, 3, 5, false, 1.0), 4);

    //rectangular_shot
    ASSERT_EQ(grid_3->rectangular_shot(-3, -3, -1, -1, false, 1.0), 0);
    ASSERT_EQ(grid_1->rectangular_shot(0, 0, 9, 9, false, 1.0), 0);
    ASSERT_EQ(grid_3->rectangular_shot(1, 5, 4, 9, true, 1.0), 4);

    //cross_shot
    ASSERT_EQ(grid_3->cross_shot(-1, -1, 4, false, 1.0), 0);
    ASSERT_EQ(grid_1->cross_shot(5, 5, 4, false, 1.0), 0);
    ASSERT_EQ(grid_3->cross_shot(3, 9, 2, false, 1.0), 5);

}

TEST_F(GridTest, GRID_first_to_drawn_and_radar)
{
    //first_to_drawn
    ASSERT_EQ(grid_4->check_putable(engine4, false, 4, 1), 1);
    ASSERT_EQ(grid_4->add_engine(engine4, false, 4, 1),1);
    ASSERT_EQ(grid_4->check_putable(engine5, false, 6, 1), 1);
    ASSERT_EQ(grid_4->add_engine(engine5, false, 6, 1),1);

    ASSERT_EQ(grid_4->first_to_drawn(9, 9, true, false, 1.0), 0);
    ASSERT_EQ(grid_4->first_to_drawn(0, 2, true, false, 1.0), 1);
    ASSERT_EQ(grid_4->first_to_drawn(6, 9, false, false, 1.0), 2);
    ASSERT_EQ(grid_4->first_to_drawn(7, 9, false, false, 1.0), 0);
    ASSERT_EQ(grid_4->first_to_drawn(0, 3, true, false, 1.0), 1);

    //radar_one_square
    ASSERT_EQ(grid_4->radar_one_square(1, 6), grid_4->get(1,6));
    ASSERT_EQ(grid_4->radar_one_square(0, 9), grid_4->get(0,9));
    ASSERT_EQ(grid_4->radar_one_square(-1, -1), nullptr);
}
TEST_F(GridTest, GRID_move_rotate_Engine)
{
    ASSERT_EQ(engine1->move_engine(nullptr,false,1),-100);
    ASSERT_EQ(engine1->rotate_engine(nullptr,true,1),-100);

    ASSERT_EQ(engine1->move_engine(grid_1,false,1),-2);
    ASSERT_EQ(engine1->rotate_engine(grid_1,true,1),-2);


    ASSERT_EQ(grid_1->check_putable(engine1, true, 1, 1), 1);
    ASSERT_EQ(grid_1->add_engine(engine1, true, 1, 1), 1);


    ASSERT_EQ(engine1->move_engine(grid_2,false,1),-3);
    ASSERT_EQ(engine1->rotate_engine(grid_2,true,1),-3);
    
    engine1->desactivate_motor();
    ASSERT_EQ(engine1->move_engine(grid_1,false,1),-4);
    ASSERT_EQ(engine1->rotate_engine(grid_1,true,1),-4);
    engine1->activate_motor();

    ASSERT_EQ(engine1->move_engine(grid_1,false,10),-5);
    ASSERT_EQ(engine1->move_engine(grid_1,false,-1),-5);
    ASSERT_EQ(engine1->rotate_engine(grid_1,true,-1),-5);
    ASSERT_EQ(engine1->rotate_engine(grid_1,true,10),-5);
    
    ASSERT_EQ(engine1->move_engine(grid_1,false,1),1);
    ASSERT_EQ(engine1->move_engine(grid_1,true,1),1);
    ASSERT_EQ(engine1->rotate_engine(grid_1,false,1),1);
    ASSERT_EQ(engine1->rotate_engine(grid_1,true,1),1);


    ASSERT_EQ(grid_1->check_putable(engine2, false, 1, 2), 1);
    ASSERT_EQ(grid_1->add_engine(engine2, false, 1, 2), 1);

    ASSERT_EQ(engine2->move_engine(grid_1,false,1),-1);
    ASSERT_EQ(engine1->rotate_engine(grid_1,true,0),-1);
    
    ASSERT_EQ(engine2->move_engine(grid_1,true,1),1);
    ASSERT_EQ(engine1->rotate_engine(grid_1,true,1),1);
    ASSERT_EQ(engine1->rotate_engine(grid_1,false,1),1);
    ASSERT_EQ(engine2->move_engine(grid_1,false,1),1);

    ASSERT_EQ(grid_1->normal_shot(1, 1, 1.0), 1);
    ASSERT_EQ(grid_1->normal_shot(1, 2, 1.0), 1);
    ASSERT_EQ(engine1->move_engine(grid_1,false,1),-4);
    ASSERT_EQ(engine1->rotate_engine(grid_1,true,1),-4);
    ASSERT_EQ(engine2->move_engine(grid_1,true,1),-4);
    ASSERT_EQ(engine2->rotate_engine(grid_1,true,1),-4);
    
}
TEST_F(GridTest, 2GRID_equals)
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            ASSERT_EQ(grid_1->get(i,j)->squares_equals(grid_2->get(i,j)), true);
        }
    }

    ASSERT_EQ(grid_1->check_putable(engine2, false, 5, 5), 1);
    ASSERT_EQ(grid_1->add_engine(engine2, false, 5, 5), 1);

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(i==5&&j>=5&&j<=8)
                ASSERT_NE(grid_1->get(i,j)->squares_equals(grid_2->get(i,j)), true);
            else
                ASSERT_EQ(grid_1->get(i,j)->squares_equals(grid_2->get(i,j)), true);
        }
    }

    ASSERT_EQ(grid_2->check_putable(engine6, false, 5, 5), 1);
    ASSERT_EQ(grid_2->add_engine(engine6, false, 5, 5), 1);

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            ASSERT_EQ(grid_1->get(i,j)->squares_equals(grid_2->get(i,j)), true);
        }
    }
}