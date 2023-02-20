#include <cmath>
#include <cctype>
#include <iostream>
#include <vector>
using namespace std;

vector<int> primes; // global vector for ease of use

// function to list prime numbers up to 'n' 
// using Sieve of Eratosthenes (see https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
void findPrimes(int n) {
    if (n <= 2)
        return;
    
    vector<bool> a;
    a.resize(n + 1, true);

    for (int i = 2; i * i <= n ; i++) {
        if (a.at(i) == true) { 
            for (int j = i * i; j <= n; j+= i) {
                a.at(j) = false;
            }            
       }
    }

    for (int i = 2; i < n; i++) {
        if (a.at(i)) 
            primes.push_back(i);
    }
}

int main()
{
    int userChoice;
    char letterChoice;
    int currentPrime = 0;

    cout << "=====Prime Number Generator=====" << endl;
    cout << "What number would you like the program to stop at?: ";
    cin >> userChoice;
    findPrimes(userChoice); // seed algorithm 

    if (userChoice <= 0) {
        cout << "\nInvalid choice. Terminating..." << endl;
        return 0;
    } else {
        cin.ignore(); // to avoid cin from breaking too soon

        while (true) { // main loop
            cout << "\n" << primes.at(currentPrime) << endl;

            currentPrime++;

            cout << "Current prime: " << currentPrime << endl;
            cout << "Number of primes: " << primes.size() << endl;
            cout << "Would you like another number? (Y or N): ";

            cin.get(letterChoice);
            cin.ignore();

            if (currentPrime == primes.size()) {
                cout << "There are no more primes. Terminating . . ." << endl;
                break; 
            }

            if (letterChoice == 'y' || letterChoice == 'Y') {
                continue; 
             } else {
                break;
            }
        }
    }

    return 0;

}

