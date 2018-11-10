# baseball-card-game

This is a program built to help and demonstrate the creation of a card game revolving around baseball that is currently in development. 

Code Details:

The game is broken down into several different classes (including innings, players, results, and a card deck), which all function with each other to simulate random playthroughs of the game.
The playthroughs are broken down into readable results that let us know if we need to change anything (too many games go into extra innings, batters hit too many singles, etc.) 

Game Details:

In the card game, two players play through a baseball game using one deck of playing cards (including Jokers).
Each player receives half of the deck (one player gets all black cards, the other gets all red) and, after shuffling, is able to draw cards and assign 9 cards for their lineup and 1 card for their pitcher, who does not bat. Each player also has a hand of 3 cards from which to play, picking up and discarding cards approprately. Each card is given a value from 1 (Ace) to 13 (King) and Jokers receive a value of 14.

Outs, hits, and walks are decided based on adding the value of the card played from the hand to the card currently active on the field.
For the batter, this is whoever is currently batting. For the pitcher, it is the current pitcher. 

Pitcher    +  Played Card  =  Total Pitcher Skill       If the pitcher's skill is higher, it's an out.

Batter     +  Played Card  =  Total Batter Skill        If the batter's skill is higher, it's a hit!


Queen (12) +  Eight (8)    =  Skill (20)                The batter's skill is higher, it's an out.

Ten (10)   +  Five (5)     =  Skill (15)

Through this main gameplay, the players score runs to win the game through at least 9 innnings. Different cards have different abilities, which helps make the game more challenging and fun.
