#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "geo_commands.h"

#include "make_const_nonconst.h"

// Note: This bin does not use bin IDs, unlike the other segmented bins.
#include "mario/model.inc.c"

#include "bubble/model.inc.c"

#include "walk_smoke/model.inc.c"

#include "burn_smoke/model.inc.c"

#include "small_water_splash/model.inc.c"

#include "water_wave/model.inc.c"

#include "sparkle/model.inc.c"

#include "water_splash/model.inc.c"

#include "white_particle_small/model.inc.c"

#include "sparkle_animation/model.inc.c"

#ifdef S2DEX_TEXT_ENGINE
#include "src/s2d_engine/s2d_config.h"
#include FONT_C_FILE
#endif

#include "mushroom_top/model.inc.c"
#include "mushroom_top/collision.inc.c"
#include "trunk/collision.inc.c"
#include "trunk/model.inc.c"
#include "toad/model.inc.c"
#include "toad/anims/data.inc.c"
#include "toad/anims/table.inc.c"
#include "luiginpc/model.inc.c"
#include "luiginpc/anims/data.inc.c"
#include "luiginpc/anims/table.inc.c"
#include "flying_boost/model.inc.c"
#include "flying_boost/collision.inc.c"
#include "banana/model.inc.c"
#include "ukiki/model.inc.c"
#include "ukiki/anims/data.inc.c"
#include "ukiki/anims/table.inc.c"
UNUSED static const u64 binid_3 = 3;
#include "rock/model.inc.c"
#include "rock/collision.inc.c"
#include "seesaw/model.inc.c"
#include "seesaw/collision.inc.c"
#include "seesaw2/model.inc.c"
#include "seesaw2/collision.inc.c"
#include "elevator/collision.inc.c"
#include "elevator/model.inc.c"
#include "red_circle/collision.inc.c"
#include "red_circle/model.inc.c"
#include "dragon_coin/model.inc.c"
#include "fall_piece_temple/model.inc.c"
#include "fall_piece_temple_1/collision.inc.c"
#include "fall_piece_temple_2/collision.inc.c"
#include "fall_piece_temple_3/collision.inc.c"
#include "fall_piece_temple_4/collision.inc.c"
#include "fall_piece_temple_5/collision.inc.c"
#include "seaweed/model.inc.c"
#include "seaweed/anims/data.inc.c"
#include "seaweed/anims/table.inc.c"
UNUSED static const u64 binid_1 = 1;
#include "dragon_coin_transparent/model.inc.c"
#include "fall_piece_2_temple/model.inc.c"