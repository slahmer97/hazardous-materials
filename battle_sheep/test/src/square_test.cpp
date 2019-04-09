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

m_square->set_health_pr(1);

ASSERT_EQ(m_square->squares_equals(m_square2),false);
ASSERT_NE(m_square->squares_equals(m_square2),true);

m_square->set_engine(m_engine);

ASSERT_EQ(m_square->squares_equals(m_square2),false);
ASSERT_NE(m_square->squares_equals(m_square2),true);

m_square->set_square_type(SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED);

ASSERT_EQ(m_square->squares_equals(m_square2),true);
ASSERT_NE(m_square->squares_equals(m_square2),false);

m_square->set_health_pr(-1.2f);
ASSERT_EQ(m_square->get_health_pr(),0.0F);

ASSERT_EQ(m_square->squares_equals(m_square2),false);
ASSERT_NE(m_square->squares_equals(m_square2),true);

}

TEST_F(SquareTest,desactivate_activate){
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

m_square->set_health_pr(1);

ASSERT_EQ(m_square->squares_equals(m_square2),false);
ASSERT_NE(m_square->squares_equals(m_square2),true);

m_square->set_engine(m_engine);

ASSERT_EQ(m_square->squares_equals(m_square2),false);
ASSERT_NE(m_square->squares_equals(m_square2),true);

m_square->set_square_type(SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED);

ASSERT_EQ(m_square->squares_equals(m_square2),true);
ASSERT_NE(m_square->squares_equals(m_square2),false);

m_square->set_health_pr(-1.2f);
ASSERT_EQ(m_square->get_health_pr(),0.0F);

ASSERT_EQ(m_square->squares_equals(m_square2),false);
ASSERT_NE(m_square->squares_equals(m_square2),true);

}