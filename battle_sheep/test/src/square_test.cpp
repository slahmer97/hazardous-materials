//
// Created by sidahmedlahmer on 3/24/19.
//

#include <square_test.h>

TEST_F(SquareTest,Init_Constructor){
ASSERT_EQ(m_square->get_engine(), nullptr);
ASSERT_EQ(m_square->get_health_pr(),.0F);
ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::NONE);
}
TEST_F(SquareTest,Setters_Getters){
m_square->set_health_pr(1);
m_square->set_engine(m_engine);
m_square->set_square_type(SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED);

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED);
ASSERT_EQ(m_square->get_health_pr(),1.0F);
ASSERT_EQ(m_square->get_engine(),m_engine);
ASSERT_NE(m_square->get_engine(), nullptr);

m_square->set_health_pr(-1.2f);                                                                                               
ASSERT_EQ(m_square->get_health_pr(),0.0F);

}

TEST_F(SquareTest,TwoSquare_Equales){
m_square->set_health_pr(1);
m_square->set_engine(m_engine);
m_square->set_square_type(SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED);

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED);
ASSERT_EQ(m_square->get_health_pr(),1.0F);
ASSERT_EQ(m_square->get_engine(),m_engine);
ASSERT_NE(m_square->get_engine(), nullptr);

ASSERT_EQ(m_square->squares_equals(nullptr),false);
ASSERT_NE(m_square->squares_equals(nullptr),true);

ASSERT_EQ(m_square->squares_equals(m_square2),false);
ASSERT_NE(m_square->squares_equals(m_square2),true);

m_square2->set_health_pr(1);

ASSERT_EQ(m_square->squares_equals(m_square2),false);
ASSERT_NE(m_square->squares_equals(m_square2),true);

m_square2->set_engine(m_engine);

ASSERT_EQ(m_square->squares_equals(m_square2),false);
ASSERT_NE(m_square->squares_equals(m_square2),true);

m_square2->set_square_type(SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED);

ASSERT_EQ(m_square->squares_equals(m_square2),true);
ASSERT_NE(m_square->squares_equals(m_square2),false);

m_square->set_health_pr(-1.2f);
ASSERT_EQ(m_square->get_health_pr(),0.0F);

ASSERT_EQ(m_square->squares_equals(m_square2),false);
ASSERT_NE(m_square->squares_equals(m_square2),true);

}

TEST_F(SquareTest,desactivate_activate){

m_square->set_square_type(SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED);

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED);


m_square->activate_motor();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED);

m_square->desactivate_motor();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED);



m_square->activate_weapon();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_WEAPON);



m_square->activate_motor();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_WEAPON);

m_square->desactivate_motor();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_WEAPON);



m_square->desactivate_weapon();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED);

m_square->activate_motor();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED);

m_square->desactivate_motor();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED);



m_square->set_square_type(SQUARE_TYPE::ENGINE_MOTOR);

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_MOTOR);

m_square->activate_weapon();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_MOTOR);

m_square->desactivate_weapon();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_MOTOR);


m_square->desactivate_motor();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED);

m_square->activate_weapon();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED);

m_square->desactivate_weapon();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED);



m_square->activate_motor();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_MOTOR);

m_square->activate_weapon();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_MOTOR);

m_square->desactivate_weapon();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_MOTOR);


m_square->set_square_type(SQUARE_TYPE::ENGINE_PART);


m_square->desactivate_motor();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_PART);

m_square->activate_motor();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_PART);

m_square->activate_weapon();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_PART);

m_square->desactivate_weapon();

ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_PART);
}


TEST_F(SquareTest,decrease_health){

m_square->set_health_pr(1);
ASSERT_EQ(m_square->decrease_health(1),0);

m_square->set_engine(m_engine);
m_engine->set_x(1);
m_engine->set_y(1);
ASSERT_EQ(m_square->decrease_health(1),0);

m_square->set_square_type(SQUARE_TYPE::NONE);
ASSERT_EQ(m_square->decrease_health(1),0);

m_square->set_square_type(SQUARE_TYPE::ENGINE_WEAPON_DEAD);
ASSERT_EQ(m_square->decrease_health(1),0);

m_square->set_square_type(SQUARE_TYPE::ENGINE_MOTOR_DEAD);
ASSERT_EQ(m_square->decrease_health(1),0);

m_square->set_square_type(SQUARE_TYPE::ENGINE_PART_DEAD);
ASSERT_EQ(m_square->decrease_health(1),0);

m_square->set_square_type(SQUARE_TYPE::ENGINE_WEAPON);
ASSERT_EQ(m_square->decrease_health(0.0f),1);
ASSERT_EQ(m_square->decrease_health(-1.0f),0);
ASSERT_EQ(m_square->get_health_pr(),1.0f);
ASSERT_EQ(m_square->decrease_health(2.0f),1);
ASSERT_EQ(m_square->get_health_pr(),0.0f);
ASSERT_EQ(m_square->get_engine()->get_current_health_point(),1.0f);
ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_WEAPON_DEAD);

m_square->set_health_pr(1);
m_square->set_square_type(SQUARE_TYPE::ENGINE_MOTOR);
ASSERT_EQ(m_square->decrease_health(0.3f),1);
ASSERT_EQ(m_square->get_health_pr(),0.7f);
ASSERT_EQ(m_square->get_engine()->get_current_health_point(),0.7f);
ASSERT_EQ(m_square->decrease_health(0.7f),1);
ASSERT_EQ(m_square->get_health_pr(),0.0f);
ASSERT_EQ(m_square->get_engine()->get_current_health_point(),0.0f);
ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_MOTOR_DEAD);

m_square->set_health_pr(1);
m_square->set_square_type(SQUARE_TYPE::ENGINE_PART);
ASSERT_EQ(m_square->decrease_health(1.0f),1);
ASSERT_EQ(m_square->get_health_pr(),0.0f);
ASSERT_EQ(m_square->get_engine()->get_current_health_point(),0.0f);
ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_PART_DEAD);

}

TEST_F(SquareTest,increase_health){

m_square->set_health_pr(0.1f);
ASSERT_EQ(m_square->increase_health(1),0);

m_square->set_engine(m_engine);
m_engine->set_x(1);
m_engine->set_y(1);
ASSERT_EQ(m_square->increase_health(1),0);

m_square->set_square_type(SQUARE_TYPE::NONE);
ASSERT_EQ(m_square->increase_health(1),0);

m_square->set_square_type(SQUARE_TYPE::ENGINE_WEAPON);
ASSERT_EQ(m_square->increase_health(0.0f),1);
ASSERT_EQ(m_square->increase_health(-1.0f),0);
ASSERT_EQ(m_square->get_health_pr(),0.1f);
ASSERT_EQ(m_square->increase_health(2),1);
ASSERT_EQ(m_square->get_health_pr(),1.0f);
ASSERT_EQ(m_square->get_engine()->get_current_health_point(),3.0f);
ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_WEAPON);

m_square->set_health_pr(0.1f);
m_square->set_square_type(SQUARE_TYPE::ENGINE_MOTOR);
ASSERT_EQ(m_square->increase_health(0.3f),1);
ASSERT_EQ(m_square->get_health_pr(),0.4f);
ASSERT_EQ(m_square->get_engine()->get_current_health_point(),3.0f);
ASSERT_EQ(m_square->increase_health(0.6f),1);
ASSERT_EQ(m_square->get_health_pr(),1.0f);
ASSERT_EQ(m_square->get_engine()->get_current_health_point(),3.0f);
ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_MOTOR);

m_square->set_health_pr(0.1f);
m_square->set_square_type(SQUARE_TYPE::ENGINE_PART);
ASSERT_EQ(m_square->increase_health(0.9f),1);
ASSERT_EQ(m_square->get_health_pr(),1.0f);
ASSERT_EQ(m_square->get_engine()->get_current_health_point(),3.0f);
ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_PART);

m_square->set_health_pr(0.0f);
m_square->set_square_type(SQUARE_TYPE::ENGINE_PART_DEAD);
ASSERT_EQ(m_square->increase_health(1.0f),1);
ASSERT_EQ(m_square->get_health_pr(),1.0f);
ASSERT_EQ(m_square->get_engine()->get_current_health_point(),3.0f);
ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_PART);


m_square->set_health_pr(0.0f);
m_square->set_square_type(SQUARE_TYPE::ENGINE_WEAPON_DEAD);
ASSERT_EQ(m_square->increase_health(0.1f),1);
ASSERT_EQ(m_square->get_health_pr(),0.1f);
ASSERT_EQ(m_square->get_engine()->get_current_health_point(),3.0f);
ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_WEAPON);


m_square->set_health_pr(0.0f);
m_square->set_square_type(SQUARE_TYPE::ENGINE_MOTOR_DEAD);
ASSERT_EQ(m_square->increase_health(0.1f),1);
ASSERT_EQ(m_square->get_health_pr(),0.1f);
ASSERT_EQ(m_square->get_engine()->get_current_health_point(),3.0f);
ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_MOTOR);


m_square->set_health_pr(0.0f);
m_square->set_square_type(SQUARE_TYPE::ENGINE_PART_DEAD);
ASSERT_EQ(m_square->increase_health(0.1f),1);
ASSERT_EQ(m_square->get_health_pr(),0.1f);
ASSERT_EQ(m_square->get_engine()->get_current_health_point(),3.0f);
ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_PART);

}

TEST_F(SquareTest,decrease_increase_health){

m_square->set_health_pr(1);
m_square->set_engine(m_engine);
m_engine->set_x(1);
m_engine->set_y(1);
m_square->set_square_type(SQUARE_TYPE::ENGINE_WEAPON);


ASSERT_EQ(m_square->decrease_health(1.0f),1);
ASSERT_EQ(m_square->get_health_pr(),0.0f);
ASSERT_EQ(m_square->get_engine()->get_current_health_point(),2.0f);
ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_WEAPON_DEAD);

ASSERT_EQ(m_square->increase_health(1.0f),1);
ASSERT_EQ(m_square->get_health_pr(),1.0f);
ASSERT_EQ(m_square->get_engine()->get_current_health_point(),3.0f);
ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_WEAPON);


m_square->set_square_type(SQUARE_TYPE::ENGINE_MOTOR);


ASSERT_EQ(m_square->decrease_health(1.0f),1);
ASSERT_EQ(m_square->get_health_pr(),0.0f);
ASSERT_EQ(m_square->get_engine()->get_current_health_point(),2.0f);
ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_MOTOR_DEAD);

ASSERT_EQ(m_square->increase_health(1.0f),1);
ASSERT_EQ(m_square->get_health_pr(),1.0f);
ASSERT_EQ(m_square->get_engine()->get_current_health_point(),3.0f);
ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_MOTOR);


m_square->set_square_type(SQUARE_TYPE::ENGINE_PART);


ASSERT_EQ(m_square->decrease_health(1.0f),1);
ASSERT_EQ(m_square->get_health_pr(),0.0f);
ASSERT_EQ(m_square->get_engine()->get_current_health_point(),2.0f);
ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_PART_DEAD);

ASSERT_EQ(m_square->increase_health(1.0f),1);
ASSERT_EQ(m_square->get_health_pr(),1.0f);
ASSERT_EQ(m_square->get_engine()->get_current_health_point(),3.0f);
ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_PART);

}