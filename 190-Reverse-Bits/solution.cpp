class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t itr1_1 = (n&0x55555555)<<1; 
        uint32_t itr1_2 = (n&0xAAAAAAAA)>>1; 
        n = itr1_1 | itr1_2;
        
        itr1_1 = (n&0x33333333)<<2; 
        itr1_2 = (n&0xCCCCCCCC)>>2; 
        n = itr1_1 | itr1_2;

        itr1_1 = (n&0x0F0F0F0F)<<4; 
        itr1_2 = (n&0xF0F0F0F0)>>4; 
        n = itr1_1 | itr1_2;

        itr1_1 = (n&0x00FF00FF)<<8; 
        itr1_2 = (n&0xFF00FF00)>>8; 
        n = itr1_1 | itr1_2;

        itr1_1 = (n&0x0000FFFF)<<16; 
        itr1_2 = (n&0xFFFF0000)>>16; 
        n = itr1_1 | itr1_2;
        
        return n;
    }
};