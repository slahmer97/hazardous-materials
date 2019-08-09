//
// Created by sidahmedlahmer on 3/24/19.
//

#ifndef HAZARDOUS_MATERIALS_TEST2_H
#define HAZARDOUS_MATERIALS_TEST2_H
#include <gtest/gtest.h>
#include <Engine.h>
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




#endif //HAZARDOUS_MATERIALS_TEST2_H
