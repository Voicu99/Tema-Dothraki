// Tema Dothraki.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>

bool canFormPalindrome(const std::string& str) {
    std::unordered_map<char, int> freqMap;

    // Calculam frecvența fiecarui caracter din sir
    for (char ch : str) {
        freqMap[ch]++;
    }

    int oddCount = 0; // Numarul de caractere cu frecventa impara

    // Verificam daca putem forma un palindrom
    for (const auto& pair : freqMap) {
        if (pair.second % 2 != 0) {
            oddCount++;
            // Daca avem mai mult de un caracter cu frecventa impara, nu putem forma un palindrom
            if (oddCount > 1) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    std::string str;
    std::cout << "Introduceti sirul de caractere: ";
    std::cin >> str;

    if (canFormPalindrome(str)) {
        std::cout << "DA, sirul poate fi rearanjat intr-un palindrom.\n";
    }
    else {
        std::cout << "NU, sirul nu poate fi rearanjat intr-un palindrom.\n";
    }

    return 0;
}
