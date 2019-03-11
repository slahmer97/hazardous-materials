//
// Created by stevlulz on 3/6/19.
//
#include <gtest/gtest.h>
#include <Square.h>

class EngineTest : public  ::testing::Test{
protected:
    Engine* m_engine1,*m_engine2,*m_engine3;
    void SetUp() override{
        Test::SetUp();
        m_engine1 = new Engine(3);
        m_engine2 = new Engine(-1);
        m_engine3 = new Engine(4,ENGINE_TYPE::CONTRE_TORPILLEUR);
    }

    void TearDown() override {
        Test::TearDown();
        delete(m_engine1);
        delete(m_engine3);
        delete(m_engine2);

    }
    EngineTest(){
        m_engine1 = new Engine(3,ENGINE_TYPE::CONTRE_TORPILLEUR);
    }
    ~EngineTest(){
        delete(m_engine1);
        delete(m_engine3);
        delete(m_engine2);
    }
};


TEST_F(EngineTest,ENGINE_Init_Contructor_TEST){

    ASSERT_EQ(m_engine1->get_engine_type(),ENGINE_TYPE::NOT_INTRODUCED);
    ASSERT_EQ(m_engine1->get_size(),3);
    ASSERT_EQ(m_engine1->get_current_health_point(),m_engine1->get_size());
    ASSERT_EQ(m_engine1->get_is_on_grid(),false);
    ///ASSERT_EQ(m_engine1->get_motor_place(),-1);
    ASSERT_EQ(m_engine1->get_weapon_place(),-1);
    ASSERT_EQ(m_engine1->get_x(),-1);
    ASSERT_EQ(m_engine1->get_y(),-1);
    ASSERT_EQ(m_engine1->get_motor_state(),MOTOR_STATE::MOTOR);


    ASSERT_EQ(m_engine2->get_engine_type(),ENGINE_TYPE::NOT_INTRODUCED);
    ASSERT_EQ(m_engine2->get_size(),3);
    ASSERT_EQ(m_engine2->get_current_health_point(),m_engine1->get_size());
    ASSERT_EQ(m_engine2->get_is_on_grid(),false);
    ////ASSERT_EQ(m_engine1->get_motor_place(),-1);
    ASSERT_EQ(m_engine2->get_weapon_place(),-1);
    ASSERT_EQ(m_engine2->get_x(),-1);
    ASSERT_EQ(m_engine2->get_y(),-1);
    ASSERT_EQ(m_engine2->get_motor_state(),MOTOR_STATE::MOTOR);



    ASSERT_EQ(m_engine2->get_engine_type(),ENGINE_TYPE::NOT_INTRODUCED);
    ASSERT_EQ(m_engine2->get_size(),3);
    ASSERT_EQ(m_engine2->get_current_health_point(),m_engine1->get_size());
    ASSERT_EQ(m_engine2->get_is_on_grid(),false);
    ////ASSERT_EQ(m_engine1->get_motor_place(),-1);
    ASSERT_EQ(m_engine2->get_weapon_place(),-1);
    ASSERT_EQ(m_engine2->get_x(),-1);
    ASSERT_EQ(m_engine2->get_y(),-1);
    ASSERT_EQ(m_engine2->get_motor_state(),MOTOR_STATE::MOTOR);

}
TEST_F(EngineTest,ENGINE_Getter_Setters_TEST){

    m_engine1->set_horizontal(true);
    ASSERT_EQ(m_engine1->is_horizontal(),true);
    m_engine1->set_horizontal(false);
    ASSERT_EQ(m_engine1->is_horizontal(),false);

    ASSERT_EQ(m_engine1->get_is_on_grid(),false);

    m_engine1->set_is_on_grid(true);
    ASSERT_EQ(m_engine1->get_is_on_grid(), false);

    m_engine1->set_is_on_grid(false);
    ASSERT_EQ(m_engine1->get_is_on_grid(), false);

    m_engine1->set_x(1);

    ASSERT_EQ(m_engine1->get_x(),1);
    ASSERT_EQ(m_engine1->get_is_on_grid(),false);

    m_engine1->set_is_on_grid(true);
    ASSERT_EQ(m_engine1->get_is_on_grid(), false);

    m_engine1->set_y(0);

    ASSERT_EQ(m_engine1->get_y(),0);
    ASSERT_EQ(m_engine1->get_is_on_grid(),true);


    m_engine1->set_is_on_grid(false);
    ASSERT_EQ(m_engine1->get_is_on_grid(), false);


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