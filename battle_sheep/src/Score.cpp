//
// Created by sidahmedlahmer on 3/24/19.
//

#include <Score.h>

#include "Score.h"

Score::Score(int s1, int s2, int s3, int s4) {
    m_s1 = s1;
    m_s2 = s2;
    m_s3 = s3;
    m_s4 = s4;
    //TODO set game instance
}
int Score::get_s1() {
    return m_s1;
}
int Score::get_s2() {
    return m_s2;
}
int Score::get_s3() {
    return m_s3;
}
int Score::get_s4() {
    return m_s4;
}