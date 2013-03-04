/*
    This file is part of darktable,
    copyright (c) 2010--2011 Henrik Andersson.

    darktable is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    darktable is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with darktable.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef DT_CONTROL_JOBS_CONTROL_H
#define DT_CONTROL_JOBS_CONTROL_H

#include <inttypes.h>
#include "control/control.h"

typedef struct dt_control_image_enumerator_t
{
  GList *index;
  int flag;
  gpointer data;
}
dt_control_image_enumerator_t;

int32_t dt_control_write_sidecar_files_job_run(dt_job_t *job);
void dt_control_write_sidecar_files_job_init(dt_job_t *job);


void dt_control_duplicate_images_job_init(dt_job_t *job);
int32_t dt_control_duplicate_images_job_run(dt_job_t *job);

void dt_control_flip_images_job_init(dt_job_t *job, const int32_t cw);
int32_t dt_control_flip_images_job_run(dt_job_t *job);

void dt_control_image_enumerator_job_film_init(dt_control_image_enumerator_t *t, int32_t filmid);
void dt_control_image_enumerator_job_selected_init(dt_control_image_enumerator_t *t);

int32_t dt_control_remove_images_job_run(dt_job_t *job);
void dt_control_remove_images_job_init(dt_job_t *job);

int32_t dt_control_move_images_job_run(dt_job_t *job);
void dt_control_move_images_job_init(dt_job_t *job);

int32_t dt_control_copy_images_job_run(dt_job_t *job);
void dt_control_copy_images_job_init(dt_job_t *job);

void dt_control_delete_images_job_init(dt_job_t *job);
int32_t dt_control_delete_images_job_run(dt_job_t *job);

void dt_control_export_job_init(dt_job_t *job, int max_width, int max_height, int format_index, int storage_index, gboolean high_quality, char *style);
int32_t dt_control_export_job_run(dt_job_t *job);

#if GLIB_CHECK_VERSION (2, 26, 0)
void dt_control_gpx_apply(const gchar *filename, int32_t filmid, const gchar *tz);
void dt_control_gpx_apply_job_init(dt_job_t *job, const gchar *filename, int32_t filmid, const gchar *tz);
int32_t dt_control_gpx_apply_job_run(dt_job_t *job);

void dt_control_time_offset(const long int offset, long int imgid);
void dt_control_time_offset_job_init(dt_job_t *job, const long int offset, long int imgid);
int32_t dt_control_time_offset_job_run(dt_job_t *job);
#endif

void dt_control_upload_style_job_init(dt_job_t *job, long int beforeid, long int afterid, gchar *nameorig, gchar *name, gchar *username, gchar *password, gchar *description, gchar *url);
int32_t dt_control_upload_style_job_run(dt_job_t *job);

void dt_control_write_sidecar_files();
void dt_control_delete_images();
void dt_control_duplicate_images();
void dt_control_flip_images(const int32_t cw);
void dt_control_remove_images();
void dt_control_move_images();
void dt_control_copy_images();
void dt_control_export(int max_width, int max_height, int format_index, int storage_index, gboolean high_quality, char *style);
void dt_control_merge_hdr();

void dt_control_gpx_apply(const gchar *filename, int32_t filmid, const gchar *tz);
void dt_control_time_offset(const long int offset, long int imgid);

void dt_control_seed_denoise();
void dt_control_denoise();

void dt_control_upload_style(long int beforeid, long int afterid, gchar *nameorig, gchar *name, gchar *username, gchar *password, gchar *description, gchar *url);

struct dt_similarity_t;
void dt_control_match_similar(struct dt_similarity_t *data);

void dt_control_start_indexer();

#endif
// modelines: These editor modelines have been set for all relevant files by tools/update_modelines.sh
// vim: shiftwidth=2 expandtab tabstop=2 cindent
// kate: tab-indents: off; indent-width 2; replace-tabs on; indent-mode cstyle; remove-trailing-space on;
