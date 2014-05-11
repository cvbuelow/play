/*
 *  b.c
 *  
 *
 *  Created by Carl von Buelow on 5/6/10.
 *  Copyright 2011 socceresque.com - All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

const int MAXC = 36;
const int MAXD = 28;
const int MAXN = 100;


int main(void) 
{
	int h,i,j,k;	//iterators
	int T;			//number of test cases
	int C;			//number of combination strings
	int D;			//number of opposed strings
	int N;			//number of letters to invoke
	int L;			//length of output array
	int no_combo;	//keep track if matched a combo
	int other_opp;	//keep track of which letter is matched for opp
	
	char cmb [MAXC][3];
	char opp [MAXD][2];
	char inv [MAXN];
	char out [MAXN];
	
	scanf("%d", &T);
	for(i = 1; i <= T; i++)
	{
		//init out
		memset(out, 0, sizeof(out));
		L = 0;
		
		//read combinations
		scanf("%d", &C);
		for(k = 0; k < C; k++)
			scanf("%s", cmb[k]);
		
		//read oppositions
		scanf("%d", &D);
		for(k = 0; k < D; k++)
			scanf("%s", opp[k]);
		
		//read letters to invoke
		scanf("%d", &N);
		scanf("%s", inv);
		for(k = 0; k < N; k++)
		{
			//check for combos or opps if list is not empty
			if(L)
			{
				//see if there is a combination match
				no_combo = 1;
				for(j = 0; j < C; j++)
				{
					if((out[L-1] == cmb[j][0] && inv[k] == cmb[j][1]) || (out[L-1] == cmb[j][1] && inv[k] == cmb[j][0]))
					{
						out[L-1] = cmb[j][2];
						no_combo = 0;
						break;
					}
				}
				
				//see if there is an opposition
				if(no_combo)
				{
					for(j = 0; j < D; j++)
					{
						if(inv[k] == opp[j][1])
							other_opp = 0;
						else if(inv[k] == opp[j][0])
							other_opp = 1;
						else
							other_opp = 2;
						if(other_opp < 2)
						{
							for(h = 0; h < L; h++)
							{
								if(out[h] == opp[j][other_opp])
								{
									//clear list
									memset(out, 0, sizeof(out));
									L = 0;
									break;
								}
							}
						}
					}
				}
				if(no_combo && L)
					out[L++] = inv[k];
			}
			else
				out[L++] = inv[k];
		}
		//output result
		printf("Case #%d: [", i);
		for(k = 0; k < L; k++)
			printf("%s%c", (k ? ", " : ""), out[k]);
		puts("]");
	}
	return 0;
}