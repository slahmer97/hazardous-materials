//
// Created by sidahmedlahmer on 3/24/19.
//

#ifndef HAZARDOUS_MATERIALS_SCORE_H
#define HAZARDOUS_MATERIALS_SCORE_H


class Score {
private:
    int m_s1,m_s2,m_s3,m_s4;
    //GAME instance

public:
    Score(int,int,int,int);
    int get_s1();
    int get_s2();
    int get_s3();
    int get_s4();

    void set_s1(int);
    void set_s2(int);
    void set_s3(int);
    void set_s4(int);




};


#endif //HAZARDOUS_MATERIALS_SCORE_H
