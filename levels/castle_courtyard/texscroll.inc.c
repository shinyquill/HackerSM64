void scroll_castle_courtyard_dl_Sandfall_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 288;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(castle_courtyard_dl_Sandfall_mesh_layer_5_vtx_0);

	deltaY = (int)(-2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_gfx_mat_castle_courtyard_dl_Lava_layer1() {
	Gfx *mat = segmented_to_virtual(mat_castle_courtyard_dl_Lava_layer1);


	shift_s(mat, 14, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 16, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_castle_courtyard() {
	scroll_castle_courtyard_dl_Sandfall_mesh_layer_5_vtx_0();
	scroll_gfx_mat_castle_courtyard_dl_Lava_layer1();
};
