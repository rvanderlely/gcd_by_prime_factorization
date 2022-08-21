/*
Name: Rachel Vanderlerly
Program 1 GCD By Prime Factorization
Date: August 21,2022
Purpose: This program will have two functions which calculate the gcd using 
the prime factorization method
*/

#include <iostream>

void Get_Prime_Factors(int x, int factors[], int &size)
{   
    size = 0;
    int prime_factor = 2;
    while (x != 1)
    {
        if (x % prime_factor == 0)
        {
            factors[size++] = prime_factor;
            x = x / prime_factor;
        }
        else
        {
            prime_factor++;
        }
    }
    
}

/*------------------------------------------------------------
                        Get Matches
Input: 2 two sorted arrays and their lengths.
Output: The GCD of two non negative numbers.
------------------------------------------------------------*/
void get_gcd(int L1[],int length1, int L2[], int length2)
{
    int comparisions = 0;   //The number of comps made
    int matches =0;         //The number of matches found
    int index1 = 0 ;        //The index used to iterate through list 1
    int index2 = 0;         //The index used to iterate through list 2
    int gcd = 1;
    int index2_found = 0;   //The index used to keep track of the last element match found 
                            //If a match is found then since both lists are sorted then 
                            //no elements before that index will need to be checked so you 
                            //can cut # of comps down signifigantly by using this as the new index
    int L3[length1]; //Make this better later by doing lowest length of the two
    //static int L3[length1]; //Make this better later by doing lowest length of the two


    //Walks through List1 
    for (index1 = 0; index1 < length1;index1++)
    {

        //Walks through List2 
        for (index2 = index2_found; index2 < length2; index2++)
        {
            comparisions++;                 //Incriment for each comparision
            
            if (L2[index2] == L1[index1])   //If a match is found
                {
                index2_found = index2 + 1;  //if there is a match then dont check anything before that index
                L3[matches] = L2[index2];   //Save the matching number in List3
                matches++;                  //Incirment matches
                break;                      //Break out of the second for loop because item has been found. 
                }
        }
    }

    //Print the results 
    std::cout<<"Array1 :";
    for (int i = 0;i<length1; i++){std::cout<<L1[i]<<"\t";}
    std::cout<<"\nArray2 :";
    for (int i = 0;i<length2; i++){std::cout<<L2[i]<<"\t";}
    std::cout << "\nMatching elements:";
    for (int l = 0;l<matches; l++){std::cout<<L3[l]<<"\t";}
    std::cout<<"\nTotal Comparisions:"<< comparisions<<"\n";

    for (int i = 0; i < matches ; i++)
    {
        gcd = gcd * L3[i];
    }
    std::cout<<"The gcd is :"<<gcd<< ".\n";
}

int main()
{

    //Get prime factors of first number
    int MAX_PRIMES = 30;
    int size1 = 0;
    int factors1[MAX_PRIMES];
    Get_Prime_Factors(24,factors1,size1);
    std::cout<<"\nFirst number has "<<size1<<" prime factors";
    std::cout<<"The prime factors are :";
    for (int i = 0; i< size1;i++)
    {
        std::cout<<factors1[i]<<" ";
    } 

    //Get prime factors of second number
    int size2 = 0;
    int factors2[MAX_PRIMES];
    Get_Prime_Factors(119,factors2,size2);
    std::cout<<"\nSecond number has "<< size2 <<" prime factors";
    std::cout<<"The prime factors are :";
    for (int i = 0; i< size2;i++)
    {
        std::cout<<factors2[i]<<" ";
    } 
    std::cout<<"\n";


    //HERE IS THE ERROR BELOW. It is overwriting my factor1 array 
    std::cout<<"\nFirst number has "<<size1<<" prime factors";
    std::cout<<"The prime factors are :";
    for (int i = 0; i< size1;i++)
    {
        std::cout<<factors1[i]<<" ";
    } 


    //Find the common elements
    get_gcd(factors1,size1,factors2,size2);
    return 0;
}

