#include "sound.h"
#include <stdio.h>
#include <math.h>
#include "screen.h"
// function definition of displayBar()

// this function opens the "test.wav" file and reads the second part(data) of
// this file. The samples should be in S16_LE format, and there are 16000 of
// them. The function processes every 200 samples and calculate their RMS value
// and renders this value as a vertical bar on terminal screen

void displayBar(char filename[])
{
	FILE*fp;
	short int samples[SAMPLERATE];
	double sum_200, rms_80[80], dB;
	int i,j;
	WAVHeader myhdr;	//dummy header to skip over the reading from file
	fp = fopen(filename, "r");
	if(fp == NULL)
	{
		printf("Error opening the file!\n");
		return;
	}
	fread(&myhdr, sizeof(WAVHeader), 1, fp);
	fread(&samples, sizeof(short), SAMPLERATE, fp);
	fclose(fp);
	// all the samples of 1sec are read to the array samples[], we need to
	// run a loop 80  times for 80 bars on the screen, and each iteration of
	// this loop will calculate a RMS value of 200 samples
	clearScreen();
	for(i=0; i<80; i++)
	{
		for(j=0,sum_200=0.0; j<200; j++)
		{
			sum_200 += samples[j+i*200]*samples[j+i*200];
		}
		rms_80[i] = sqrt(sum_200/200);
		dB = 20*log10(rms_80[i]);
#ifdef DEBUG
		printf("RMS[%d] = %10.4f = %10.4 fdB\n", i, rms_80[i], dB);
#else
	//in order to display sound value in a screen, we need to use dicibel
		bar(i, dB);
#endif
	}	// for
}	// function


// function definition of displayWAVheader()

void displayWAVheader(char filename[])
{
	WAVHeader myhdr;	// an instance of defined struct
	FILE *fp;
	fp = fopen(filename,"r");	//open the file for reading
	fclose(fp);
	if(fp == NULL)	// if open is failed
	{
		printf("ERROR of opening file!\n");
		return;
	}
	fread(&myhdr, sizeof(WAVHeader), 1, fp);
	printID(myhdr.chunkID);
	printf("chunk size: %d\n", myhdr.chunkSize);
	printID(myhdr.format);
	printID(myhdr.subchunk1ID);
	printf("subchunk 1 size : %d\n", myhdr.subchunk1Size);
	// there are more fields to be displayed
	printf("audio format : %d\n", myhdr.audioFormat);
	printf("num of channels : %d\n", myhdr.numChannels);
	printf("sample rate : %d\n", myhdr.sampleRate);
	printf("byte rate: %d\n", myhdr.byteRate);
	printf("block align : %d\n", myhdr.blockAlign);
	printf("bits per sample : %d\n", myhdr.bitsPerSample);
	printf(myhdr.subchunk2ID);
	printf("subchunk 2 size : %d\n", myhdr.subchunk2Size);

}

void printID(char id[])
{
	int i;
	for (i=0; i<4; i++)
		printf("%c", id[i]);
	printf("\n");
}
