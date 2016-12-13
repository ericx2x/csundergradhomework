Eric Lima
ericjlima@gmail.com

I will report what I observed here. The sort parses the datafile and goes through it with all the name & phone numbers. Of course, it is first by phone number area code and then by last name within each area code. For the grep command the data gets streamed in by a file. Then the number of lines is noted. Since both buffers get filled to capacity and cannot move the second datafile gets deadlocked. 

I believe I completed this program 100%. Luckily, I didn't run into errors and the program seems to be working successfully. 

Let me know if you need anything else.
