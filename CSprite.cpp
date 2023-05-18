#include <array>
#include <cmath>
#include "Position.h"
#include "CSprite.h"

#include <SFML/Graphics.hpp>

CSprite::CSprite(): m_position ({0, 0}) {}

void CSprite::set_position(int i_x, int i_y) {m_position = {i_x, i_y};}

Position CSprite::get_position() {return m_position;}
