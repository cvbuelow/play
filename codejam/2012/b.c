/*
 *  b.c
 *  
 *
 *  Created by Carl von Buelow on 4/14/12.
 *  Copyright 2012 socceresque.com - All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

//const int MAXC = 36;
//const int MAXD = 28;
const int MAXN = 100;


int main(void) 
{
	int h,i,j,k;	//iterators
	int T;			//number of test cases
	int N;			//number of googlers
	int S;			//number of surprising triplets
	int p;			//best result of at least this
	int ti;			//total score
	int out;		//answer
	
	//int L;			//length of output array
	//int no_combo;	//keep track if matched a combo
	//int other_opp;	//keep track of which letter is matched for opp
	
	//char cmb [MAXC][3];
	//char opp [MAXD][2];
		//char out [MAXN];
	
	scanf("%d", &T);
	for(i = 1; i <= T; i++)
	{
		//init out
		out = 0;
		//memset(out, 0, sizeof(out));
		//L = 0;
		
		//read number of googlers
		scanf("%d", &N);
		
		//read number of surprising triplets
		scanf("%d", &S);
		
		//read letters to invoke
		scanf("%d", &p);
		
		//read score totals
		for(k = 0; k < N; k++)
		{
			scanf("%d", &ti);
			if(ti > (p * 3) - 1)
				out++;
			else if(S && ti == (p * 3) - 1)
			{
				out++;
				S--;
			}
		}
		//output result
		printf("Case #%d: %d\n", i, out);
	}
	return 0;
}