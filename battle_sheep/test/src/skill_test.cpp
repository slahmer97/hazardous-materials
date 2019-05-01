//
// Created by sidahmedlahmer on 3/24/19.
//
#include <skill_test.h>
#include <iostream>

TEST_F(SkillTest, Skill_points)
{
    ASSERT_EQ(skill1->get_engine_type(),ENGINE_TYPE::CONTRE_TORPILLEUR);
    ASSERT_EQ(skill2->get_engine_type(),ENGINE_TYPE::TORPILLEUR);
    ASSERT_EQ(skill3->get_engine_type(),ENGINE_TYPE::PATROUILE);
    ASSERT_EQ(skill1->get_points(),100);
    ASSERT_EQ(skill2->get_points(),100);
    ASSERT_EQ(skill3->get_points(),100);
    ASSERT_EQ(skill1->decrease_points(0),100);
    ASSERT_EQ(skill1->decrease_points(10),90);
    ASSERT_EQ(skill1->decrease_points(100),0);
    ASSERT_EQ(skill1->decrease_points(-100),-1);
    ASSERT_EQ(skill2->increase_points(0),100);
    ASSERT_EQ(skill2->increase_points(100),200);
    ASSERT_EQ(skill2->increase_points(-100),-1);
}