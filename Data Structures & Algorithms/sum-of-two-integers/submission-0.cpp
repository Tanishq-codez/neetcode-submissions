class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            // Find the carry and cast to unsigned to prevent undefined behavior
            unsigned int carry = (a & b);
            
            // Add without carrying
            a = a ^ b;
            
            // Shift carry to the left to add in the next iteration
            b = carry << 1;
        }
        return a;
    }
};