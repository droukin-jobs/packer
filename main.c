#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include "packer.h"
//pack and unpack small values

#define MAX_SIZE ( 1<<28)
/*
#define C_S 0 
#define A_S 2 
#define C_BM 0b00000011
#define A_BM 0b00000011

//note that i % 2 == i & 1

#define PACK_CARD(I,V) (((V) << (((I) & 1) << 2)) << (C_S))
#define PACK_ACCT(I,V) (((V) << (((I) & 1) << 2)) << (A_S))
#define UNPACK_CARD(I) cards[(((arr[((I) >> 1)] >> (((I) & 1) << 2)) >> (C_S)) & (C_BM))]
#define UNPACK_ACCT(I) accts[(((arr[((I) >> 1)] >> (((I) & 1) << 2)) >> (A_S)) & (A_BM))]
*/


int main(void){
	char *cards[3]={"Visa","Master","EFTPOS"};
	char *accts[3]={"Credit","Cheque","Savings"};
	int i;
	srand(time(NULL));
	time_t ts, te;
	time(&ts);
#ifdef PACK
	uint8_t *arr = (uint8_t*)malloc((MAX_SIZE >> 1)*sizeof(uint8_t));
	printf("PACK %lu chars\n", MAX_SIZE >> 1);
	for(i=0;i<MAX_SIZE;i++){
		int r = rand() % 3;
		if (!(i & 1)) arr[i >> 1 ] = 0;
		if(i % (MAX_SIZE / 10) == 0)
			printf("%d. C = %s, ",i,cards[r]);
		arr[i >> 1 ] |= PACK_CARD(i,r);
		r = rand() % 3;
		arr[i >> 1 ] |= PACK_ACCT(i,r);
		if(i % (MAX_SIZE / 10) == 0)
			printf("A = %s\n",accts[r]);
	}
	printf("UNPACK\n");
	for(i=0;i<MAX_SIZE;i++){
		if(i % (MAX_SIZE / 10) == 0){
			printf("%d. C = %s, ",i,UNPACK_CARD(i));
			printf("A = %s\n",UNPACK_ACCT(i));
		}
	}
#endif
#ifdef STRUCT
	
	struct s_type {
		uint8_t acct:2;
		uint8_t card:2;
	};
	struct s_type *str = malloc(MAX_SIZE*sizeof(struct s_type));
	printf("COPY %lu structs\n", MAX_SIZE << 1);
	for(i=0;i<MAX_SIZE;i++){
		int r = rand() % 3;
		if(i % (MAX_SIZE / 10) == 0)
			printf("%d. C = %s, ",i, cards[r]);
		str[i].card = r;
		r = rand() % 3;
		str[i].acct = r;
		if(i % (MAX_SIZE / 10) == 0)
			printf("A = %s\n",accts[r]);
	}
	printf("DISPLAY\n");
	for(i=0;i<MAX_SIZE;i++){
		if(i % (MAX_SIZE / 10) == 0){
			printf("%d. C = %s, ",i,cards[str[i].card]);
			printf("A = %s\n",accts[str[i].acct]);
		}
	}
#endif
#ifdef ARRAY	
	uint8_t *c_arr = (uint8_t*)malloc(MAX_SIZE*sizeof(uint8_t));
	uint8_t *a_arr = (uint8_t*)malloc(MAX_SIZE*sizeof(uint8_t));
	printf("COPY %lu chars\n", MAX_SIZE << 1);
	for(i=0;i<MAX_SIZE;i++){
		int r = rand() % 3;
		c_arr[i] = 0;
		a_arr[i] = 0;
		if(i % (MAX_SIZE / 10) == 0)
			printf("%d. C = %s, ",i, cards[r]);
		c_arr[i] = r;
		r = rand() % 3;
		a_arr[i] = r;
		if(i % (MAX_SIZE / 10) == 0)
			printf("A = %s\n",accts[r]);
	}
	printf("DISPLAY\n");
	for(i=0;i<MAX_SIZE;i++){
		if(i % (MAX_SIZE / 10) == 0){
			int ms = ((i % 2) << 2);
			printf("%d. C = %s, ",i,cards[c_arr[i]]);
			printf("A = %s\n",accts[a_arr[i]]);
		}
	}
#endif
	time(&te);
	printf("Time taken: %f seconds\n",difftime(te,ts));
	
	return 0;
}
