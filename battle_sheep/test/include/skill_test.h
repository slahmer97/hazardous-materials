//
// Created by sidahmedlahmer on 3/24/19.
//

#ifndef HAZARDOUS_MATERIALS_SKILL_TEST_H
#define HAZARDOUS_MATERIALS_SKILL_TEST_H
#include <gtest/gtest.h>
#include <FactorySkill.h>
class SkillTest : public ::testing::Test
{
  protected:
    Grid * grid_1;
    Grid * grid_2;
    Grid * grid_3;
    Grid * grid_4;
    Engine * engine1;
    Engine * engine2;
    Engine * engine3;
    Engine * engine4;
    Engine * engine5;
    Engine * engine6;
    Skill * skill1;
    Skill * skill2;
    Skill * skill3;
    void SetUp() override {
      Test::SetUp();

    }

    void TearDown() override {
      Test::TearDown();
    }

  public:
    SkillTest(){
      grid_1 = new Grid();
      grid_2 = new Grid();
      grid_3 = new Grid();
      grid_4 = new Grid();
      skill1 = new Skill(ENGINE_TYPE::CONTRE_TORPILLEUR);
      skill2 = new Skill(ENGINE_TYPE::TORPILLEUR);
      skill3 = new Skill(ENGINE_TYPE::PATROUILE);
      engine1 = new Engine(3, ENGINE_TYPE::CONTRE_TORPILLEUR);
      engine1->add_skill(ENGINE_TYPE::CONTRE_TORPILLEUR, SHOT_TYPE::CONTRE_TORPILLEUR_SKILL);
      engine2 = new Engine(4, ENGINE_TYPE::TORPILLEUR);
      engine2->add_skill(ENGINE_TYPE::TORPILLEUR, SHOT_TYPE::TORPILLEUR_SKILL);
      engine3 = new Engine(2, ENGINE_TYPE::PATROUILE);
      engine3->add_skill(ENGINE_TYPE::PATROUILE, SHOT_TYPE::PATROUILE_SKILL);
      engine4 = new Engine(2, ENGINE_TYPE::CROISEUR);
      engine4->add_skill(ENGINE_TYPE::CROISEUR, SHOT_TYPE::CROISEUR_SKILL);
      engine5 = new Engine(5, ENGINE_TYPE::PORTE_AVION);
      engine5->add_skill(ENGINE_TYPE::PORTE_AVION, SHOT_TYPE::PORTE_AVION_SKILL);
      engine6 = new Engine(3, ENGINE_TYPE::TORPILLEUR);
      engine6->add_skill(ENGINE_TYPE::TORPILLEUR, SHOT_TYPE::TORPILLEUR_SKILL);
    }
    ~SkillTest(){
      delete(grid_1);
      delete(grid_2);
      delete(grid_3);
      delete(grid_4);
      delete(engine1);
      delete(engine2);
      delete(engine3);
      delete(engine4);
      delete(engine5);
    }
}
#endif //HAZARDOUS_MATERIALS_SKILL_TEST_H
