/*
 *  snapper.c
 *  
 *
 *  Created by Carl von Buelow on 5/8/10.
 *  Copyright 2010 socceresque.com - All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>


int main(void) 
{
	int i, k;	//iterators
	int T;			//number of test cases
	int N;			//number of snapper devices
	int K;			//number of times fingers snapped
	int light_on;
	
	scanf("%d", &T);
	for(i = 1; i <= T; i++)
	{
		scanf("%d %d", &N, &K);
		int snapper[N];
		memset(snapper, 0, N*sizeof(int));	//initialize snappers to OFF (0)
		light_on = 1;
		
		while(K--)
		{
			k = 0;
			while(!(snapper[k] = !snapper[k]) && k < N)
			{
				k++;
			}
		}
		
		//check if the light is on after the last snap
		for(k = 0; k < N; k++)
		{
			if(!snapper[k])	
			{
				light_on = 0;
				break;
			}
		}
		printf("Case #%d: %s\n", i, light_on ? "ON" : "OFF");
	}
	return 0;
}