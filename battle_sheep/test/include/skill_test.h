//
// Created by sidahmedlahmer on 3/24/19.
//

#ifndef HAZARDOUS_MATERIALS_SKILL_TEST_H
#define HAZARDOUS_MATERIALS_SKILL_TEST_H
#include <gtest/gtest.h>
#include <FactorySkill.h>
#include <FactoryEngine.h>
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
    Engine * engine7;
    Engine * engine8;
    Engine * engine9;
    Engine * engine10;
    Engine * engine11;
    Engine * engine12;
    Engine * engine13;
    Engine * engine14;
    Engine * engine15;
    Engine * engine16;
    Engine * engine17;
    Engine * engine18;
    Engine * engine19;
    Engine * engine20;
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
      skill1 = FactorySkill::getSkill(ENGINE_TYPE::CONTRE_TORPILLEUR);
      skill2 = FactorySkill::getSkill(ENGINE_TYPE::TORPILLEUR);
      skill3 = FactorySkill::getSkill(ENGINE_TYPE::PATROUILE);
      engine1 = FactoryEngine::getEngine(ENGINE_TYPE::PORTE_AVION);
      engine2 = FactoryEngine::getEngine(ENGINE_TYPE::CROISEUR);
      engine3 = FactoryEngine::getEngine(ENGINE_TYPE::CONTRE_TORPILLEUR);
      engine4 = FactoryEngine::getEngine(ENGINE_TYPE::CUIRASSE);
      engine5 = FactoryEngine::getEngine(ENGINE_TYPE::TORPILLEUR);
      engine6 = FactoryEngine::getEngine(ENGINE_TYPE::BOMBARDIER);
      engine7 = FactoryEngine::getEngine(ENGINE_TYPE::INTERCEPTEUR);
      engine8 = FactoryEngine::getEngine(ENGINE_TYPE::BROUILLEUR);
      engine9 = FactoryEngine::getEngine(ENGINE_TYPE::PATROUILE);
      engine10 = FactoryEngine::getEngine(ENGINE_TYPE::RECONNAISSANCE);
      engine11 = FactoryEngine::getEngine(ENGINE_TYPE::PORTE_AVION);
      engine12 = FactoryEngine::getEngine(ENGINE_TYPE::CROISEUR);
      engine13 = FactoryEngine::getEngine(ENGINE_TYPE::CONTRE_TORPILLEUR);
      engine14 = FactoryEngine::getEngine(ENGINE_TYPE::CUIRASSE);
      engine15 = FactoryEngine::getEngine(ENGINE_TYPE::TORPILLEUR);
      engine16 = FactoryEngine::getEngine(ENGINE_TYPE::BOMBARDIER);
      engine17 = FactoryEngine::getEngine(ENGINE_TYPE::INTERCEPTEUR);
      engine18 = FactoryEngine::getEngine(ENGINE_TYPE::BROUILLEUR);
      engine19 = FactoryEngine::getEngine(ENGINE_TYPE::PATROUILE);
      engine20 = FactoryEngine::getEngine(ENGINE_TYPE::RECONNAISSANCE);
    }
    ~SkillTest(){
      delete(grid_1);
      delete(grid_2);
      delete(grid_3);
      delete(grid_4);
      delete(skill1);
      delete(skill2);
      delete(skill3);
      delete(engine1);
      delete(engine2);
      delete(engine3);
      delete(engine4);
      delete(engine5);
      delete(engine6);
      delete(engine7);
      delete(engine8);
      delete(engine9);
      delete(engine10);
      delete(engine11);
      delete(engine12);
      delete(engine13);
      delete(engine14);
      delete(engine15);
      delete(engine16);
      delete(engine17);
      delete(engine18);
      delete(engine19);
      delete(engine20);
    }
};
#endif //HAZARDOUS_MATERIALS_SKILL_TEST_H
