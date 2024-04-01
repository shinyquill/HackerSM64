void scroll_wf_dl_Level_mesh_layer_1_vtx_5() {
	int i = 0;
	int count = 393;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_Level_mesh_layer_1_vtx_5);

	deltaX = (int)(0.5 * 0x20) % width;
	deltaY = (int)(0.5 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_gfx_mat_wf_dl_f3dlite_material_059_layer1() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_f3dlite_material_059_layer1);


	shift_s(mat, 14, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 16, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_wf_dl_Water_layer5() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_Water_layer5);
	static int interval_tex_wf_dl_Water_layer5 = 2;
	static int cur_interval_tex_wf_dl_Water_layer5 = 2;
	static int interval_tex_wf_dl_Water_layer5_2 = 2;
	static int cur_interval_tex_wf_dl_Water_layer5_2 = 2;

	if (--cur_interval_tex_wf_dl_Water_layer5 <= 0) {
		shift_s(mat, 14, PACK_TILESIZE(0, 1));
		cur_interval_tex_wf_dl_Water_layer5 = interval_tex_wf_dl_Water_layer5;
	}

	if (--cur_interval_tex_wf_dl_Water_layer5_2 <= 0) {
		shift_s_down(mat, 16, PACK_TILESIZE(0, 1));
		shift_t_down(mat, 16, PACK_TILESIZE(0, 1));
		cur_interval_tex_wf_dl_Water_layer5_2 = interval_tex_wf_dl_Water_layer5_2;
	}

};

void scroll_wf() {
	scroll_wf_dl_Level_mesh_layer_1_vtx_5();
	scroll_gfx_mat_wf_dl_f3dlite_material_059_layer1();
	scroll_gfx_mat_wf_dl_Water_layer5();
};
