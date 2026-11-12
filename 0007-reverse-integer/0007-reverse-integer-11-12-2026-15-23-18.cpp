class Solution {
public:
    int reverse(int x) {
        
        int s = 0;
        
        while (x != 0) {
            
            int r = x % 10;
            
            // Check positive overflow
            if (s > INT_MAX / 10 || 
                (s == INT_MAX / 10 && r > 7)) {
                return 0;
            }
            
            // INT_MIN is -2,147,483,648 and INT_MAX is 2,147,483,647

            // Check negative overflow
            if (s < INT_MIN / 10 || 
                (s == INT_MIN / 10 && r < -8)) {
                return 0;
            }
            
            s = s * 10 + r;
            x = x / 10;
        }
        
        return s;
    }
};