# ZetaNet
A C++ Neural Network made from scratch to solve simple machine learning problems. This version is optimized to work with encrypting and decrypting simple string messages.


### Description
I started this project towards the end of CS1 as both a challenge to myself to utilize the various programming techniques I had been learning, and to dip my toes into a more advanced area of Computer Science. This project features my own Matrix ADT with an accompanying MatrixTools class to manipulate these matrices even further. I use these classes to run the backend of my neural network. The goal of this neural network started as a general purpose network, and at it's early stages I used to to solve multi-input XOR and NOR operations, but as the project progressed I decided to make it work specifically with the goal of solving encryption in mind.

This program solves a type of encryption I made up (I think) which just rotates one of the binary digits of a letter to turn it into another letter or character. The neural network then recognizes this pattern and is able to apply this to a test dataset string that you choose.

I ran into many problems while undergoing this project, including inefficiency and a bad use of choice of variables for input and output for the neural network, but eventually fixed the variable problem. This network is still very inefficient, mostly because each matrix operation is O(n^2). I might revisit this project in the future to resolve this issue, but for now I am considering this complete.

This is an example of what the neural network does on a very small test sentence:

### Example

(Left = Encryption using the NN, Right = Decryption using the NN)
<p align="center">
  <img src="https://i.imgur.com/ICzdtv3.png" width="350">
  <img src="https://i.imgur.com/e60KhlX.png" width="350">
</p>

### Subprojects

#### TSVReader Class

This is a class I made to be able to read from .tsv files that I exported from google sheets. I realized pretty early on in this project that being able to read data files was going to be an absolute essential. This was my solution. The first line of the file is just ignored as header data, but in the future could be saved with the data. I could also make it read a specific part of the file instead of everything in the file, but decided not to overbuild the class for my uses in this project.

#### Matrix Class

This class is the heart of the project. This class took the most time for me to code as I built it during my CS1 and CS2 classes. As a beginner at the time most of it is very poorly optimized. If I were to do this project again this is the part I would use a library for, as I'm sure they'd know how to optimize it better than I ever could.

#### MatrixTools Class

This is a helper class that works closely with the Matrix class to manipulate 2 matrices together without being associated with one matrix in particular. I also threw random methods in there that had no good place anywhere else.


