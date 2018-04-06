#include <stdio.h>
#include <stdlib.h>
#include "sound.h"
#include <signal.h>
int main(void)
{
	int ret;
	while(1)
	{
		//record 1 sec of sound into test.wav
		ret = system("arecord -r16000 -c1 -f S16_LE -d1 -q test.wav");
		if(WIFSIGNALED(ret) && (WTERMSIG(ret)==SIGINT))	break;
		//open the wav file and read samples
		//display necessary information (duration, wav header etc)
		displayWAVheader("test.wav");
		//calculate fast dBs
		displayBar("test.wav");
	}
}
