//
// Created by stevlulz on 3/6/19.
//
#include <engine_test.h>
#include <square_test.h>
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/*
class SquareTest : public ::testing::Test {
protected:
    Square*m_square;
    Engine * m_engine;

    void SetUp() override {
        Test::SetUp();

    }

    void TearDown() override {
        Test::TearDown();
    }

public:
    SquareTest(){
        m_square = new Square();
        m_engine = new Engine(3,ENGINE_TYPE::PORTE_AVION);
    }
    ~SquareTest(){
        delete(m_square);
        delete(m_engine);
    }
};
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

 */