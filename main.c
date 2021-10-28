// C program to calculate the value of pi using probability that GCD(x,y) =1 is 6/pi^2
#include <stdio.h>
#include <stdlib.h>


// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}


// This function will create different sequence of
// random numbers on every program run
int val[2];
void random_nos(void){
    int i ;
    for(i = 0; i<2; i++){
//        printf(" %d\n ", rand());
        val[i] = rand();
//        printf("\nRandom value generated: Iteration number %d  Value %d \n",i, val[i]);
        }

}

// Function to find the square-root of N
float findSQRT(double number)
{
    double start = 0, end = number;
    double mid;
    float ans;

    // To find integral part of square
    // root of number
    while (start <= end) {
        // Find mid
        mid = (start + end) / 2;
        // If number is perfect square
        // then break
        if (mid * mid == number) {
            ans = mid;
            break;
        }
        // Increment start if integral
        // part lies on right side
        // of the mid
        if (mid * mid < number) {
          //first start value should be added to answer
            ans=start;
          //then start should be changed
            start = mid + 1;
        }
        // Decrement end if integral part
        // lies on the left side of the mid
        else {
            end = mid - 1;
        }
    }

    // To find the fractional part
    // of square root upto 5 decimal
    float increment = 0.1;
    for (int i = 0; i < 5; i++) {
        while (ans * ans <= number) {
            ans += increment;
        }
        // Loop terminates,
        // when ans * ans > number
        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;
}

// Main program
int main()
{


    int j, gcd_res ;
    int N = 1000000,gcdeq1=0;
    double gcd1_prob;
    double pisqr;
    // Use current time as seed for random generator
    srand(time(0));

      for(j = 0; j<N; j++){

        random_nos();


        gcd_res =  gcd(val[0], val[1]);
//        printf("\nGCD(%d, %d) = %d", a, b, gcd_res);
        if (gcd_res == 1) {
            gcdeq1++;
        }
      }

    gcd1_prob = (gcdeq1*1.0)/(N*1.0);
    if(gcd1_prob != 0){
      pisqr = (6*1.0)/(gcd1_prob*1.0);
    }
    else
    {
      //to prevent division by 0
      pisqr = 3.14*3.14;
      printf("\n Error: division by 0 is avoided, pi will be assigned to 3.14\n");
    }

    printf("\nIteration count is %d \nNumber of times GCD equal 1 is %d \
           \nProbability of GCD equal 1 is %f  \npi square is %f\n", N, gcdeq1,gcd1_prob,pisqr);

    printf("\nValue of pi is %f \n", findSQRT(pisqr));

    return 0;
    getch();
}
