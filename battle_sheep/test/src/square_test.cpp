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