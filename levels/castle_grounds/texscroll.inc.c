void scroll_castle_grounds_dl_Waterfall_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 107;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(castle_grounds_dl_Waterfall_mesh_layer_5_vtx_0);

	deltaY = (int)(-5.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_gfx_mat_castle_grounds_dl_Water_layer5() {
	Gfx *mat = segmented_to_virtual(mat_castle_grounds_dl_Water_layer5);
	static int interval_tex_castle_grounds_dl_Water_layer5 = 2;
	static int cur_interval_tex_castle_grounds_dl_Water_layer5 = 2;
	static int interval_tex_castle_grounds_dl_Water_layer5_2 = 2;
	static int cur_interval_tex_castle_grounds_dl_Water_layer5_2 = 2;

	if (--cur_interval_tex_castle_grounds_dl_Water_layer5 <= 0) {
		shift_s(mat, 14, PACK_TILESIZE(0, 1));
		cur_interval_tex_castle_grounds_dl_Water_layer5 = interval_tex_castle_grounds_dl_Water_layer5;
	}

	if (--cur_interval_tex_castle_grounds_dl_Water_layer5_2 <= 0) {
		shift_s_down(mat, 16, PACK_TILESIZE(0, 1));
		shift_t_down(mat, 16, PACK_TILESIZE(0, 1));
		cur_interval_tex_castle_grounds_dl_Water_layer5_2 = interval_tex_castle_grounds_dl_Water_layer5_2;
	}

};

void scroll_castle_grounds() {
	scroll_castle_grounds_dl_Waterfall_mesh_layer_5_vtx_0();
	scroll_gfx_mat_castle_grounds_dl_Water_layer5();
};
