//
// Created by stevlulz on 3/7/19.
//

#ifndef TMP_PROJ_SQUARE_H
#define TMP_PROJ_SQUARE_H


#include "Engine.h"
#include "enum.h"

class Engine;
class Square
{

private:
    Engine *m_engine;
    SQUARE_TYPE m_square_type;
    float m_health_pr;
    //int depth;
    //char hazard; //climate changes (c : cold, t : tempest, n : none ... ?)

public:
    Square();

    Square(Engine *m_engine);
    //Square(Engine engine_here_nv, int depth_nv, char hazard_nv);



    /**
     * @brief get_engine is main function used to check if a square has an engine
     *        residing in it or no
     * @return return a reference for engine which is residing in this square ?
     *         nullptr if square is empty
     */
    Engine *get_engine();


    /**
     * @brief get_health_pr() is main function used to get the pourcetage of health of
     *        the engine's part residing on it
     * @return 0 if the engine part residing on this square is dead or square is empty ?
     *         otherwise it returns the remainning health pourcentage (positive float) for current part
     */
    float get_health_pr();



    /**
     * @brief desactivate_motor() is main function used to desactivate engine's motor which reside
     * on current square if the current square has an avtivated motor of an engine, it desactivates it otherwise it does nothing
     */
    void desactivate_motor();



    /**
     * @brief desactivate_weapon() is main function used to desactivate engine's weapon which reside
     * on current square if the current square has an activated weapon of an engine, it desactivates it otherwise it does nothing
    */
    void desactivate_weapon();



    /**
     * @brief activate_weapon() is main function used to reasactivate engine's weapon which reside
     * on current square if the current square has a desactivated weapon of an engine, it reactivates it otherwise it does nothing
     */
    void activate_weapon();


    /**
     * @brief activate_weapon() is main function used to reasactivate engine's motor which reside
     * on current square if the current square has a desactivated motor of an engine, it reactivates it otherwise it does nothing
    */
    void activate_motor();



    /**
     * @brief get_square_type() is main function used to get the state of current square or type of piece which is
     *        residing on it(motor,nothing,....etc)
     * @return
     *         NONE : current square is empty
     *         ENGINE_MOTOR : current square contains an engine's motor
     *         ENGINE_MOTOR_DESACTIVATED : current square contains a desactivated motor
     *         ENGINE_WEAPON : current square constrains an engine's weapon
     *         ENGINE_WEAPON_DESACTIVATED : current square contains
     *         ENGINE_PART : current square contains other engine's part(except motor and weapons)
     *         ENGINE_DEAD : current square contrains engine's crumbs
     */
    SQUARE_TYPE get_square_type();

    /**
     * @brief decrease_health() is the only function that has access to decrease the health of current engine's part
     *        -if the current square has no engine's piece on it, then it does nothing (it just returns)
     *
     *        -if the current square has an engine's part, then it decreases the health of current square
     *         (if it arrives to 0 it made the square as ENGINE_DEAD),then decreases the health of total
     *         health of engine residing on it.
     *
     *        -if the current square has an engine's weapon, then it does same as previous (if it arrives to 0
     *          TODO (maybe desactivate weapon)
     *
     *         -if the current square has an engine's motor, then it does same as previous (if it arrives to 0
     *         TODO (maybe desactivate the movements)
     *
     * @param dec the value of decreasing the current square's health and total engine's health
     * @return
     *         - if -1 then the current square doesn't contrain any engine part
     *         - (TODO other cases)
     */
    int decrease_health(float dec);


    void set_engine(Engine *engine_a);
    void set_health_pr(float pr);



    /**
     * @brief set_square_type() this is main function that has permission to modify the current square's type
     *        check enum.h(SQUARE_TYPE)
     * @param square_type the value of current's square type
     */
    void set_square_type(SQUARE_TYPE square_type);

};



#endif //TMP_PROJ_SQUARE_H
