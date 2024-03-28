#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/castle_courtyard/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_courtyard_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _castle_courtyard_segment_7SegmentRomStart, _castle_courtyard_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _outside_yay0SegmentRomStart, _outside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group9_yay0SegmentRomStart, _group9_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _castle_courtyard_segment_7SegmentRomStart, _castle_courtyard_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _clouds_skybox_mio0SegmentRomStart, _clouds_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	LOAD_MODEL_FROM_GEO(MODEL_COURTYARD_SPIKY_TREE, spiky_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_COURTYARD_WOODEN_DOOR, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, castle_courtyard_geo_000200), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_courtyard_area_1),
		WARP_NODE(0x0A, LEVEL_CASTLE_COURTYARD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE_COURTYARD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE_COURTYARD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x02, LEVEL_CASTLE_COURTYARD, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_CASTLE_COURTYARD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 1016, 955, 5667, 0, 178, 0, 0x000A0000, bhvInstantActiveWarp),
		MARIO_POS(0x01, 178, 1016, 955, 5667),
		OBJECT(MODEL_NONE, -402, 89, -3290, 0, 48, 0, (0x0B << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -621, 89, -3523, 0, 180, 0, (0x02 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 8840, 93, -952, 0, 180, 0, (0x01 << 16), bhvWarp),
		OBJECT(MODEL_TOAD, -871, 5, -2254, 0, 157, 0, (0x04 << 16), bhvToadMessage),
		OBJECT(MODEL_TOAD, 2734, 105, -3820, 0, 157, 0, (0x04 << 16), bhvToadMessage),
		OBJECT(MODEL_TOAD, 2966, 105, -4094, 0, -6, 0, (0x04 << 16), bhvToadMessage),
		OBJECT(MODEL_LUIGI, 3227, 5, 1233, 0, 103, 0, (0x05 << 16), bhvLuigiNPC2),
		TERRAIN(castle_courtyard_area_1_collision),
		MACRO_OBJECTS(castle_courtyard_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_HUB),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, castle_courtyard_area_2),
		WARP_NODE(0x0A, LEVEL_CASTLE_COURTYARD, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE_COURTYARD, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE_COURTYARD, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_CASTLE_COURTYARD, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -113, -252, -1179, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -113, -252, -1515, 0, 180, 0, (0x01 << 16), bhvWarp),
		TERRAIN(castle_courtyard_area_2_collision),
		MACRO_OBJECTS(castle_courtyard_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_HUB),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, castle_courtyard_area_3),
		WARP_NODE(0x0A, LEVEL_CASTLE_COURTYARD, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE_COURTYARD, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE_COURTYARD, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -72, 89, 1126, 0, -90, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, -90, -72, 89, 1126),
		OBJECT(MODEL_NONE, -167, -344, -10795, 0, 180, 0, (0x01 << 16), bhvWarp),
		TERRAIN(castle_courtyard_area_3_collision),
		MACRO_OBJECTS(castle_courtyard_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_HUB),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -90, -72, 89, 1126),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
