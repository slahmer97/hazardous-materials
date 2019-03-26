//
// Created by sidahmedlahmer on 3/24/19.
//

#ifndef HAZARDOUS_MATERIALS_SQUARE_TEST_H
#define HAZARDOUS_MATERIALS_SQUARE_TEST_H

#include <Square.h>
#include <gtest/gtest.h>

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


#endif //HAZARDOUS_MATERIALS_SQUARE_TEST_H
