#include <stdio.h>
#include <string.h>


/* Table #0 of Pro Tracker 3.3x - 3.4r */
static unsigned short PT3NoteTable_PT_33_34r[]={
  0xC21,0xB73,0xACE,0xA33,0x9A0,0x916,0x893,0x818,0x7A4,0x736,0x6CE,0x66D,
  0x610,0x5B9,0x567,0x519,0x4D0,0x48B,0x449,0x40C,0x3D2,0x39B,0x367,0x336,
  0x308,0x2DC,0x2B3,0x28C,0x268,0x245,0x224,0x206,0x1E9,0x1CD,0x1B3,0x19B,
  0x184,0x16E,0x159,0x146,0x134,0x122,0x112,0x103,0x0F4,0x0E6,0x0D9,0x0CD,
  0x0C2,0x0B7,0x0AC,0x0A3,0x09A,0x091,0x089,0x081,0x07A,0x073,0x06C,0x066,
  0x061,0x05B,0x056,0x051,0x04D,0x048,0x044,0x040,0x03D,0x039,0x036,0x033,
  0x030,0x02D,0x02B,0x028,0x026,0x024,0x022,0x020,0x01E,0x01C,0x01B,0x019,
  0x018,0x016,0x015,0x014,0x013,0x012,0x011,0x010,0x00F,0x00E,0x00D,0x00C,
};

/* Table #0 of Pro Tracker 3.4x - 3.5x */
static unsigned short PT3NoteTable_PT_34_35[]={
  0xC22,0xB73,0xACF,0xA33,0x9A1,0x917,0x894,0x819,0x7A4,0x737,0x6CF,0x66D,
  0x611,0x5BA,0x567,0x51A,0x4D0,0x48B,0x44A,0x40C,0x3D2,0x39B,0x367,0x337,
  0x308,0x2DD,0x2B4,0x28D,0x268,0x246,0x225,0x206,0x1E9,0x1CE,0x1B4,0x19B,
  0x184,0x16E,0x15A,0x146,0x134,0x123,0x112,0x103,0x0F5,0x0E7,0x0DA,0x0CE,
  0x0C2,0x0B7,0x0AD,0x0A3,0x09A,0x091,0x089,0x082,0x07A,0x073,0x06D,0x067,
  0x061,0x05C,0x056,0x052,0x04D,0x049,0x045,0x041,0x03D,0x03A,0x036,0x033,
  0x031,0x02E,0x02B,0x029,0x027,0x024,0x022,0x020,0x01F,0x01D,0x01B,0x01A,
  0x018,0x017,0x016,0x014,0x013,0x012,0x011,0x010,0x00F,0x00E,0x00D,0x00C,
};


/* Table #1 for all versions */
static unsigned short PT3NoteTable_ST[]={
  0xEF8,0xE10,0xD60,0xC80,0xBD8,0xB28,0xA88,0x9F0,0x960,0x8E0,0x858,0x7E0,
  0x77C,0x708,0x6B0,0x640,0x5EC,0x594,0x544,0x4F8,0x4B0,0x470,0x42C,0x3FD,
  0x3BE,0x384,0x358,0x320,0x2F6,0x2CA,0x2A2,0x27C,0x258,0x238,0x216,0x1F8,
  0x1DF,0x1C2,0x1AC,0x190,0x17B,0x165,0x151,0x13E,0x12C,0x11C,0x10A,0x0FC,
  0x0EF,0x0E1,0x0D6,0x0C8,0x0BD,0x0B2,0x0A8,0x09F,0x096,0x08E,0x085,0x07E,
  0x077,0x070,0x06B,0x064,0x05E,0x059,0x054,0x04F,0x04B,0x047,0x042,0x03F,
  0x03B,0x038,0x035,0x032,0x02F,0x02C,0x02A,0x027,0x025,0x023,0x021,0x01F,
  0x01D,0x01C,0x01A,0x019,0x017,0x016,0x015,0x013,0x012,0x011,0x010,0x00F,
};

/* Table #2 of Pro Tracker 3.4r */
static unsigned short PT3NoteTable_ASM_34r[]={
  0xD3E,0xC80,0xBCC,0xB22,0xA82,0x9EC,0x95C,0x8D6,0x858,0x7E0,0x76E,0x704,
  0x69F,0x640,0x5E6,0x591,0x541,0x4F6,0x4AE,0x46B,0x42C,0x3F0,0x3B7,0x382,
  0x34F,0x320,0x2F3,0x2C8,0x2A1,0x27B,0x257,0x236,0x216,0x1F8,0x1DC,0x1C1,
  0x1A8,0x190,0x179,0x164,0x150,0x13D,0x12C,0x11B,0x10B,0x0FC,0x0EE,0x0E0,
  0x0D4,0x0C8,0x0BD,0x0B2,0x0A8,0x09F,0x096,0x08D,0x085,0x07E,0x077,0x070,
  0x06A,0x064,0x05E,0x059,0x054,0x050,0x04B,0x047,0x043,0x03F,0x03C,0x038,
  0x035,0x032,0x02F,0x02D,0x02A,0x028,0x026,0x024,0x022,0x020,0x01E,0x01D,
  0x01B,0x01A,0x019,0x018,0x015,0x014,0x013,0x012,0x011,0x010,0x00F,0x00E
};

/* Table #2 of Pro Tracker 3.4x - 3.5x */
static unsigned short PT3NoteTable_ASM_34_35[] = {
  0xD10,0xC55,0xBA4,0xAFC,0xA5F,0x9CA,0x93D,0x8B8,0x83B,0x7C5,0x755,0x6EC,
  0x688,0x62A,0x5D2,0x57E,0x52F,0x4E5,0x49E,0x45C,0x41D,0x3E2,0x3AB,0x376,
  0x344,0x315,0x2E9,0x2BF,0x298,0x272,0x24F,0x22E,0x20F,0x1F1,0x1D5,0x1BB,
  0x1A2,0x18B,0x174,0x160,0x14C,0x139,0x128,0x117,0x107,0x0F9,0x0EB,0x0DD,
  0x0D1,0x0C5,0x0BA,0x0B0,0x0A6,0x09D,0x094,0x08C,0x084,0x07C,0x075,0x06F,
  0x069,0x063,0x05D,0x058,0x053,0x04E,0x04A,0x046,0x042,0x03E,0x03B,0x037,
  0x034,0x031,0x02F,0x02C,0x029,0x027,0x025,0x023,0x021,0x01F,0x01D,0x01C,
  0x01A,0x019,0x017,0x016,0x015,0x014,0x012,0x011,0x010,0x00F,0x00E,0x00D,
};

/* Table #3 of Pro Tracker 3.4r */
static unsigned short PT3NoteTable_REAL_34r[] = {
  0xCDA,0xC22,0xB73,0xACF,0xA33,0x9A1,0x917,0x894,0x819,0x7A4,0x737,0x6CF,
  0x66D,0x611,0x5BA,0x567,0x51A,0x4D0,0x48B,0x44A,0x40C,0x3D2,0x39B,0x367,
  0x337,0x308,0x2DD,0x2B4,0x28D,0x268,0x246,0x225,0x206,0x1E9,0x1CE,0x1B4,
  0x19B,0x184,0x16E,0x15A,0x146,0x134,0x123,0x113,0x103,0x0F5,0x0E7,0x0DA,
  0x0CE,0x0C2,0x0B7,0x0AD,0x0A3,0x09A,0x091,0x089,0x082,0x07A,0x073,0x06D,
  0x067,0x061,0x05C,0x056,0x052,0x04D,0x049,0x045,0x041,0x03D,0x03A,0x036,
  0x033,0x031,0x02E,0x02B,0x029,0x027,0x024,0x022,0x020,0x01F,0x01D,0x01B,
  0x01A,0x018,0x017,0x016,0x014,0x013,0x012,0x011,0x010,0x00F,0x00E,0x00D,
};

/* Table #3 of Pro Tracker 3.4x - 3.5x */
/* NOTE: ONLY DIFFERENCE IS 0x113 -> 0x112 */
static unsigned short PT3NoteTable_REAL_34_35[] = {
  0xCDA,0xC22,0xB73,0xACF,0xA33,0x9A1,0x917,0x894,0x819,0x7A4,0x737,0x6CF,
  0x66D,0x611,0x5BA,0x567,0x51A,0x4D0,0x48B,0x44A,0x40C,0x3D2,0x39B,0x367,
  0x337,0x308,0x2DD,0x2B4,0x28D,0x268,0x246,0x225,0x206,0x1E9,0x1CE,0x1B4,
  0x19B,0x184,0x16E,0x15A,0x146,0x134,0x123,0x112,0x103,0x0F5,0x0E7,0x0DA,
  0x0CE,0x0C2,0x0B7,0x0AD,0x0A3,0x09A,0x091,0x089,0x082,0x07A,0x073,0x06D,
  0x067,0x061,0x05C,0x056,0x052,0x04D,0x049,0x045,0x041,0x03D,0x03A,0x036,
  0x033,0x031,0x02E,0x02B,0x029,0x027,0x024,0x022,0x020,0x01F,0x01D,0x01B,
  0x01A,0x018,0x017,0x016,0x014,0x013,0x012,0x011,0x010,0x00F,0x00E,0x00D,
};


static unsigned short Tone[256];


unsigned short base0_v3[]={
  0xC21,0xB73,0xACE,0xA33,0x9A0,0x916,0x893,0x818,0x7A4,0x736,0x6CE,0x66D,
};

unsigned short base0_v4[]={
  0xC22,0xB73,0xACF,0xA33,0x9A1,0x917,0x894,0x819,0x7A4,0x737,0x6CF,0x66D,
};

unsigned short base1[]={
  0xEF8,0xE10,0xD60,0xC80,0xBD8,0xB28,0xA88,0x9F0,0x960,0x8E0,0x858,0x7E0,
};

unsigned short base2_v3[]={
  0xD3E,0xC80,0xBCC,0xB22,0xA82,0x9EC,0x95C,0x8D6,0x858,0x7E0,0x76E,0x704,
};

unsigned short base2_v4[]={
  0xD10,0xC55,0xBA4,0xAFC,0xA5F,0x9CA,0x93D,0x8B8,0x83B,0x7C5,0x755,0x6EC,
};

/* note: same for both versions */
unsigned short base3[]={
  0xCDA,0xC22,0xB73,0xACF,0xA33,0x9A1,0x917,0x894,0x819,0x7A4,0x737,0x6CF,
};


static void NoteTablePropogate(unsigned short *base_table) {

	int x,y;

	for(y=0;y<12;y++) Tone[y]=base_table[y];

	for(x=0;x<84;x++) {
		Tone[x+12]=Tone[x]>>1;
	}

}

static void NoteTableAdjust(unsigned char *adjust_table) {

	int blah,extra;
	int offset=0;
	int x,y;

	for(y=0;y<12;y++) {
		offset=y;
		blah=adjust_table[y];
		for(x=0;x<8;x++) {
			extra=blah&1;
			blah>>=1;

//			printf("%d ",extra);
//			if (x%12==11) printf("\n");

			Tone[offset]+=extra;
			offset+=12;
		}
	}

	return;
}


/* create table #0 v3.3 "PT3NoteTable_PT_33_34r" */
static void NoteTableCreate_0_v3(void) {

	NoteTablePropogate(base0_v3);
}

static unsigned char table0_v4_adjust[]={
  0x40, 0xe6, 0x9c, 0x66, 0x40, 0x2c, 0x20, 0x30, 0x48, 0x6c, 0x1c, 0x5a,
};

/* create table #0 v3.4 "PT3NoteTable_PT_34_35" */
static void NoteTableCreate_0_v4(void) {

	NoteTablePropogate(base0_v4);
	NoteTableAdjust(table0_v4_adjust);
}



/* create table #1 "PT3NoteTable_ST" */
void NoteTableCreate_1_vX(void) {

	NoteTablePropogate(base1);

	Tone[23]+=13;
	Tone[46]-=1;
}

static unsigned char table2_v3_adjust[]={
  0xf8, 0x80, 0x90, 0xc0, 0x04, 0xf0, 0xf8, 0xec, 0xe0, 0xc0, 0xfc, 0x40,
};

/* Create Table #2, v3, "PT3NoteTable_ASM_34r" */
void NoteTableCreate_2_v3(void) {

	NoteTablePropogate(base2_v3);
	NoteTableAdjust(table2_v3_adjust);
	Tone[86]+=1;
	Tone[87]+=1;
}

static unsigned char table2_v4_adjust[]={
  0x20, 0xa8, 0x40, 0xf8, 0xbc, 0x90, 0x78, 0x70, 0x74, 0x08, 0x2a, 0x50,
};


/* Create Table #2, v4+, "PT3NoteTable_ASM_34_35" */
void NoteTableCreate_2_v4(void) {

	NoteTablePropogate(base2_v4);
	NoteTableAdjust(table2_v4_adjust);
}

static unsigned char table3_v4_adjust[]={
  0xB4, 0x40, 0xe6, 0x9c, 0x66, 0x40, 0x2c, 0x20, 0x30, 0x48, 0x6c, 0x1c,
};

/* Create Table #3, v3, "PT3NoteTable_REAL_34r" */
void NoteTableCreate_3_v3(void) {

	NoteTablePropogate(base3);
	NoteTableAdjust(table3_v4_adjust);
	Tone[43]++;
}



/* Create Table #3, v4+, "PT3NoteTable_REAL_34_35" */
void NoteTableCreate_3_v4(void) {

//	int x,y;
//	int extra;

	NoteTablePropogate(base3);
	NoteTableAdjust(table3_v4_adjust);
}




int main(int argc, char **argv) {

	int i;
	int nomatch=0;


	/***********************************/
	/* Test table #0 Version <=3.3     */
	/* PT3NoteTable_PT_33_34r          */
	/***********************************/

	printf("\n");
	printf("*********************\n");
	printf("Test Table 0 v3\n");
	printf("*********************\n");

	NoteTableCreate_0_v3();

	nomatch=0;

	for(i=0;i<8*12;i++) {
		if (i%12==0) printf("\n");
		printf("%03X",Tone[i]);
		if (Tone[i]-PT3NoteTable_PT_33_34r[i]) {
			printf("+%d|",Tone[i]-PT3NoteTable_PT_33_34r[i]);
			nomatch++;
			//printf("%03X",PT3NoteTable_ASM_34_35[i]);
		}
		else {
			printf("   ");
		}
	}
	printf("\n");

	if (!memcmp(Tone,PT3NoteTable_PT_33_34r,8*12*sizeof(short))) {
		printf("MATCH Table 0 version 3.3\n");
	}
	else {
		printf("NO MATCH\n");
	}

	printf("Nomatch count=%d\n",nomatch);


	/***********************************/
	/* Test table #0 Version 3.4+      */
	/* PT3NoteTable_PT_34_35           */
	/***********************************/

	printf("\n");
	printf("*********************\n");
	printf("Test Table 0 v4+\n");
	printf("*********************\n");

	NoteTableCreate_0_v4();

	nomatch=0;

	for(i=0;i<8*12;i++) {
		if (i%12==0) printf("\n");
		printf("%03X",Tone[i]);
		if (Tone[i]-PT3NoteTable_PT_34_35[i]) {
			printf("+%d|",Tone[i]-PT3NoteTable_PT_34_35[i]);
			nomatch++;
			//printf("%03X",PT3NoteTable_ASM_34_35[i]);
		}
		else {
			printf("   ");
		}
	}
	printf("\n");

	if (!memcmp(Tone,PT3NoteTable_PT_34_35,8*12*sizeof(short))) {
		printf("MATCH Table 0 version 3.4\n");
	}
	else {
		printf("NO MATCH\n");
	}

	printf("Nomatch count=%d\n",nomatch);




	/***********************************/
	/* Test table 1 all versions       */
	/* "PT3NoteTable_ST"               */
	/***********************************/

	printf("\n");
	printf("*********************\n");
	printf("Test Table 1\n");
	printf("*********************\n");

	nomatch=0;

	NoteTableCreate_1_vX();


	for(i=0;i<8*12;i++) {
		if (i%12==0) printf("\n");
		printf(" %03X",Tone[i]);
		if (Tone[i]-PT3NoteTable_ST[i]) {
			printf("+%d",Tone[i]-PT3NoteTable_ST[i]);
			nomatch++;
		}
		else {
			printf("  ");
		}
	}
	printf("\n");

	if (!memcmp(Tone,PT3NoteTable_ST,8*12*sizeof(short))) {
		printf("MATCH Table 1\n");
	}
	else {
		printf("NO MATCH Table 1\n");
	}

	printf("Nomatch count=%d\n",nomatch);

	/***********************************/
	/* Test table #2 Version 3.4r      */
	/* ASM_34r                         */
	/***********************************/

	printf("\n");
	printf("*********************\n");
	printf("Test Table 2 v3.4r\n");
	printf("*********************\n");

	NoteTableCreate_2_v3();

	nomatch=0;

	for(i=0;i<8*12;i++) {
		if (i%12==0) printf("\n");
		printf("%03X",Tone[i]);
		if (Tone[i]-PT3NoteTable_ASM_34r[i]) {
			printf("+%d/",Tone[i]-PT3NoteTable_ASM_34r[i]);
			nomatch++;
		}
		else {
			printf("   ");
		}
	}
	printf("\n");

	if (!memcmp(Tone,PT3NoteTable_ASM_34r,8*12*sizeof(short))) {
		printf("MATCH Table 2 v3.4r\n");
	}
	else {
		printf("NO MATCH\n");
	}

	printf("Nomatch count=%d\n",nomatch);


	/***********************************/
	/* Test table #2 Version 3.4 - 3.5 */
	/* ASM_34_35                       */
	/***********************************/

	printf("\n");
	printf("*********************\n");
	printf("Test Table 2 v3.4+\n");
	printf("*********************\n");

	NoteTableCreate_2_v4();

	nomatch=0;

	for(i=0;i<8*12;i++) {
		if (i%12==0) printf("\n");
		printf("%03X",Tone[i]);
		if (Tone[i]-PT3NoteTable_ASM_34_35[i]) {
			printf("+%d/",Tone[i]-PT3NoteTable_ASM_34_35[i]);
			nomatch++;
			//printf("%03X",PT3NoteTable_ASM_34_35[i]);
		}
		else {
			printf("   ");
		}
	}
	printf("\n");

	if (!memcmp(Tone,PT3NoteTable_ASM_34_35,8*12*sizeof(short))) {
		printf("MATCH Table 2 v4\n");
	}
	else {
		printf("NO MATCH 34\n");
	}

	printf("Nomatch count=%d\n",nomatch);

	/***********************************/
	/* Test table #3 Version 3.4r      */
	/* ASM_34r                         */
	/***********************************/

	printf("\n");
	printf("*********************\n");
	printf("Test Table 3 v3.4r\n");
	printf("*********************\n");

	NoteTableCreate_3_v3();

	nomatch=0;

	for(i=0;i<8*12;i++) {
		if (i%12==0) printf("\n");
		printf("%03X",Tone[i]);
		if (Tone[i]-PT3NoteTable_REAL_34r[i]) {
			printf("+%d/",Tone[i]-PT3NoteTable_REAL_34r[i]);
			nomatch++;
		}
		else {
			printf("   ");
		}
	}
	printf("\n");

	if (!memcmp(Tone,PT3NoteTable_REAL_34r,8*12*sizeof(short))) {
		printf("MATCH Table 3 v3.4r\n");
	}
	else {
		printf("NO MATCH\n");
	}

	printf("Nomatch count=%d\n",nomatch);


	/***********************************/
	/* Test table #3 Version 3.4 - 3.5 */
	/* REAL_34_35                       */
	/***********************************/

	printf("\n");
	printf("*********************\n");
	printf("Test Table 3 v3.4+\n");
	printf("*********************\n");

	NoteTableCreate_3_v4();

	nomatch=0;

	for(i=0;i<8*12;i++) {
		if (i%12==0) printf("\n");
		printf("%03X",Tone[i]);
		if (Tone[i]-PT3NoteTable_REAL_34_35[i]) {
			printf("+%d/",Tone[i]-PT3NoteTable_REAL_34_35[i]);
			nomatch++;
		}
		else {
			printf("   ");
		}
	}
	printf("\n");

	if (!memcmp(Tone,PT3NoteTable_REAL_34_35,8*12*sizeof(short))) {
		printf("MATCH Table 3 v3.4+\n");
	}
	else {
		printf("NO MATCH\n");
	}

	printf("Nomatch count=%d\n",nomatch);


}



