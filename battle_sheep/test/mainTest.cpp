//
// Created by stevlulz on 3/6/19.
//
#include <gtest/gtest.h>
#include <Square.h>

struct SquareTest : testing::Test{
    Square* m_square;
    SquareTest(){
        m_square = new Square;
    }

};
TEST_F(SquareTest,Init_Constructor){
    ASSERT_EQ(m_square->get_engine(), nullptr);
    ASSERT_EQ(m_square->get_health_pr(),.0F);
    ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::NONE);
}
TEST_F(SquareTest,Setters_Getters){
    auto * e = new Engine(1,ENGINE_TYPE::PORTE_AVION);
    m_square->set_health_pr(1);
    m_square->set_engine(e);
    m_square->set_square_type(SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED);

    ASSERT_EQ(m_square->get_square_type(),SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED);
    ASSERT_EQ(m_square->get_health_pr(),1.0F);
    ASSERT_EQ(m_square->get_engine(),e);
    ASSERT_NE(m_square->get_engine(), nullptr);


    m_square->set_health_pr(-1.2f);
    ASSERT_EQ(m_square->get_health_pr(),0.0F);

}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}