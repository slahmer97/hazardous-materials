#include "../include/skill.h"

using namespace std;

Skill::Skill(bool unlimited_a, bool used_a, int x_a, int y_a, int a_a, int b_a)
    : unlimited(unlimited_a),
      used(used_a),
      x(x_a),
      y(y_a),
      a(a_a),
      b(b_a)
{
}
bool Skill::is_unlimited(){
    return unlimited;
}
bool Skill::is_used(){
    return used;
}
int Skill::get_x_location(){
    return x;
}
int Skill::get_y_location(){
    return y;
}
int Skill::get_a_location(){
    return a;
}
int Skill::get_b_location(){
    return b;
}

//Setters :
void Skill::set_unlimited(bool unlimited_a){
    unlimited=unlimited_a;
}
void Skill::set_used(bool used_a){
    used=used_a;
}
void Skill::set_x_location(int x_a){
    x=x_a;
}
void Skill::set_y_location(int y_a){
    y=y_a;
}
void Skill::set_a_location(int a_a){
    a=a_a;
}
void Skill::set_b_location(int b_a){
    b=b_a;
}
