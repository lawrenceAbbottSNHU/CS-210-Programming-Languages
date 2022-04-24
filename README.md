# CS-210-Programming-Languages

# Summarize the project and what problem it was solving.
This project involves the creation of an easy-to-use application that the Corner Grocer's employees can use to analyze the most frequently purchased items, each business day. The application provides insight to the employees of Corner Grocer and helps them to more effectively take on the task of rearranging the produce section. Users are presented with a menu with three options. Option 1 outputs to the screen a list of all items purchased and the frequency by which each item was purchased. Option 2 outputs to the screen the frequency of a specific produce item, after the user has provided the name of the produce item to be reported on. Option 3 outputs to the screen a histogram representation of the output from Option 1, whereby the frequency of each item in the list is represented as a '*'

# What did you do particularly well?
I utilized both C++ and Python programming languages in the solution, while maintaining a seamless user experience.

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I believe the code can be enhanced by checking whether the data dictionary file has already been created. The way the application is currently written the data dictionary file is overwritten each time one of the menu options is selected. One way to improve the speed of each subsequent request would be to check the last date on which the file was last written to. Assuming that the application is the only entity that modifies the file, in theory, the data in the file would remain relevant until the following business day, when the next day's produce data is available for processing. In other words, if the data dictionary file was last modified today, just retrieve the data from the file. If not, first write to the file and then retrieve the data. 

# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
I encountered some challenges while writing the code. I was particularly challenged when I called upon the Python scripts to write multiple lines of output by calling the print() method for each line. Exceptions were thrown when print() was called multiple times, so I instead created a string variable called "buffer", which served as a buffer by which all the lines could be concatenated together into a single string. Then, I called print() only once and passed in the buffer string. This produced the desired result, but there may be a more efficient way to implement this. 

# What skills from this project will be particularly transferable to other projects or course work?
The creation of this software application taught me how easy it is to integrate one or more programming languages into an application. In this case, I was successful in calling Python methods from C++. Once the interface has been established that allows you user to call methods in another programming language, you can utilize the strengths of that programming language. In this case, Python, being an exceptional language for processing data, was called upon in the implementation of some of the features available through the menu options for the end user. 

# How did you make this program maintainable, readable, and adaptable?
The code is written in such a way that is can be easily maintained, modified, or adapted. I have been sure to include many comments in the code to explain what is happening and have used self-documenting method names and variables so that the code is easier read by a future developer. Adding new features would be quite easy to implement because the code is written in such a way to promote reuse of the existing methods. Also, the code is written in an object-oriented style, so objects can be extended easily to further improve the application.

