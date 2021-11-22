#ifndef __GAME_FLOW_H__
#define __GAME_FLOW_H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "listdp.h"
#include "map.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "player.h"
#include "../FUNGSI/roll.h"

#define MaxCommand 20

boolean game(boolean endGame);

void CMap(Map peta, TabPlayer gemink);

void CBuff(boolean immune, int buffRoll);

void CInspect(Map peta);

#endif
