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

TEST_F(SkillTest, to_string)
{
    ASSERT_EQ(skill1->shot_type_to_string(PORTE_AVION_SKILL),"porte_avion_skill");
    ASSERT_EQ(skill1->shot_type_to_string(CROISEUR_SKILL),"croiseur_skill");
    ASSERT_EQ(skill1->shot_type_to_string(CONTRE_TORPILLEUR_SKILL),"contre_torpilleur_skill");
    ASSERT_EQ(skill1->shot_type_to_string(CUIRASSE_SKILL),"cuirasse_skill");
    ASSERT_EQ(skill1->shot_type_to_string(TORPILLEUR_SKILL),"torpilleur_skill");
    ASSERT_EQ(skill1->shot_type_to_string(BOMBARDIER_SKILL),"bombardier_skill");
    ASSERT_EQ(skill1->shot_type_to_string(INTERCEPTEUR_SKILL),"intercepteur_skill");
    ASSERT_EQ(skill1->shot_type_to_string(BROUILLEUR_SKILL),"brouilleur_skill");
    ASSERT_EQ(skill1->shot_type_to_string(PATROUILE_SKILL),"patrouile_skill");
    ASSERT_EQ(skill1->shot_type_to_string(RECONNAISSANCE_SKILL),"reconnaissance_skill");


    ASSERT_EQ(skill1->shot_type_to_type("porte_avion_skill"),PORTE_AVION_SKILL);
    ASSERT_EQ(skill1->shot_type_to_type("croiseur_skill"),CROISEUR_SKILL);
    ASSERT_EQ(skill1->shot_type_to_type("contre_torpilleur_skill"),CONTRE_TORPILLEUR_SKILL);
    ASSERT_EQ(skill1->shot_type_to_type("cuirasse_skill"),CUIRASSE_SKILL);
    ASSERT_EQ(skill1->shot_type_to_type("torpilleur_skill"),TORPILLEUR_SKILL);
    ASSERT_EQ(skill1->shot_type_to_type("bombardier_skill"),BOMBARDIER_SKILL);
    ASSERT_EQ(skill1->shot_type_to_type("intercepteur_skill"),INTERCEPTEUR_SKILL);
    ASSERT_EQ(skill1->shot_type_to_type("brouilleur_skill"),BROUILLEUR_SKILL);
    ASSERT_EQ(skill1->shot_type_to_type("patrouile_skill"),PATROUILE_SKILL);
    ASSERT_EQ(skill1->shot_type_to_type("reconnaissance_skill"),RECONNAISSANCE_SKILL);
}

TEST_F(SkillTest, play_with_skills)
{
    ASSERT_EQ(grid_1->add_engine(engine1,true,0,0),1);
    ASSERT_EQ(grid_1->add_engine(engine2,true,1,2),1);
    ASSERT_EQ(grid_1->add_engine(engine3,true,2,4),1);
    ASSERT_EQ(grid_1->add_engine(engine4,true,3,6),1);
    ASSERT_EQ(grid_1->add_engine(engine5,true,4,8),1);
    
    ASSERT_EQ(grid_3->add_engine(engine6,true,0,0),1);
    ASSERT_EQ(grid_3->add_engine(engine7,true,1,2),1);
    ASSERT_EQ(grid_3->add_engine(engine8,true,2,4),1);
    ASSERT_EQ(grid_3->add_engine(engine9,true,3,6),1);
    ASSERT_EQ(grid_3->add_engine(engine10,true,4,8),1);
    

    ASSERT_EQ(grid_2->add_engine(engine11,true,0,0),1);
    ASSERT_EQ(grid_2->add_engine(engine12,true,1,2),1);
    ASSERT_EQ(grid_2->add_engine(engine13,true,2,4),1);
    ASSERT_EQ(grid_2->add_engine(engine14,true,3,6),1);
    ASSERT_EQ(grid_2->add_engine(engine15,true,4,8),1);
    
    ASSERT_EQ(grid_4->add_engine(engine16,true,0,0),1);
    ASSERT_EQ(grid_4->add_engine(engine17,true,1,2),1);
    ASSERT_EQ(grid_4->add_engine(engine18,true,2,4),1);
    ASSERT_EQ(grid_4->add_engine(engine19,true,3,6),1);
    ASSERT_EQ(grid_4->add_engine(engine20,true,4,8),1);
    

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            ASSERT_EQ(grid_1->get(i,j)->squares_equals(grid_2->get(i,j)), true);
            ASSERT_EQ(grid_3->get(i,j)->squares_equals(grid_4->get(i,j)), true);
        }
    }
    ASSERT_EQ(engine16->Skill_shot(grid_1,grid_3,3,6,true,BOMBARDIER_SKILL),8);
    ASSERT_EQ(engine6->Skill_shot(grid_2,grid_4,3,6,true,BOMBARDIER_SKILL),8);
    ASSERT_EQ(engine10->Skill_shot(grid_2,3,6,true,RECONNAISSANCE_SKILL),-1);
    ASSERT_EQ(engine10->Skill_shot(grid_2,3,6,true,PATROUILE_SKILL),-4);
    ASSERT_EQ(engine13->Skill_shot(grid_1,2,4,true,CONTRE_TORPILLEUR_SKILL),2);
    ASSERT_EQ(engine3->Skill_shot(grid_2,2,4,true,CONTRE_TORPILLEUR_SKILL),2);
    ASSERT_EQ(engine6->Skill_shot(grid_2,3,5,true,BOMBARDIER_SKILL),-1000);
    ASSERT_EQ(engine3->Skill_shot(grid_2,grid_4,1,0,true,CONTRE_TORPILLEUR_SKILL),-1000);
    ASSERT_EQ(engine16->Skill_shot(grid_2,grid_4,1,0,true,BOMBARDIER_SKILL),-3);
    ASSERT_EQ(engine13->Skill_shot(grid_2,3,5,true,CONTRE_TORPILLEUR_SKILL),-3);
    ASSERT_EQ(engine13->Skill_shot(nullptr,grid_3,1,0,true,CONTRE_TORPILLEUR_SKILL),-100);
    ASSERT_EQ(engine13->Skill_shot(grid_1,nullptr,1,0,true,CONTRE_TORPILLEUR_SKILL),-100);
    ASSERT_EQ(engine13->Skill_shot(nullptr,nullptr,1,0,true,CONTRE_TORPILLEUR_SKILL),-100);
    ASSERT_EQ(engine13->Skill_shot(nullptr,3,5,true,CONTRE_TORPILLEUR_SKILL),-100);
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            ASSERT_EQ(grid_1->get(i,j)->squares_equals(grid_2->get(i,j)), true);
            ASSERT_EQ(grid_3->get(i,j)->squares_equals(grid_4->get(i,j)), true);
        }
    }
}