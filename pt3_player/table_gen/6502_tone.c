#include <stdio.h>
#include <string.h>

// 8*12
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

static unsigned short Tone[256];
//static unsigned char ToneHigh[256];
//static unsigned char ToneLow[256];


// NoteTableCreator (c) Ivan Roshin
// A - NoteTableNumber*2+VersionForNoteTable
// (xx1b - 3.xx..3.4r, xx0b - 3.4x..3.6x..VTII1.0)

#if 0
unsigned short base[]={
0x0D10*2,(0x0C55*2)+1,0x0BA4*2,0x0AFC*2,0x0A5F*2,0x09CA*2,
0x093D*2,0x08B8*2,0x083B*2,0x07C5*2,0x0755*2,0x06EC*2,
};
#endif
unsigned short base[]={
0x0D10,0x0C55,0x0BA4,0x0AFC,0x0A5F,0x09CA,
0x093D,0x08B8,0x083B,0x07C5,0x0755,0x06EC,
};


unsigned short base2[]={
  0x0EF8,0x0E10,0x0D60,0x0C80,0x0BD8,0x0B28,0x0A88,0x09F0,  // 50
  0x0960,0x08E0,0x0858,0x07E0,
};

void NoteTableCreate0(void) {

	int x,y;

	for(y=0;y<12;y++) {
		Tone[y]=base2[y];
		//ToneHigh[y]=base2[y]>>8;
		//ToneLow[y]=base2[y]&0xff;
	}

	for(x=0;x<84;x++) {
		Tone[x+12]=Tone[x]>>1;
	}

	Tone[23]+=13;
	Tone[46]-=1;
}

/*
0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  1  0
0  0  0  0  1  0  0  0  1  0  0  0
0  1  0  1  1  0  1  0  0  1  1  0

0  0  0  1  1  1  1  1  1  0  0  1
1  1  0  1  1  0  1  1  1  0  1  0
0  0  1  1  0  0  1  1  1  0  0  1
0  1  0  1  1  1  0  0  0  0  0  0
*/

static unsigned char table1_adjust[]={
0x20, 0xa8, 0x40, 0xf8, 0xbc, 0x90, 0x78, 0x70, 0x74, 0x08, 0x2a, 0x50
};


void NoteTableCreate1(void) {

	int x,y;
	int extra;

	for(y=0;y<12;y++) Tone[y]=base[y];

	for(x=0;x<84;x++) {
		Tone[x+12]=Tone[x]>>1;
	}

	int blah;
	int offset=0;
	for(y=0;y<12;y++) {
		offset=y;
		blah=table1_adjust[y];
		for(x=0;x<8;x++) {
			extra=blah&1;
			blah>>=1;

//			printf("%d ",extra);
//			if (x%12==11) printf("\n");

			Tone[offset]+=extra;
			offset+=12;
		}
	}

//	Tone[95]--;

}



int main(int argc, char **argv) {

	int i;


	/* Test table 0 */
	NoteTableCreate0();

	for(i=0;i<8*12;i++) {
		if (i%12==0) printf("\n");
		printf(" %03X",Tone[i]);
		if (Tone[i]-PT3NoteTable_ST[i]) {
			printf("+%d",Tone[i]-PT3NoteTable_ST[i]);
		}
		else {
			printf("  ");
		}
	}
	printf("\n");

	if (!memcmp(Tone,PT3NoteTable_ST,8*12*sizeof(short))) {
		printf("MATCH 35\n");
	}
	else {
		printf("NO MATCH 35\n");
	}

	if (!memcmp(Tone,PT3NoteTable_ASM_34_35,8*12*sizeof(short))) {
		printf("MATCH 34\n");
	}
	else {
		printf("NO MATCH 34\n");
	}


	/* Test table 1 */

	NoteTableCreate1();

	int nomatch=0;

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

	if (!memcmp(Tone,PT3NoteTable_ST,8*12*sizeof(short))) {
		printf("MATCH 35\n");
	}
	else {
		printf("NO MATCH 35\n");
	}

	if (!memcmp(Tone,PT3NoteTable_ASM_34_35,8*12*sizeof(short))) {
		printf("MATCH 34\n");
	}
	else {
		printf("NO MATCH 34\n");
	}

	printf("Nomatch count=%d\n",nomatch);

}



