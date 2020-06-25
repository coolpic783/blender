/*
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
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2008 Blender Foundation.
 * All rights reserved.
 */

/** \file
 * \ingroup obj
 */

#include <iostream>

#include "PIL_time.h"

#include "IO_wavefront_obj.h"

#include "wavefront_obj.hh"
#include "wavefront_obj_exporter.hh"

/**
 * Called from io_obj.c. Calls internal functions in IO:OBJ.
 * When more preferences are there, will be used to set appropriate flags.
 */
void OBJ_export(bContext *C, const OBJExportParams *export_params)
{
  double start_time = PIL_check_seconds_timer();
  io::obj::exporter_main(C, export_params);
  double end_time = PIL_check_seconds_timer();
  std::cout << "\nOBJ export time: " << (end_time - start_time) * 1000 << " milliseconds\n";
}
/**
 * Called from io_obj.c. Currently not implemented.
 */
void OBJ_import(bContext *C, const OBJImportParams *import_params)
{
}
