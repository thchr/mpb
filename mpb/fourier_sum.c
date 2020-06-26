/* Copyright (C) 1999-2014 Massachusetts Institute of Technology.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "config.h"
#include <check.h>

#include "mpb.h"
#include <ctl-io.h>

number fourier_sum(vector3 r, vector3_list gs, cnumber_list coefs){
    number s = 0.0;
    number gdotr;
    int i;
    int Nterms = gs.num_items;

    for (i = 0; i < Nterms; ++i){
        gdotr = vector3_dot(gs.items[i], r);
        s += coefs.items[i].re*cos(gdotr) - coefs.items[i].im*sin(gdotr);
    }

    return s;
}