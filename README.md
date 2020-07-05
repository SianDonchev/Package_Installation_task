# Package Installation task
A console application which lets the user inputs names
of packages with dependencies between them and gives a possible order for their installation.

The format of the input is: Firstly, the application expects a number corresponding to the number of lines to be entered.
Secondly, each line expects the name of the package in a string format, followed by the name of the packages it depends on.

Example for input:

7

A B C

B C E

C D

D

E F

F C

G

Possible output:
(There can be more than one solution)

G D C F E B A
