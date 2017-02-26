# ppl-assignment-soumik-mufc (IIT2015065)
ppl-assignment-soumik-mufc created by GitHub Classroom
ROLL No-IIT2015065 Section A

## General Overview
> The project now implements question 1 and 2.
> All the source files are available.
> The documentation for question1 is in Documentation_question1.pdf and for question2 is in Documentation_question2.pdf
> Class Diagram is in UML_diagram.jpg file.

## Background
> Project was made in Linux Ubuntu Distro.
> Tools used: Command line tools and sublime text.
> Documentation was made using Doxygen and Latex.
> Class Diagram was made using STARUML.

## Prerequisite
> GCC version 5.4.0 or above
> C++ Complier must support c++11 or above.

## Building and running
### Question 1
> To create random girls and boys.
```
g++ insert_data.cpp -o data -std=c++11
./data
```
> To run question 1
```
g++ q1_main.cpp Helper.cpp Miser.cpp Generous.cpp Geeky.cpp Choosy.cpp Normal.cpp Desperate.cpp -std=c++11 
./q1
```
> The couples will be stored in Couple_log.txt file.

### Question 2
> To create random gifts.
```
g++ insert_gift_util.cpp -o data2 -std=c++11
./data2
```
> To run question 2
```
g++ q2_main.cpp Helper_couple.cpp Gift.cpp Couple.cpp -std=c++11 -o q2
./q2
```
> The gifts exchanges will be stored in Gifts_log.txt file.
> user must ender the value of k to print k happiest and k most compatible couples.

PS:
Bugs in making couples(i.e paring of couples) have been removed.

Classes include: Miser, Generous, Geeky, Normal, Choosy, Desperate, Helper, Helper_couple, Gift, Couple.

Class Diagram uploaded finally. :p
