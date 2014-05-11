#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	FILE * in_file ;
	FILE * out_file ;
	int i = 0;
	int fread_ret = 0;
	
	int t_total_array[1];
	int read_n[1];
	int read_k[1];
	int t_total_loops = 0 ;
	int temp = 1;
	char temp_char ;

	

	
#if 1
	printf("\n Starting the Program \n");
	printf("\n Reading the input file\n");

	in_file = fopen("C:\\jam\\src\\testing5\\input_file\\problem1.in", "r");
	if (in_file == NULL)
	printf ("\n Error in opening the input file \n");
	else
	printf ("\n Successfully opened the input file \n");


	printf("\n Opening the output file\n");

	out_file = fopen("C:\\jam\\src\\testing5\\output_file\\problem1.out", "w");
	if (out_file == NULL)
	printf ("\n Error in opening the output file \n");
	else
	printf ("\n Successfully opened the output file \n");


	/*Assuming I will be reading numbers*/
	fread_ret = fscanf(in_file, "%d", t_total_array );
	
	if(fread_ret != 1)
	{
		printf("\n Error in reading first row inthe file, fread val is %d \n", fread_ret);
		exit(0);
	}
	

	if ((t_total_array[0] <= 10000) && (t_total_array[0] >= 1)) 
	{
		temp = 1 ;

	}
	else
	{
		printf("\n Error in reading one of the rows inthe file, t_total_array[0] val is %d \n", t_total_array[0]);
		exit(0);
	}


	t_total_loops = t_total_array[0] ;

	while (t_total_loops >= 1)
	{
						
						//fread_ret = fscanf(in_file, "%c", temp_char);
						fread_ret = fscanf(in_file, "%d %d", read_n, read_k );

						
						if(fread_ret != 2)
						{
							printf("\n Error in reading one of the rows inthe file, fread val is %d \n", fread_ret);
							exit(0);
						}
						if ((read_n[0] <= 30) && (read_n[0] >= 1))
						{
							temp = 1 ;

						}
						else
						{
							printf("\n Error in reading one of the rows inthe file, read_n[0] val is %d \n", read_n[0]);
							exit(0);
						}
						if ((read_k[0] <= 100) && (read_k[0] >= 0)) /*Limit to be changed to 10^8*/
						{
							temp = 1 ;

						}
						else
						{
							printf("\n Error in reading one of the rows inthe file, read_k[0] val is %d \n", read_k[0]);
							exit(0);
						}



						/*Check fread ret val*/
					#endif
						

						{	
								int n = read_n[0];
								int k = read_k[0];
								int max_dec_val = 0 ; 
								int remainder = 0 ;
								int bulb_state = 0 ;
								int sum = 0 ;
								int y = 0;
								static int output_count = 1 ;

								
								


								while (y  <= (n-1))
								{
									max_dec_val = max_dec_val + pow(2, y);
									y++;
								}
								

								if (k == 0)
								{
									
									bulb_state = 0 ; 
									goto bulb_state_derived ;
								}
								
								if (k > max_dec_val)
								{
									remainder = k% (max_dec_val + 1) ;   /*check if this giver reminder v imp*/ 
									if (remainder == max_dec_val)
									{
										bulb_state = 1 ; 
										goto bulb_state_derived ;
									}

								}
								else if (k <= max_dec_val)
								{
									if (k == max_dec_val)
									{
										bulb_state = 1 ; 
										goto bulb_state_derived ;
									}
									else
									{
										bulb_state = 0 ; 
										goto bulb_state_derived ;
									}
								}
								else
								{
									printf("\n BIG Error - should not have come here\n");
									exit(0);
								}
								


							bulb_state_derived: printf ("\n The bulb state is %d \n", bulb_state);
												if (bulb_state == 1)
												{
													fprintf (out_file, "Case #%d: ON\n", output_count);
													output_count++;
												}
												else if (bulb_state == 0)
												{
													fprintf (out_file, "Case #%d: OFF\n", output_count);
													output_count++;
												}
												else
												{
													printf("\n BIG problem - should not be here - bubl state is %d", bulb_state);
													exit(0);
												}
												

						}

	t_total_loops -- ;
	}
	

	fclose(in_file);
	fclose(out_file);
	return 0;
}
