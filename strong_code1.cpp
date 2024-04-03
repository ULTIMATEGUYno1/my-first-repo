#include <iostream>
#include <unordered_set>
using namespace std;

    int numDistinctPrimeFactors(int num) 
    {
        unordered_set<int> factors;

        int divisor = 2;

        while (num > 1) 
        {
            if (num % divisor == 0)
            {
                factors.insert(divisor);
                
                while (num % divisor == 0)
                 {
                    num /= divisor;
                }
            }

            divisor++;
        }
        return factors.size();
    }



int main()
 {
    int consecutiveCount = 0;

    int num = 1;
    
    while (consecutiveCount < 4) 
    {
        if (numDistinctPrimeFactors(num) == 4) 
        {
            consecutiveCount++;
        } 

        else 
        {
            consecutiveCount = 0;
        }

        num++;
    }
    
    cout << "The first of the four consecutive integers with four distinct prime factors is:" << num - 4 << endl;
    
    return 0;
}
