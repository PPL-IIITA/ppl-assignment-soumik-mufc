# ppl-assignment-soumik-mufc (IIT2015065)

ppl-assignment-soumik-mufc created by GitHub Classroom

ROLL No-IIT2015065 

Section A

## General Overview
* The project now implements question 3 to 7 (submission2 branch).
* The questions 1 and 2 is in main branch.
* All the source files are available.
* The documentation for questions 3 to 7 is in Documentation folder.
* Class Diagram is in Class_Diagram/Class_diagram.pdf file.

## Background
* Project was made in Linux Ubuntu Distro.
* Tools used: Command line tools and sublime text.
* Documentation was made using Doxygen and Latex.
* Class Diagram was made using Visual Paradigm.

## Prerequisite
* GCC version 5.4.0 or above
* C++ Complier must support c++11 or above.

## Documentation
* Download or Clone the project.
* Move to the Documentation folder.
* Open the index.html file in a web browser(preferably chrome).
* The documentation is opened on the web browser.

## Building and running

### Build System: LINUX

To create random girls and boys: (First move to the Project folder i.e ppl-assignment-soumik-mufc-submission-2)
```
 $ cd data_generators
 $ g++ insert_data.cpp -o insert_data -std=c++11
 $ ./insert_data
```

To create random gifts: (First move to the Project folder i.e ppl-assignment-soumik-mufc-submission-2)
```
 $ cd data_generators
 $ g++ insert_gift_util.cpp -o insert_gift -std=c++11
 $ ./insert_gift
```

### Question 3

 To run question 3 : (First move to the Project folder i.e ppl-assignment-soumik-mufc-submission-2)

```
 $ cd q_3/
 $ g++ q3_main.cpp ../Classes/*.cpp -std=c++11 -o q3 
 $ ./q3 12
```
 The argument supplied is k for printing k most happiest and compatible couples.

 The couples will be stored in Couple_log.txt file in the log_files folder.

### Question 4
 
 To run question 4 : (First move to the Project folder i.e ppl-assignment-soumik-mufc-submission-2)

```
 $ cd q_4/
 $ g++ q4_main.cpp ../Classes/*.cpp -std=c++11 -o q4
 $ ./q4 25
```
 The argument supplied is k for breaking up k least happy couples.

 The newly formed couples will be stored in modified_couples_log.txt in the log_files folder.

 ### Question 5
 
 To run question 5 : (First move to the Project folder i.e ppl-assignment-soumik-mufc-submission-2)

```
 $ cd q_5/
 $ g++ q5_main.cpp ../Classes/*.cpp -std=c++11 -o q5
 $ ./q5 1 5
```
 Two arguments supplied are choice and k. 

 Choice is either 1 or 2. Choice = 1 denotes that coupling is to be done according to the question 1 algorithm. Choice = 2 denotes that coupling is to be done according to q5 algorithm. 

 k denotes that k most happy and compatible couples are to be printed on the screen.

 ### Question 6
 
 To run question 6 : (First move to the Project folder i.e ppl-assignment-soumik-mufc-submission-2)

```
 $ cd q_6/
 $ g++ q6_main.cpp ../Classes/*.cpp -std=c++11 -o q6
 $ ./q6 100
```
 The argument supplied is t.  

 t denotes that couple with happiness less than t are to break up and form new couples. 

 The couples formed are stored in Couples_log.txt file in the log_files folder.

### Question 7
 
 To run question 7 : (First move to the Project folder i.e ppl-assignment-soumik-mufc-submission-2)

```
 $ cd q_7/
 $ g++ q7_main.cpp ../Classes/*.cpp -std=c++11 -o q7
 $ ./q7 [3]
```
 The argument supplied is choice which is an optional argument.  

 choice denotes that which algorithm will be used to find the girlfriend for a praticular boy.
 No argument denotes that algo 1 will be followed.

* choice = 1 -> Algo 1
* choice = 2 -> Algo 2
* choice = 3 -> Algo 3

 The couples formed are stored in ouput_q7.txt file in the q_7 folder.

