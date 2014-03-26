What is Numeron?
=======

This is CUI number game called "Numeron".

Rule
=======

  There are two Players.
  In this introduction, as an example, there are Player A and Player B.
  Both of them has a secret number which consist with 3 different number, such as "273","903","012".
  For example, Player A selects "273" and Player B selects "903".
  Player A guesses Player B's number and call like "093".
  Player B has to compare with secreat number and answer like " 1 EAT and 2 BITE".
  
  - EAT means how many numbers which macth the value and place.
  - BITE means how many numbers which macth the value, but don't match the place.
  
  For example, in this case, Player A can know that Player B's number must be "039" or "390" or "903".
  Next, Player B also guesses Player A's number and call "254?"
  
  And Player A says " 1 EAT and 0 BITE".
  
  Next, Player A call "903?"
  Player B answer "3 EAT and 0 BITE"
  
  Then, Player A get win!
  The Player who mache the all answer first get win.
  

How to play
=======

    $ git clone http://github.com/routerman/Numeron 
    $ cd Numeron 
    $ make 
    $ ./numeron 
    1:   HUMAN vs HUMAN 
    2:   HUMAN vs COMPUTER 
    3:COMPUTER vs HUMAN 
    4:COMPUTER vs COMPUTER 
    Sir, Please, select GAME MODE >>2 [Enter] 
  
