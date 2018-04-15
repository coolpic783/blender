/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software  Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * Contributor(s): Blender Foundation
 *
 * ***** END GPL LICENSE BLOCK *****
 *
 */

/** \file DNA_hair_types.h
 *  \ingroup DNA
 */

#ifndef __DNA_HAIR_TYPES_H__
#define __DNA_HAIR_TYPES_H__

#include "DNA_defs.h"
#include "DNA_listBase.h"
#include "DNA_ID.h"
#include "DNA_meshdata_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Root point (follicle) of a hair on a surface */
typedef struct HairFollicle {
	/* Sample on the scalp mesh for the root vertex */
	MeshSample mesh_sample;
	/* Parent curve indices for shape interpolation */
	unsigned int parent_index[4];
	/* Parent curve weights for shape interpolation */
	float parent_weight[4];
} HairFollicle;

/* Collection of hair roots on a surface */
typedef struct HairPattern {
	struct HairFollicle *follicles;
	int num_follicles;
	int pad;
} HairPattern;

typedef struct HairGuideCurve {
	/* Sample on the scalp mesh for the root vertex */
	MeshSample mesh_sample;
	/* Offset in the vertex array where the curve starts */
	int vertstart;
	/* Number of vertices in the curve */
	int numverts;
} HairGuideCurve;

typedef struct HairGuideVertex {
	int flag;
	float co[3];
} HairGuideVertex;

typedef struct HairSystem {
	int flag;
	int pad;
	
	/* Set of hair follicles on the scalp mesh */
	struct HairPattern *pattern;
	
	/* Curves for guiding hair fibers */
	struct HairGuideCurve *curves;
	/* Control vertices on guide curves */
	struct HairGuideVertex *verts;
	/* Number of guide curves */
	int totcurves;
	/* Number of guide curve vertices */
	int totverts;
	
	/* Material used for drawing and rendering hair fibers */
	int material_index;
	int pad2;
	
	/* Data buffers for drawing */
	void *draw_batch_cache;
	/* Texture buffer for drawing */
	void *draw_texture_cache;
} HairSystem;

typedef enum eHairSystemFlag
{
	/* Guide curve positions have changed, rebind hair follicles */
	HAIR_SYSTEM_UPDATE_FOLLICLE_BINDING = (1 << 8),
} eHairSystemFlag;

typedef struct HairDrawSettings
{
	short follicle_mode;
	short pad1;
	int pad2;
} HairDrawSettings;

typedef enum eHairDrawFollicleMode
{
	HAIR_DRAW_FOLLICLE_NONE     = 0,
	HAIR_DRAW_FOLLICLE_POINTS   = 1,
	HAIR_DRAW_FOLLICLE_AXES     = 2,
} eHairDrawFollicleMode;

#ifdef __cplusplus
}
#endif

#endif /* __DNA_HAIR_TYPES_H__ */
