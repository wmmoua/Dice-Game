/***************************************
Dice Game
Author: Well Moua
Date Created: 10/31/2019
Description: A game of which two dice will be roll for two players and determine who won by rolling the highest.
***************************************/

#include <iostream>
#include <random>
#include <chrono>
using namespace std;

namespace Random
{   
    static std::default_random_engine rng;
    static bool seeded = false;

    // Random class defintion
    class Random
    {
        private:
        std::uniform_int_distribution<int> _dist;

        public:
        Random(int low, int high) : _dist(low, high)
        { 
            seed();     
        }

        static void seed()
        {
            //we only want to seed once
            if (seeded)
            {
                return; 
            } 
            seeded = true;

            // Deriving seed from current system time
            auto generatedSeed = std::chrono::system_clock::now().time_since_epoch().count();
            rng.seed(generatedSeed);
        }

        int get()
        {
            return _dist(rng);
        }
    };
}



// Implement Dice class here
class Dice
{
    private:
    Random::Random rand;
    int x;

    public:
    Dice(int sides) : rand(1, sides)
    {
    }
    
    int roll()
    {
        return rand.get();
    }
};

// Implement Player class here
class Player
{
    private:
    Dice Dice1;
    Dice Dice2;

    public:
    Player() : Dice1(6), Dice2(6)
    {
    }

    int rollDice()
    {
        int dice;
        dice = Dice1.roll() + Dice2.roll();
        return dice;
    }
};


int main()
{
    Player p1;
    Player p2;

    int p1Score = p1.rollDice();
    int p2Score = p2.rollDice();

    // Implement ramaining game logic here
    cout<<"Player 1 rolls: "<<p1Score<<endl;
    cout<<"Player 2 rolls: "<<p2Score<<endl;
    if (p1Score > p2Score)
    {
        cout<<"Player 1 wins!"<<endl;
    }
    if (p1Score < p2Score)
    {
        cout<<"Player 2 wins!"<<endl;
    }
    if (p1Score == p2Score)
    {
        cout<<"It's a Tie!"<<endl;
    }

    return 0;
}