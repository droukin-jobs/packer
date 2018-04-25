
#define C_S 0 
#define A_S 2 
#define C_BM 0b00000011
#define A_BM 0b00000011

//note that i % 2 == i & 1

#define PACK_CARD(I,V) (((V) << (((I) & 1) << 2)) << (C_S))
#define PACK_ACCT(I,V) (((V) << (((I) & 1) << 2)) << (A_S))
#define UNPACK_CARD(I) cards[(((arr[((I) >> 1)] >> (((I) & 1) << 2)) >> (C_S)) & (C_BM))]
#define UNPACK_ACCT(I) accts[(((arr[((I) >> 1)] >> (((I) & 1) << 2)) >> (A_S)) & (A_BM))]
