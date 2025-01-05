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
#include "levels/castle_inside/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_inside_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _castle_inside_segment_7SegmentRomStart, _castle_inside_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _inside_yay0SegmentRomStart, _inside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _castle_inside_segment_7SegmentRomStart, _castle_inside_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _clouds_skybox_mio0SegmentRomStart, _clouds_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_BOWSER_TRAP, castle_geo_000F18), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WATER_LEVEL_PILLAR, castle_geo_001940), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_MINUTE_HAND, castle_geo_001530), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_HOUR_HAND, castle_geo_001548), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_PENDULUM, castle_geo_001518), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_METAL_DOOR, metal_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR_UNUSED, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR_UNUSED, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_0_STARS, castle_door_0_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_1_STAR, castle_door_1_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_3_STARS, castle_door_3_stars_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_KEY_DOOR, key_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_30_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_8_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_50_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_70_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(2, castle_inside_area_2),
		WARP_NODE(0x0A, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x02, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_CASTLE_COURTYARD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CASTLE_STAR_DOOR_8_STARS, -11243, 0, -3390, 0, 30, 0, 0x04000000, bhvStarDoor),
		OBJECT(MODEL_CASTLE_STAR_DOOR_8_STARS, -11108, 0, -3468, 0, -150, 0, 0x04000000, bhvStarDoor),
		OBJECT(MODEL_LUIGI, -7048, 0, -521, 0, -174, 0, (DIALOG_012 << 16), bhvLuigiNPC),
		OBJECT(MODEL_TOAD, -10778, 0, -2165, 0, -179, 0, (DIALOG_013 << 24), bhvToadMessage),
		OBJECT(MODEL_STAR, -7271, 300, -926, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_TOAD, -6329, 1373, -1586, 0, 157, 0, (DIALOG_010 << 24), bhvToadMessage),
		OBJECT(MODEL_NONE, -6644, 95, -935, 0, -92, 0, 0x000A0000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, -10982, 84, -3108, 0, 38, 0, (0x0B << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, -11340, 84, -3693, 0, -150, 0, (0x02 << 16), bhvWarp),
		TERRAIN(castle_inside_area_2_collision),
		MACRO_OBJECTS(castle_inside_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_HUB),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(1, castle_inside_area_1),
		WARP_NODE(0x0A, LEVEL_CASTLE, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_CASTLE, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xFF, LEVEL_ENDING, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_CASTLE, 0x02, 0x0B, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0x00, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0x01, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0x02, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0x06, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0x07, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0x08, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0x09, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0x0A, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0x0B, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xAA, LEVEL_CASTLE_COURTYARD, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CASTLE_DOOR_0_STARS, -136, 0, 361, 0, 0, 0, 0x000A0000, bhvDoor),
		OBJECT(MODEL_NONE, -3185, 438, -1595, 0, 167, 0, 0x00000000, bhvTankFishGroup),
		OBJECT(MODEL_NONE, -3044, 438, -1744, 0, -35, 0, 0x00000000, bhvTankFishGroup),
		OBJECT(MODEL_SEAWEED, -3224, 256, -1744, 0, 167, 0, 0x00000000, bhvSeaweed),
		OBJECT(MODEL_SEAWEED, -3575, 256, -1519, 0, 167, 0, 0x00000000, bhvSeaweed),
		OBJECT(MODEL_SEAWEED, -2756, 256, -1611, 0, 167, 0, 0x00000000, bhvSeaweed),
		OBJECT(MODEL_TOAD, -3231, 0, 819, 0, 27, 0, (DIALOG_015 << 24), bhvToadMessage),
		OBJECT(MODEL_TOAD, -1998, 78, 760, 0, -156, 0, (DIALOG_042 << 24), bhvToadMessage),
		OBJECT(MODEL_TOAD, -3524, 78, -1068, 0, 167, 0, (DIALOG_046 << 24), bhvToadMessage),
		OBJECT(MODEL_TOAD, -1463, 66, -1085, 0, -31, 0, (DIALOG_036 << 24), bhvToadMessage),
		OBJECT(MODEL_TOAD, -5146, 78, 347, 0, 178, 0, (DIALOG_043 << 24), bhvToadMessage),
		OBJECT(MODEL_SEAWEED, -2669, 256, -1410, 0, 167, 0, 0x00000000, bhvSeaweed),
		OBJECT(MODEL_NONE, -3130, 0, 1229, 0, 178, 0, 0x000A0000, bhvInstantActiveWarp),
		OBJECT(MODEL_CASTLE_DOOR_0_STARS, 1055, 0, 678, 0, -90, 0, 0x00FF0000, bhvDoorWarp),
		OBJECT(MODEL_NONE, -3143, 88, 1611, 0, 178, 0, 0x000D0000, bhvWarp),
		OBJECT(MODEL_NONE, 1289, 556, -2899, 0, -89, 0, 0x01000000, bhvStarSpawnPointRanking),
		OBJECT(MODEL_NONE, 1289, 556, -1678, 0, -89, 0, 0x02000000, bhvStarSpawnPointRanking),
		OBJECT(MODEL_NONE, 1289, 556, -471, 0, -89, 0, 0x03000000, bhvStarSpawnPointRanking),
		OBJECT(MODEL_NONE, -1804, 400, -780, 0, 1, 0, 0x00000000, bhvStarSpawnPointDragonCoin),
		OBJECT(MODEL_NONE, 209, 0, -1678, 0, 88, 0, 0x000C0000, bhvInstantActiveWarp),
		TERRAIN(castle_inside_area_1_collision),
		ROOMS(castle_inside_area_1_collision_rooms),
		MACRO_OBJECTS(castle_inside_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_SHOP),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
