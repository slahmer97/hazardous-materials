//
// Created by sidahmedlahmer on 3/24/19.
//

#include <engine_test.h>


TEST_F(EngineTest,ENGINE_Init_Contructor_TEST){

    ASSERT_EQ(m_engine1->get_engine_type(),ENGINE_TYPE::NOT_INTRODUCED);
    ASSERT_EQ(m_engine1->get_size(),3);
    ASSERT_EQ(m_engine1->get_current_health_point(),m_engine1->get_size());
    ASSERT_EQ(m_engine1->get_is_on_grid(),false);
    ASSERT_EQ(m_engine1->get_motor_place(),0);
    ASSERT_EQ(m_engine1->get_weapon_place(),2);
    ASSERT_EQ(m_engine1->get_x(),-1);
    ASSERT_EQ(m_engine1->get_y(),-1);
    ASSERT_EQ(m_engine1->get_motor_state(),MOTOR_STATE::MOTOR);


    ASSERT_EQ(m_engine2->get_engine_type(),ENGINE_TYPE::NOT_INTRODUCED);
    ASSERT_EQ(m_engine2->get_size(),3);
    ASSERT_EQ(m_engine2->get_current_health_point(),m_engine1->get_size());
    ASSERT_EQ(m_engine2->get_is_on_grid(),false);
    ASSERT_EQ(m_engine2->get_motor_place(),0);
    ASSERT_EQ(m_engine2->get_weapon_place(),2);
    ASSERT_EQ(m_engine2->get_x(),-1);
    ASSERT_EQ(m_engine2->get_y(),-1);
    ASSERT_EQ(m_engine2->get_motor_state(),MOTOR_STATE::MOTOR);

}
TEST_F(EngineTest,ENGINE_Getter_Setters_TEST){

    m_engine1->set_horizontal(true);
    ASSERT_EQ(m_engine1->is_horizontal(),-1);
    m_engine1->set_horizontal(false);
    ASSERT_EQ(m_engine1->is_horizontal(),-1);

    ASSERT_EQ(m_engine1->get_is_on_grid(),false);

    m_engine1->set_is_on_grid(true);
    ASSERT_EQ(m_engine1->get_is_on_grid(), false);

    m_engine1->set_is_on_grid(false);
    ASSERT_EQ(m_engine1->get_is_on_grid(), false);

    m_engine1->set_x(1);

    ASSERT_EQ(m_engine1->get_x(),-1);
    ASSERT_EQ(m_engine1->get_is_on_grid(),false);

    m_engine1->set_is_on_grid(true);
    ASSERT_EQ(m_engine1->get_is_on_grid(), false);


    m_engine1->set_y(0);

    ASSERT_EQ(m_engine1->get_y(),0);
    ASSERT_EQ(m_engine1->get_x(),1);
    ASSERT_EQ(m_engine1->get_is_on_grid(),true);


    m_engine1->set_is_on_grid(false);
    ASSERT_EQ(m_engine1->get_is_on_grid(), false);

    m_engine1->set_horizontal(false);
    ASSERT_EQ(m_engine1->is_horizontal(), -1);

    m_engine1->set_horizontal(true);
    ASSERT_EQ(m_engine1->is_horizontal(),-1);

}
TEST_F(EngineTest,ENGINE_ACTIVATE_DESACTIVATE_TEST){

    ASSERT_EQ(m_engine1->get_motor_state(),MOTOR_STATE::MOTOR);
    m_engine1->desactivate_motor();
    ASSERT_EQ(m_engine1->get_motor_state(),MOTOR_STATE::MOTOR_DESACTIVATED);
    m_engine1->kill_motor();
    ASSERT_EQ(m_engine1->get_motor_state(),MOTOR_STATE::MOTOR_DEAD);

    ASSERT_EQ(m_engine1->get_weapon_state(),WEAPON_STATE::WEAPON);
    m_engine1->desactivate_weapon();
    ASSERT_EQ(m_engine1->get_weapon_state(),WEAPON_STATE::WEAPON_DESACTIVATED);

    m_engine1->kill_weapon();
    ASSERT_EQ(m_engine1->get_weapon_state(),WEAPON_STATE::WEAPON_DEAD);



}
