Baseball Card Game
==================

This is a program built to help and demonstrate the creation of a card game revolving around baseball that is currently in development.


Game Details
------------

In the card game, two players play through a baseball game using one deck of playing cards (including Jokers).
Each player receives half of the deck (one player gets all black cards, the other gets all red) and, after shuffling, is able to draw cards and assign 9 cards for their lineup and 1 card for their pitcher, who does not bat. Each player also has a hand of 3 cards from which to play, picking up and discarding cards appropriately. Each card is given a value from 1 (Ace) to 13 (King) and Jokers receive a value of 14.

Outs, hits, and walks are decided based on adding the value of the card played from the hand to the card currently active on the field.
For the batter, this is whoever is currently batting. For the pitcher, it is the current pitcher.

|		     | Card (value) |   | Played card (value) |   | Skill (value)      |
|:----------:|:------------:|:-:|:-------------------:|:-:|:------------------:|
|**Pitcher** | Queen (12)   | + | Eight (8)           | = | Pitcher Skill (20) |
| **Batter** | King (13)    | + | Five (5)            | = | Batter Skill (18)  |

**The Pitcher's Skill is higher. It's an out!**

Through this main gameplay, the players score runs to win the game through at least 9 innnings. Different cards have different abilities, which helps make the game more challenging and fun.


Code Details
------------

The game is broken down into several different classes (including innings, players, results, and a card deck), which all function with each other to simulate random playthroughs of the game.

**Example**

The `Player` class

```C++
class Player
{
public:
    void setStartingDeck(std::vector<CardDeck::Card> halfDeck);
    void removeJokerAndAces();
    void shuffleStartDeck();
    void pickUpCard();
    void setStartingAreas();
    void setIsBatting(bool tf);
    bool getIsBatting();
    
    void refreshPickup();
    void moveToNextBatter();
    int getLastBatterIndex();
    void refreshHand();
    void playCard();
    void decreasePitcherValue();
    void replacePitcher(int newPitcherHandIndex);
    CardDeck::Card getPlayFieldCard();
    CardDeck::Card getPitcher();
    CardDeck::Card getCurrentBatter();
    void cleanUp(); // erase card from playField, put to discard. Pick up new card.
    
private:
    std::vector<CardDeck::Card> hand;
    std::vector<CardDeck::Card> field;
    std::vector<CardDeck::Card> pickup;
    std::vector<CardDeck::Card> discard;
    std::vector<CardDeck::Card> pitcher;
    std::vector<CardDeck::Card> playField;
    std::vector<CardDeck::Card> startingDeck;
    std::vector<CardDeck::Card> removedFromPlay;
    int lastBatterIndex;
    bool isBatting;
    int pitcherStartValue;
    
};
```
___

Each class' _methods_ perform tasks similar to the tasks performed by those objects in the physical card game

**Example**

The `setStartingAreas()` method in the class `Player`, which sets up the game.

```C++
void Player::setStartingAreas()
{
    
    // Draws 12 cards from the top of the deck
    for (int deckIndex = 0; deckIndex < 12; deckIndex++)
        field.push_back(startingDeck.at(deckIndex));
    for (int deckIndex = 0; deckIndex < 12; deckIndex++)
        startingDeck.erase(startingDeck.begin());
    
    //Puts the rest of the cards from the deck into the pickup pile
    for (int deckIndex_2 = 0; deckIndex_2 < startingDeck.size(); deckIndex_2++)
        pickup.push_back(startingDeck.at(deckIndex_2));
    for (int deckIndex_2 = 0; deckIndex_2 < startingDeck.size(); deckIndex_2++)
        startingDeck.erase(startingDeck.begin());
    
    // Puts the Aces and Joker into the pickup pile
    for (int remFromPlayIndex = 0; remFromPlayIndex < removedFromPlay.size(); remFromPlayIndex++)
        pickup.push_back(removedFromPlay.at(remFromPlayIndex));
    for (int remFromPlayIndex = 0; remFromPlayIndex < removedFromPlay.size(); remFromPlayIndex++)
        removedFromPlay.erase(removedFromPlay.begin());
    
    
    // Assigns the pitcher from the 12 cards drawn                                      PITCHER ASSIGNED
    int max = 0;
    int maxIndex = 0;
    
    for (int fieldIndex = 0; fieldIndex < field.size(); fieldIndex++)
    {
        if (field[fieldIndex].value > max)
        {
            max = field[fieldIndex].value;
            maxIndex = fieldIndex;
        }
    }
    
    pitcher.push_back(field.at(maxIndex));
    field.erase(field.begin() + maxIndex);
    
    pitcherStartValue = pitcher.at(0).value;

    
    // Takes out the lowest card from the field, leaving 10
    int min = 14;
    int minIndex = 0;
    
    for (int fieldIndex_2 = 0; fieldIndex_2 < field.size(); fieldIndex_2++)
    {
        if (field[fieldIndex_2].value < min)
        {
            min = field[fieldIndex_2].value;
            minIndex = fieldIndex_2;
        }
    }
    
    pickup.push_back(field.at(minIndex));
    field.erase(field.begin() + minIndex);
    
    
    // Takes out the next lowest card from the field, leaving 9                         FIELD ASSIGNED
    int min_2 = 14;
    int minIndex_2 = 0;
    
    for (int fieldIndex_3 = 0; fieldIndex_3 < field.size(); fieldIndex_3++)
    {
        if (field[fieldIndex_3].value < min_2)
        {
            min = field[fieldIndex_3].value;
            minIndex_2 = fieldIndex_3;
        }
    }
    
    pickup.push_back(field.at(minIndex_2));
    field.erase(field.begin() + minIndex_2);
    
    
    // Shuffles the pickup pile
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(pickup.begin(), pickup.end(), default_random_engine(seed));
    
    
    // Picks up 3 cards and puts them in the player's hand                              HAND ASSIGNED
    for ( int numberOfCards = 1; numberOfCards <= 3; numberOfCards++)
    {
        pickUpCard();
    }
    
    
    // Makes the first card in the field the first batter
    lastBatterIndex = 0;
}
```
In the example, we have that the `Player` organizes the cards into separate sections (pitcher, lineup, pickup pile, etc.) as well as shuffles the cards, which parrallels the actions of a player in the physical card game. 

___

The playthroughs are broken down into readable results that let us know if we need to change anything (too many games go into extra innings, batters hit too many singles, etc.) 

**Example Program Output**

```
NUMBER OF GAMES: 5000

-----Totals--And--Per--Game-----
Hits: 		__20186		Hits per game: 			4.0372
Runs: 		___7536		Runs per game: 			1.5072
Singles: 	__15072		Singles per game: 		3.0144
Doubles: 	___3382		Doubles per game: 		0.6764
Triples: 	____112		Triples per game: 		0.0224
Home Runs: 	___1620		Home runs per game: 		0.324
Walks: 		___8579		Walks per game: 		1.7158
				Batters Per Game: 		60.9162
				Batters Per Inning: 		3.38423

-----Percentages--Overall-----
Singles: 	74.6656%
Doubles: 	16.7542%
Triples: 	0.55484%
Home Runs: 	8.02536%
-----
> 5 Runs: 	4.46%
4 Runs: 	18.5%
3 Runs: 	1.32%
2 Runs: 	1.88%
1 Run: 		5.76%
Ties: 		68%
------------------------------

Program ended with exit code: 0
```
With these results we can see that too many games (68% of all games) are going in to extra innings (tied after 9 innings), and so can then try and make the changes needed to get a more reasonable percentage.
