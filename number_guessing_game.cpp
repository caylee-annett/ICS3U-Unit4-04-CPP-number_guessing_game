// Copyright (c) 2021 Caylee Annett All rights reserved
//
// Created by Caylee Annett
// Created on May 2021
// This program is a game where the user tries to guess a randomly
//    generated number and uses a break statement

#include <iostream>
#include <random>
#include <string>

int main() {
    // This function tells the user if their guess is correct
    std::string guessAsString;
    int guessAsInteger;
    int correctNumber;

    // Input
    std::cout << "Guess what the integer between 0 and 10 is: ";
    std::cin >> guessAsString;
    std::cout << "" << std::endl;

    // Process & Output
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 10);  // [0, 10]
    correctNumber = idist(rgen);

    while (true) {
        try {
            guessAsInteger = std::stoi(guessAsString);

            if (guessAsInteger == correctNumber) {
                std::cout << "You guessed it!" << std::endl;
                break;
            } else if (guessAsInteger > correctNumber) {
                std::cout << "Incorrect! "<< guessAsInteger << " is too high."
                    << std::endl;
                std::cout << "" << std::endl;
            } else {
                std::cout << "Incorrect! "<< guessAsInteger << " is too low."
                    << std::endl;
                std::cout << "" << std::endl;
            }
        } catch (std::invalid_argument) {
                std::cout << guessAsString << " is not a valid input."
                    <<std::endl;
                std::cout << "" << std::endl;
        } std::cout << "Try again: ";
        std::cin >> guessAsString;
    }
    std::cout << "" << std::endl;
    std::cout << "Done." << std::endl;
}
