/*
 * Ncview by David W. Pierce.  A visual netCDF file viewer.
 * Copyright (C) 1993 through 2009 David W. Pierce
 *
 * This program  is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as 
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License, version 3, for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * David W. Pierce
 * 6259 Caminito Carrean
 * San Diego, CA   92122
 * pierce@cirrus.ucsd.edu
 */

static int cmap_helix2[] = {
	0,0,0, 0,0,0, 1,1,1, 2,1,1, 3,2,2, 4,2,2, 5,3,3, 6,4,4, 
	7,4,4, 7,5,5, 8,6,6, 9,6,6, 10,7,7, 10,8,8, 11,9,9, 12,10,10, 
	12,11,11, 13,11,11, 14,12,12, 14,13,13, 15,14,14, 15,15,15, 16,16,16, 16,17,17, 
	17,18,18, 17,19,19, 18,20,20, 18,21,21, 18,22,22, 19,23,23, 19,25,25, 19,26,26, 
	20,27,27, 20,28,28, 20,29,29, 20,30,30, 20,31,31, 21,33,33, 21,34,34, 21,35,35, 
	21,36,36, 21,37,37, 21,39,39, 21,40,40, 21,41,41, 21,42,42, 21,43,43, 21,44,44, 
	20,46,46, 20,47,47, 20,48,48, 20,49,49, 20,50,50, 19,52,52, 19,53,53, 19,54,54, 
	18,55,55, 18,56,56, 18,57,57, 17,58,58, 17,59,59, 17,60,60, 16,61,61, 16,62,62, 
	16,63,63, 15,64,64, 15,65,65, 14,66,66, 14,67,67, 13,68,68, 13,69,69, 12,70,70, 
	12,71,71, 11,72,72, 11,72,72, 10,73,73, 10,74,74, 9,75,75, 9,75,75, 8,76,76, 
	8,76,76, 7,77,77, 7,78,78, 6,78,78, 6,79,79, 5,79,79, 5,79,79, 4,80,80, 
	4,80,80, 4,80,80, 3,81,81, 3,81,81, 2,81,81, 2,81,81, 2,81,81, 1,81,81, 
	1,81,81, 1,81,81, 1,81,81, 0,81,81, 0,81,81, 0,81,81, 0,81,81, 0,81,81, 
	0,80,80, 0,80,80, 0,80,80, 0,79,79, 0,79,79, 0,79,79, 0,78,78, 0,77,77, 
	0,77,77, 0,76,76, 0,76,76, 1,75,75, 1,74,74, 1,74,74, 2,73,73, 2,72,72, 
	3,71,71, 3,70,70, 4,69,69, 4,69,69, 5,68,68, 6,67,67, 6,66,66, 7,65,65, 
	8,64,64, 9,62,62, 10,61,61, 11,60,60, 12,59,59, 13,58,58, 14,57,57, 15,55,55, 
	16,54,54, 18,53,53, 19,52,52, 20,50,50, 22,49,49, 23,48,48, 25,47,47, 26,45,45, 
	28,44,44, 29,43,43, 31,41,41, 33,40,40, 34,39,39, 36,37,37, 38,36,36, 40,35,35, 
	42,33,33, 44,32,32, 46,31,31, 48,29,29, 50,28,28, 52,27,27, 54,25,25, 57,24,24, 
	59,23,23, 61,22,22, 63,20,20, 66,19,19, 68,18,18, 71,17,17, 73,16,16, 75,15,15, 
	78,14,14, 81,13,13, 83,12,12, 86,11,11, 88,10,10, 91,9,9, 94,8,8, 96,7,7, 
	99,6,6, 102,5,5, 104,5,5, 107,4,4, 110,3,3, 113,3,3, 115,2,2, 118,2,2, 
	121,1,1, 124,1,1, 127,1,1, 129,0,0, 132,0,0, 135,0,0, 138,0,0, 141,0,0, 
	143,0,0, 146,0,0, 149,0,0, 152,0,0, 155,0,0, 157,0,0, 160,1,1, 163,1,1, 
	165,1,1, 168,2,2, 171,3,3, 173,3,3, 176,4,4, 179,5,5, 181,6,6, 184,6,6, 
	186,7,7, 188,8,8, 191,10,10, 193,11,11, 196,12,12, 198,13,13, 200,15,15, 202,16,16, 
	204,18,18, 206,19,19, 209,21,21, 211,23,23, 212,24,24, 214,26,26, 216,28,28, 218,30,30, 
	220,32,32, 221,34,34, 223,37,37, 224,39,39, 226,41,41, 227,44,44, 229,46,46, 230,48,48, 
	231,51,51, 232,54,54, 233,56,56, 234,59,59, 235,62,62, 236,65,65, 237,68,68, 238,71,71, 
	238,74,74, 239,77,77, 240,80,80, 240,83,83, 240,86,86, 241,89,89, 241,93,93, 241,96,96, 
	241,99,99, 241,103,103, 241,106,106, 241,110,110, 240,113,113, 240,117,117, 239,120,120, 239,124,124};
