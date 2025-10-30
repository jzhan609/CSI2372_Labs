/*
* Player.h - Player Class definition
* Purpose: Represents a player in a card game, managing their hand and gameplay logic
*/

class Player {
public:
    Player(CardsSet& cardPacket, bool isComputer) : packet(cardPacket), computer
    (isComputer) {}
    int play();
private:
    CardsSet inHand;
    CardsSet& packet;
    const bool computer;
    int countPoints();
};


/*
 * Calculates the total points in the player's hand
 * Returns: Total points (int)
 */
int Player::countPoints() {
    int total = 0;
    int numAces = 0;

     //Ace (value 1) counts as 14 if total <= 21, otherwise counts as 1
     //Other cards count as their face value (2-13)
    
    //First pass: count all cards and track aces
    for (int i = 1; i <= inHand.numCards(); i++) {
        Card card = inHand.lookIn(i);
        int val = card.value();
        
        if (val == 1) {
            //Ace found = initially count as 14
            numAces++;
            total += 14;
        } else {
            total += val;
        }
    }
    
    //If over 21 and we have aces => convert aces from 14 to 1
    while (total > 21 && numAces > 0) {
        total -= 13; //Change ace from 14 to 1 (minus 13)
        numAces--;
    }
    
    return total;
}

/*
 * Executes the player's turn, manages the playing logic for both human and computer players
 * Returns: Final score (int)
 */
int Player::play() {
    inHand.empty(); //Clear hand for new game
    bool wantCard = true;
    char answer[3];
    
    while (wantCard) {
        //Draw a card from the packet
        Card card = packet.take();
        inHand.put(card);
        
        //Calculate current score
        int score = countPoints();
        
        if (!computer) {
            //Human player - show card and score
            cout << "You get Card: ";
            card.write();
            cout << endl;
            cout << "Your score is " << score << " points" << endl;
            
            //Check if game over
            if (score >= 21) {
                wantCard = false;
            } else {
                //Ask if wants another card
                cout << "Any additional Card ? ";
                cin >> answer;
                wantCard = (answer[0] == 'y' || answer[0] == 'Y');
            }
        } else {
            //Computer player's automatic strategy
            //Computer stops at 17 or higher, or if over 21
            if (score >= 17 || score > 21) {
                wantCard = false;
            }
        }
    }
    
    return countPoints();
}
