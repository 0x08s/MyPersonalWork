#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    // Define suits and faces
    const char *suit[4]  = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *face[13] = {"Ace","2","3","4","5","6","7","8","9","10",
                            "Jack","Queen","King"};
    
    int deck[4][13] = {0};  // 0 = undealt, 1 = dealt
    
    srand(time(0));  // random seed
    
    int card = 0;
    
    // Shuffle - assign random positions

    cout<<"Shuffling Deck \n";

    while(card < 52){

    int row = rand() % 4;// random suit
           
    int col = rand() % 13;  // random face
        
    if(deck[row][col] == 0){

    deck[row][col] = ++card;  // assign card number

        }
    }

    cout<<"Deck Shuffled Successfully!\n";
    
    // Deal first 5 cards

cout<<"Dealing 5 Cards\n";

for(int d=1; d<=5; d++){

for(int i=0; i<4; i++){

for(int j=0; j<13; j++){

if(deck[i][j] == d){

cout<<"Card "<<d<<face[j]<<suit[i]<<"\n";
}
}
}
}   
    // Display full deck order

    cout<<"\nFull Deck Order\n";

for(int d=1; d<=52; d++){

for(int i=0; i<4; i++){

for(int j=0; j<13; j++){

if(deck[i][j] == d){

cout<<"Card "<<d<<face[j]<<suit[i]<<"\n";
}
}
}   
    return 0;
}
}