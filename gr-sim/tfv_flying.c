#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <math.h>

#include "gr-sim.h"
#include "tfv_utils.h"
#include "tfv_zp.h"

#include "tfv_sprites.h"



static unsigned char flying_map[32][32]= {
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},

	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},

	{2,2,2,2, 15,15,15,15, 2,2,2,0, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 13,12, 8, 4, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 13,12, 8, 4, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 13, 9, 8, 4, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},

	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 0,2,2,2, 2,2,2,0, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},

	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},

	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},

	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},

	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
	{2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,},
};


static int tile_w=32,tile_h=32;


/* http://www.helixsoft.nl/articles/circle/sincos.htm */

static double space_z=2.5; // height of the camera above the plane
static int horizon=-2;    // number of pixels line 0 is below the horizon
static double scale_x=20, scale_y=20; 
		// scale of space coordinates to screen coordinates
static double bmp_w=40, bmp_h=40;

//void mode_7 (BITMAP *bmp, BITMAP *tile, fixed angle, fixed cx, fixed cy, MODE_7_PARAMS params)

double BETA=-0.6;

void draw_background_mode7(double angle, double cx, double cy) {

	// current screen position
	int screen_x, screen_y;

	// the distance and horizontal scale of the line we are drawing
	double distance, horizontal_scale;

	// masks to make sure we don't read pixels outside the tile
	int mask_x = (tile_w - 1);
	int mask_y = (tile_h - 1);

	// step for points in space between two pixels on a horizontal line
	double  line_dx, line_dy;

	// current space position
	double space_x, space_y;

	clear_top(0);

	color_equals(COLOR_MEDIUMBLUE);
	for(screen_y=0;screen_y<6;screen_y+=2) {
		hlin_double(0, 0, 40, screen_y);
	}
	color_equals(COLOR_GREY);
	hlin_double(0, 0, 40, 6);

	for (screen_y = 8; screen_y < bmp_h; screen_y++) {
		// first calculate the distance of the line we are drawing
		distance = (space_z * scale_y) / (screen_y + horizon);

		// then calculate the horizontal scale, or the distance between
		// space points on this horizontal line
		horizontal_scale = (distance / scale_x);

		// calculate the dx and dy of points in space when we step
		// through all points on this line
		line_dx = -sin(angle) * horizontal_scale;
		line_dy = cos(angle) * horizontal_scale;

		// calculate the starting position
		space_x = cx + (distance * cos(angle)) - bmp_w/2 * line_dx;
		space_y = cy + (distance * sin(angle)) - bmp_w/2 * line_dy;

		space_x+=(BETA*space_z*cos(angle));
		space_y+=(BETA*space_z*sin(angle));


		// go through all points in this screen line
		for (screen_x = 0; screen_x < bmp_w; screen_x++) {
			// get a pixel from the tile and put it on the screen

			color_equals(flying_map[(int)space_x & mask_x]
					[(int)space_y&mask_y]);

			basic_plot(screen_x,screen_y);

			// advance to the next position in space
			space_x += line_dx;
			space_y += line_dy;
		}
	}
}


int flying(void) {

	int i;
	unsigned char ch;
	int xx,yy;
	int turning=0;
	double flyx=0,flyy=0;
	double our_angle=0.0;
	double dy,dx,speed=0;

	/************************************************/
	/* Flying					*/
	/************************************************/

	gr();
	xx=17;	yy=26;
	color_equals(COLOR_BLACK);


	color_equals(COLOR_MEDIUMBLUE);

	for(i=0;i<20;i++) {
		hlin(1, 0, 40, i);
	}

	color_equals(COLOR_DARKBLUE);
	for(i=20;i<48;i++) {
		hlin(1, 0, 40, i);
	}

	while(1) {
		ch=grsim_input();

		if ((ch=='q') || (ch==27))  break;

		if (ch=='g') {
			BETA+=0.1;
			printf("Horizon=%lf\n",BETA);
		}
		if (ch=='h') {
			BETA-=0.1;
			printf("Horizon=%lf\n",BETA);
		}

		if (ch=='s') {
			scale_x++;
			scale_y++;
			printf("Scale=%lf\n",scale_x);
		}

		if ((ch=='i') || (ch==APPLE_UP)) {
			if (yy>16) {
				yy-=2;
				space_z+=1;
			}

			printf("Z=%lf\n",space_z);
		}
		if ((ch=='m') || (ch==APPLE_DOWN)) {
			if (yy<30) {
				yy+=2;
				space_z-=1;
			}
			printf("Z=%lf\n",space_z);
		}
		if ((ch=='j') || (ch==APPLE_LEFT)) {
			if (turning>0) {
				turning=0;
			}
			else {
				turning=-20;

				our_angle-=(6.28/32.0);
				if (our_angle<0.0) our_angle+=6.28;
			}
		//	printf("Angle %lf\n",our_angle);
		}
		if ((ch=='k') || (ch==APPLE_RIGHT)) {
			if (turning<0) {
				turning=0;
			}
			else {
				turning=20;
				our_angle+=(6.28/32.0);
				if (our_angle>6.28) our_angle-=6.28;
			}


		}

		if (ch=='z') {
			speed+=0.05;
		}

		if (ch=='x') {
			speed-=0.05;
		}

		if (ch==' ') {
			speed=0;
		}


		{
			dx = speed * cos (our_angle);
			dy = speed * sin (our_angle);

		        flyx += dx;
        		flyy += dy;
		}

//		gr_copy(0x800,0x400);

		draw_background_mode7(our_angle, flyx, flyy);

		grsim_put_sprite(0,ship_shadow,xx,30);

		if (turning==0) grsim_put_sprite(0,ship_forward,xx,yy);
		if (turning<0) {
			grsim_put_sprite(0,ship_left,xx,yy);
			turning++;
		}
		if (turning>0) {
			grsim_put_sprite(0,ship_right,xx,yy);
			turning--;
		}

		grsim_update();

		usleep(20000);

	}
	return 0;
}

