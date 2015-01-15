/* 
 * File:   euler8_largest_product.cpp
 * Author: Jon
 *
 * Created on September 26, 2014, 9:59 AM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
//#include <array>
using namespace std;

/*
 * 
 */
int main() {
    const char num1000[] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
    char *end;
    int base = 0;
    //int max = ((sizeof(num1000)/sizeof(*num1000)) - 13);
    int max = 14;
    int tempVal;
    cout << "Dont start new product after max " << max << '\n';
    long largestProduct = 0;
    for (int i = 0; i <= max; ++i) {
        long tempLargestProduct = 1;
        for (int j = 0; j < 13; ++j) {
            tempVal = atoi(num1000[i+j]);
            cout << "i = " << i << " j = " << j << " num1000[" << (i+j) << "] = " << tempVal << '\n';
            if (tempVal == 0) {
                i = i + j + 1;
                cout << "got zero i= " << i << " j = " << j << '\n';
                break;
            } 
            else {
                tempLargestProduct = tempLargestProduct * tempVal;
            }
        }
        if (tempLargestProduct > largestProduct) {
            cout << "Temp product " << tempLargestProduct << " is bigger than stored product " << largestProduct << '\n';
            largestProduct = tempLargestProduct;
        }
    }
    cout << "Largest product of 13 consecutive numbers is " << largestProduct << '\n';
    
    return 0;
}

