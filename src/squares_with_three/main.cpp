#include <iostream>  // Include standard input/output stream library

using namespace std;

// Function to check if an integer contains the digit '3'
bool containsThree(int n)
{
    n = abs(n);  // Convert n to its absolute value (handles negative numbers)
    while (n > 0)  // Loop through all digits of n
    {
        if (n % 10 == 3) return true;  // If the last digit is 3, return true
        n /= 10;  // Remove the last digit
    }
    return false;  // Return false if no '3' is found
}

// Function to count how many square numbers (from 1^2 to value^2) contain the digit '3'
int squaresWithThree(int value)
{
    // Check if input is within the valid range (1 to 10000)
    if (value > 10000 || value < 1)
    {
        return 0;  // Return 0 if value is invalid
    }

    int count = 0;  // Counter for squares that contain the digit '3'

    // Loop through all integers from 1 to 'value'
    for (int i = 1; i <= value; i++)
    {
        long long squared = (long long)i * i;  // Calculate square, use long long to prevent overflow
        if (containsThree(squared))  // Check if the square contains '3'
        {
            count++;  // Increment counter if true
        }
    }

    return count;  // Return total count of squares containing '3'
}

int main() {
    // Test the function for increasing values (1, 10, 100, 1000, 10000)
    for (int i = 1; i <= 10000; i *= 10)
    {
        cout << "For values up to " << i << ", number of squares containing '3': "
             << squaresWithThree(i) << endl;  // Display result
    }

    return 0;  // End of program
}
