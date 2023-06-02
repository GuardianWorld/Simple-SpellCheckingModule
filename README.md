# SpellCheckingModule

Simple Spell Checking module made by Me.
Implemented in pure C++.

## Objective:

To learn how to implement a Spell Checking module by hand and learn C++ usage. Nothing more.

Better implementations exist on the internet, with the end goal of this one being simply for learning purposes.

## Challanges added:

The only tools i had avaliable for use where:
- ChatGPT (For better C++ coding, since i'm still learning).
- Websites explaining the diverses algorithms normally used for spell checking.
- IDEs, coding documentation for C++.

Keeping in mind that: 
- Already existing implementations (Like HunSpell, NuSpell, Aspell, ISpell, etc.) could not have their source code checked.
- All i could do is check the logic behind the algorithms.


## How it was implemented:

This spell checking module was implemented using an approach of Levanshtein for checking word similarities.
The main classes is the Word module, the Dictionary module and the SpellChecking module.

### Word module:

This module works saving some characteristics of the word, such as: The word itself, Meaning of the word, the type of the word, and some training and data weights.

### Dictionary Module:

Implements the words in a HashMap, and saves them, also gives all the necessary operations.

### SpellChecking Module:

Starts by acquiring a dictionary and then making the search operations. The first step when called to do a spell checking operation is to check if the word exists in the Dictionary, if it does, it does not do any more operations, saving a lot of time.
If the word does not exist, it checks a Cache that can store pairs of <WrongTyping, RightWord> to see if said mistake already happened in the past.

If the first step above is successfull, it adds a word usage weight on the word, giving it more priority in case it is mispelled on the future.

Third step is searching trough the Dictionary for all words that are inside a Levanshtein Distance (Set to TWO on this code, but can be easily changed while initializing the SpellChecking module).

After getting all the suggestions, it then sorts the list and grabs only:
* Either the best words only (5 Minimum)
* It grabs all words that have the same weight as the first one on the list.

#### Weights: 

The weights are calculated via: Distance (Penalty) + 10% of the value for that word in the training set + Value of the usage by the user (Number of times used that word is used / number of all words used my the user). 


#### Accuracy: 

I didn't really make many tests, but for the dictionary (Custom Made dictionary), i got results that are quite satisfactory for the usage i wanted. Only supports the basic english dictionary 
and the addon simpler dictionary (Training Weights), with a total of 42677 words inside.

The dictionary has a more complicated part (Dictionary + word type + definition) and a simpler implementation for the training data (Dictionary + Weights).

A total of 36 books were used as training data for obtaining the Training Data of words, those books being a mixture of fantasy books (Harry Potter, Percy Jackson, etc.), study books (Computer Science, Mathematics, etc.) and some custom made texts, with only words that were spoken at least 10 times in all books or existing in the base dictionary being accepted (Otherwise the dictionary would have 500k+ "words").

## Conclusion:
With the end of this project, i think i learned quite a lot. The code is by no means perfect, and in my honest opnion, a refactor to place everything in the correct place and order things better would make wonders for it. But with the goal being reached of making an spell checker that is "Decent" and learn both its logic and the possible ways to implement it, i think i finalized my main objective.

It was a fun journey in my opnion.

Obs: The reason this repository only has 5 commits is that i was implementing this in another private repository... The reason i don't place that one as public is that its a GIANT mess with all the bundles of codes i work on one project... Its not ideal and the make file is huge, but i find that fun to do so yea.

##### This project is free to use as it is, and is not expected to be updated any further in the future. Any errors, questions or suggestions, feel free to fork the project and adopt it. 


