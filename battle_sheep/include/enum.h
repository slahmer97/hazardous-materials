//
// Created by stevlulz on 3/7/19.
//

#ifndef TMP_PROJ_ENUM_H
#define TMP_PROJ_ENUM_H

#include <iostream>
enum SQUARE_TYPE
{
    NONE,
    ENGINE_MOTOR,
    ENGINE_WEAPON,
    ENGINE_PART,
    ENGINE_MOTOR_DESACTIVATED,
    ENGINE_WEAPON_DESACTIVATED,
    //Burned states + Pertforated states
    ENGINE_MOTOR_BURNED,
    ENGINE_WEAPON_BURNED,
    ENGINE_PART_BURNED,
    ENGINE_MOTOR_DESACTIVATED_BURNED,
    ENGINE_WEAPON_DESACTIVATED_BURNED,
    ENGINE_MOTOR_PERFORATED,
    ENGINE_WEAPON_PERFORATED,
    ENGINE_PART_PERFORATED,
    ENGINE_MOTOR_DESACTIVATED_PERFORATED,
    ENGINE_WEAPON_DESACTIVATED_PERFORATED,
    ENGINE_MOTOR_BURNED_PERFORATED,
    ENGINE_WEAPON_BURNED_PERFORATED,
    ENGINE_PART_BURNED_PERFORATED,
    ENGINE_MOTOR_DESACTIVATED_BURNED_PERFORATED,
    ENGINE_WEAPON_DESACTIVATED_BURNED_PERFORATED,
    //end
    ENGINE_MOTOR_DEAD,
    ENGINE_WEAPON_DEAD,
    ENGINE_PART_DEAD
};

enum MOTOR_STATE
{
    MOTOR,
    MOTOR_BURNED,
    MOTOR_PERFORATED,
    MOTOR_PERFORATED_BURNED,
    MOTOR_DESACTIVATED,
    MOTOR_DESACTIVATED_BURNED,
    MOTOR_DESACTIVATED_PERFORED,
    MOTOR_DESACTIVATED_BURNED_PERFORED,
    MOTOR_DEAD
};

enum WEAPON_STATE
{
    WEAPON,
    WEAPON_BURNED,
    WEAPON_PERFORATED,
    WEAPON_BURNED_PERFORATED,
    WEAPON_DESACTIVATED,
    WEAPON_DESACTIVATED_BURNED,
    WEAPON_DESACTIVATED_PERFORED,
    WEAPON_DESACTIVATED_BURNED_PERFORED,
    WEAPON_DEAD
};

enum PART_STATE
{
    PART,
    PART_BURNED,
    PART_PERFORATED,
    PART_BURNED_PERFORATED,
    PART_DEAD
};

enum ENGINE_TYPE
{
    PORTE_AVION,
    CROISEUR,
    CONTRE_TORPILLEUR,
    CUIRASSE,
    TORPILLEUR,
    BOMBARDIER,
    INTERCEPTEUR,
    BROUILLEUR,
    PATROUILE,
    RECONNAISSANCE,
    NOT_INTRODUCED,
    INCENDIARY
};
/*
std::string  engine_type_to_string(ENGINE_TYPE type){
    if(type == PORTE_AVION)
        return "porte_avion";
    else if(type == CROISEUR)
        return "croiseur";
    else if(type == CONTRE_TORPILLEUR)
        return "contre_torpilleur";
    else if(type == CUIRASSE)
        return "cuirasse";
    else if(type == TORPILLEUR)
        return "torpilleur";
    else if(type == BOMBARDIER)
        return "bombardier";
    else if(type ==INTERCEPTEUR )
        return "intercepteur";
    else if(type == BROUILLEUR)
        return "brouilleur";
    else if(type == PATROUILE)
        return "patrouile";
    else if(type == RECONNAISSANCE)
        return "reconnaissance";
    else if(type == NOT_INTRODUCED)
        return "not_introduced";
    else if(type == INCENDIARY)
        return  "incendiary";

}
ENGINE_TYPE engine_type_to_type(const std::string& type){
     if(type == "porte_avion")
         return PORTE_AVION;
     else if(type == "croiseur")
        return CROISEUR;
     else if(type =="contre_torpilleur" )
        return CONTRE_TORPILLEUR ;
     else if(type == "cuirasse")
        return CUIRASSE;
     else if(type == "torpilleur")
        return TORPILLEUR;
     else if(type == "bombardier")
        return BOMBARDIER;
     else if(type =="intercepteur" )
        return INTERCEPTEUR;
     else if(type == "brouilleur")
        return BROUILLEUR;
     else if(type == "patrouile")
        return PATROUILE;
     else if(type == "reconnaissance")
         return RECONNAISSANCE;
     else if(type == "not_introduced")
        return NOT_INTRODUCED ;
     else if(type == "incendiary")
        return INCENDIARY ;
}

*/

enum SHOT_TYPE
{
    PORTE_AVION_SKILL,
    CROISEUR_SKILL,
    CONTRE_TORPILLEUR_SKILL,
    CUIRASSE_SKILL,
    TORPILLEUR_SKILL,
    BOMBARDIER_SKILL,
    INTERCEPTEUR_SKILL,
    BROUILLEUR_SKILL,
    PATROUILE_SKILL,
    RECONNAISSANCE_SKILL,
    NORMAL_SHOT
};

/*
std::string shot_type_to_string(SHOT_TYPE shot){
    if(shot == PORTE_AVION_SKILL)
        return "porte_avion_skill";
    else if(shot == CROISEUR_SKILL)
        return "croiseur_skill";
    else if(shot == CONTRE_TORPILLEUR_SKILL)
        return "contre_torpilleur_skill";
    else if(shot == BOMBARDIER_SKILL)
        return "bombardier_skill";
    else if(shot == INTERCEPTEUR_SKILL)
        return "intercepteur_skill";
    else if(shot == BROUILLEUR_SKILL)
        return "brouilleur_skill";
    else if(shot == RECONNAISSANCE_SKILL)
        return "reconnaissance_skill";
    else if(shot == NORMAL_SHOT)
        return "normal_shot";
}
SHOT_TYPE shot_type_to_type(const std::string& shot){
    if(shot == "porte_avion_skill")
        return  PORTE_AVION_SKILL;
    else if(shot == "croiseur_skill")
        return CROISEUR_SKILL ;
    else if(shot == "contre_torpilleur_skill")
        return CONTRE_TORPILLEUR_SKILL;
    else if(shot == "bombardier_skill")
        return BOMBARDIER_SKILL;
    else if(shot == "intercepteur_skill")
        return INTERCEPTEUR_SKILL;
    else if(shot == "brouilleur_skill")
        return BROUILLEUR_SKILL;
    else if(shot == "reconnaissance_skill")
        return RECONNAISSANCE_SKILL;
    else if(shot == "normal_shot")
        return NORMAL_SHOT;
}
*/

#endif //TMP_PROJ_ENUM_H
