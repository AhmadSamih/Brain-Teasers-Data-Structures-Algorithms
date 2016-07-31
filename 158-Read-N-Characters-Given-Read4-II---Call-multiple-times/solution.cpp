// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
     #define window 4
     char cache[window];
     int curp = 0, remaining = 0;
     
    int read(char *buf, int n) {
        if (n <= 0) return n; int idx = 0;
        
        while (remaining > 0 && idx < n) {
            buf[idx++] = cache[curp++]; 
            --remaining; // If we have some data left lets read that
            if(curp ==4) curp = 0;
        }
        
        while (true)
        {
            if (idx >= n) return idx;
            remaining = read4(cache);
            if (remaining == 0) return idx;

            while (remaining && idx < n) { // populate our buffer given we have bytes to read
                buf[idx++] = cache[curp++]; 
                --remaining;
                if(curp ==4) curp = 0;
            }
        }
    }
};