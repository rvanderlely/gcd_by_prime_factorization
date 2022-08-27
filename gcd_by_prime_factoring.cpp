/*
Name: Rachel Vanderlerly
Program 1 GCD By Prime Factorization
Date: August 21,2022
Purpose: This program uses two functions to calculate the gcd of two integers input by the user 
and returns the greatest common divisor between the two. 
*/

#include <iostream>
/*------------------------------------------------------------
                        Get_Prime_Factors
Input:  An integer, x. 
        An empty integer array passed by reference, factors.
        An integer passed by reference, size.
Output: None. Changes made to size and factors are done by reference. 
------------------------------------------------------------*/
void Get_Prime_Factors(int x, int factors[], int &size)
{   
    size = 0;                               //Initialize size to 0
    int prime_factor = 2;                   //Start with 2 as the prime factor
    while (x != 1)
    {
        if (x % prime_factor == 0)          //if it is divisible by the prime factor
        {
            factors[size++] = prime_factor; //Add prime_factor to the array of prime factors and incriment size
            x = x / prime_factor;           //Set x to x divided by the prime factor 
        }
        else
        {
            prime_factor++;                 //If not divisible by prime factor then incriment prime factor
        }
    }
    
}
/*------------------------------------------------------------
                        Get Matches
Input:  An integer array passed by reference and it's length, L1 and length1.
        An integer array passed by reference and it's length, L2 and length2.
Output: Returns the GCD of two non negative numbers.
------------------------------------------------------------*/
int get_gcd(int L1[],int length1, int L2[], int length2)
{
    int comparisions = 0;   //The number of comps made
    int matches =0;         //The number of matches found
    int index1 = 0 ;        //The index used to iterate through list 1
    int index2 = 0;         //The index used to iterate through list 2
    int gcd = 1;            //Initilize gcd with 1 
    int L3[30];             //An array to hold the common prime factors
    int index2_found = 0;   //The index used to keep track of the last element match found 
                            //If a match is found then since both lists are sorted then 
                            //no elements before that index will need to be checked so you 
                            //can cut # of comps down signifigantly by using this as the new index

    //Step through List1 
    for (index1 = 0; index1 < length1;index1++)
    {
        //Step through List2 only checking from the index of the last found match, index2_found
        for (index2 = index2_found; index2 < length2; index2++)
        {
            comparisions++;                 //Incriment for each comparision
            if (L2[index2] == L1[index1])   //If a match is found they share a prime factor
                {
                index2_found = index2 + 1;  //If there is a match then dont check anything before that index from now on
                L3[matches] = L2[index2];   //Save the matching number in L3
                matches++;                  //Incirment matches
                break;                      //Break out of the second for loop because item has been found. 
                }
        }
    }
    for (int i = 0; i < matches ; i++)
    {
        gcd = gcd * L3[i];                  //Calculate the gcd by multiplying common prime factors
    }
    return gcd;                             //Return the gcd. 
}

int main()
{
char run_again = 'Y';
while (run_again == 'Y' ||run_again == 'y')
{
    //Get prime factors of first number
    int MAX_PRIMES = 30;
    int size1 = 0;
    int number1 = 0;
    std::cout<<"Enter number 1:";
    std::cin>>number1;
    int factors1[MAX_PRIMES];
    Get_Prime_Factors(number1,factors1,size1);

    //Get prime factors of second number
    int size2 = 0;
    int factors2[MAX_PRIMES];
    int number2 =0;
    std::cout<<"Enter number 2:";
    std::cin>>number2;
    Get_Prime_Factors(number2,factors2,size2);

    //Find Gcd
    int gcd = get_gcd(factors1,size1,factors2,size2);
    std::cout<<"The GCD of "<<number1 <<" and " << number2 << " is:"<<gcd<< ".\n";
    std::cout<<"Enter Y to run again or enter any other key to quit:";
    std::cin>>run_again;
    std::cout<<"\n";
}

    return 0;
}

