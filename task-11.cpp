#include <iostream>
#include <string>
#include <vector>

using namespace std;

int randomFunc() {
    int randomVal;
    return randomVal = rand() % 52;
};
int main()
{
    int finalDecision = 1;

    do
    {
        vector<string> cards = { "2","2","2","2","3","3","3","3","4","4","4","4","5","5","5","5","6","6","6","6","7","7","7","7","8","8","8","8","9","9","9","9","10","10","10","10","J","J","J","J","Q","Q","Q","Q","K","K","K","K","A","A","A","A" };
        vector<string> player;
        vector<string> computer;
        string tempVal;
        int cardVal;
        int playerVal = 0;
        int computerVal = 0;
        int indexVal = 0;
        int firstDecision = 1;
        srand(time(0));



        /*ASSIGN CARDS OF PLAYER AND COMPUTER*/
        int i = 0;
        do
        {
            indexVal = randomFunc();
            tempVal = cards[indexVal];
            if (tempVal != "0")
            {
                if (i < 3)
                {
                    computer.push_back(tempVal);
                }
                else {
                    player.push_back(tempVal);
                }
                i++;
            }
        } while (i < 5);

        /*ASSIGN VALUE OF COMPUTER*/
        for (int i = 0; i < computer.size(); i++)
        {
            computerVal += 0;
            if (computer[i] == "J" || computer[i] == "Q" || computer[i] == "K")
            {
                cardVal = 10;
            }
            else if (computer[i] == "A") {
                cardVal = 11;
            }
            else {
                cardVal = stoi(computer[i]);
            }
            computerVal += cardVal;
        }

        /*ASSIGN VALUE OF PLAYER*/
        for (int i = 0; i < player.size(); i++)
        {
            if (player[i] == "J" || player[i] == "Q" || player[i] == "K")
            {
                cardVal = 10;
            }
            else if (player[i] == "A") {
                cardVal = 11;
            }
            else {
                cardVal = stoi(player[i]);
            }
            playerVal += cardVal;
        }
        /*DEFINE 'A' VALUE OF COMPUTER CARD*/
        for (int i = 0; i < computer.size(); i++)
        {
            if (computerVal > 21 && computer[i] == "A") {
                computerVal -= 10;
            }
        }
        /*DEFINE 'A' VALUE OF PLAYER CARD*/
        for (int i = 0; i < player.size(); i++)
        {
            if (playerVal > 21 && player[i] == "A") {
                playerVal -= 10;
            }
        }

        while (playerVal < 21 && firstDecision)
        {
            cout << "\nYour cards are: \n";
            for (int i = 0; i < player.size(); i++)
            {
                cout << player[i];
                if (i != player.size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << "\nYour card value is: ";
            cout << playerVal;
            cout << "\nDo you want to get another card?";
            cout << "\nPress 1 to get, press 0 to get result.";
            cin >> firstDecision;

            /*ASSIGN CARDS OF PLAYER AND COMPUTER*/
            if (firstDecision)
            {
                indexVal = randomFunc();
                tempVal = cards[indexVal];
                if (tempVal != "0")
                {
                    player.push_back(tempVal);
                }
                /*ASSIGN VALUE OF PLAYER*/
                playerVal = 0;
                for (int i = 0; i < player.size(); i++)
                {
                    if (player[i] == "J" || player[i] == "Q" || player[i] == "K")
                    {
                        cardVal = 10;
                    }
                    else if (player[i] == "A") {
                        cardVal = 11;
                    }
                    else {
                        cardVal = stoi(player[i]);
                    }
                    playerVal += cardVal;
                }
                /*DEFINE 'A' VALUE OF PLAYER CARD*/
                for (int i = 0; i < player.size(); i++)
                {
                    if (playerVal > 21 && player[i] == "A") {
                        playerVal -= 10;
                    }
                }
            }
            else {
                cout << "Computer's cards are: \n";
                for (int i = 0; i < computer.size(); i++)
                {
                    cout << computer[i];
                    if (i != computer.size() - 1)
                    {
                        cout << ", ";
                    }
                }
                cout << "\nComputer card value is: ";
                cout << computerVal;

                if (computerVal <= 21)
                {
                    if (playerVal > computerVal)
                    {
                        cout << "\nYou won!";
                    }
                    else if (playerVal == computerVal) {
                        cout << "\nIt is a draw.";
                    }
                    else {
                        cout << "\nYou lost...";
                    }
                }
                else
                {
                    cout << "\nYou won!";

                }
            }
        }
        if (playerVal == 21)
        {
            cout << "\nYour cards are: \n";
            for (int i = 0; i < player.size(); i++)
            {
                cout << player[i];
                if (i != player.size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << "\nYour card value is: 21";
            cout << "\nBlackjack! Let's check the computer.";

            cout << "\nComputer's cards are: \n";
            for (int i = 0; i < computer.size(); i++)
            {
                cout << computer[i];
                if (i != computer.size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << "\nComputer card value is: ";
            cout << computerVal;

            if (computerVal < 21 || computerVal > 21)
            {
                cout << "\nYou won!";
            }
            else {
                cout << "\nIt is a draw.";
            }
        }
        if (playerVal > 21)
        {
            cout << "\nYour cards are: \n";
            for (int i = 0; i < player.size(); i++)
            {
                cout << player[i];
                if (i != player.size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << "\nYour card value is: ";
            cout << playerVal;
            cout << "\nYou lost...";
        }
        cout << "\nTo play again press 1, to exit press 0: ";
        cin >> finalDecision;
    } while (finalDecision);
    return 0;
}