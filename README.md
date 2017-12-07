# Chat-Server-and-Client

**INSTRUCTIONS ON FIRST RUN**

**Download the compiled programs and create a blank folder each in the server and client folder, move the downloaded programs to the newly created folder, i mean the server program into the the empty folder in server folder and do the same for the client program.**

**There is also a executable named "RunMeOnlyOnce.exe"(32 bit or 64 bit). Download the 32 bit or 64 bit version which ever suits you.
But remember that this executable must be present in subfolder under server and client folder, where the client and server programs are stored.**

**INTRODUCTION**

Instant messengers have become a daily part of our life. We cannot imagine a life without Whatsapp, Telegram, Hike, etc. I was always curious about their working, so I spent some time and learnt about their theory of implementation. Equipped with the right knowledge I have created a very basic implementation of instant messengers.
Though this is very basic, probably it might seem like app of MS-DOS era. But the functionality present in it is very similar to the current IM app, it can connect to a client through a server and send messages to other client. 
 
**USER’S GUIDE**

Let me first of all explain the contents of the project folder.

**Folder Client**:
        
         Header Files
         Logs
         Program Code
         Release
        
**Folder Server**:
        
         Header Files
         Logs
         Program Code
         Release
        
In the folder header files, all the custom made header files(.hpp) are used. In the logs folder all the program run logs are stored, so one can see the logs to find the error behind the crash of the program. In the program code folder, the final .cpp files are stored.
the compiled programs are stored in folder release, both **32 bit** and **64 bit** versions are stored in it.

**Before using the program, I would like to elaborate the conditions under which it can run.**
1.	Running servers and client, all on the same machine.
2.	Running server and clients on different machines on same LAN network.
3.  The machine should be windows preferably above windows 7.

**Please note that this cannot work on PCs connected through the internet, but only on a LAN network.**
For case 1: we use the local ip that is **127.0.0.1**
For case 2: we use the local ip of the machine on the LAN netwotk, eg:- **192.168.0.89**, etc.

I am running the program on my local machine, so I will set my server’s ip address to 127.0.0.1, and connect the client to server at ip **127.0.0.1** . server port used in **444**, any available port can be used.
Remember one thing, when one runs the program for the first time on their PC, run the program “RunMeOnlyOnce”. Don’t run it again, it is to be run only once during first use. Please use the **32 bit or 64 bit** version, whatever your PC supports.

**Server application**:
Now there are 4 options. **Type 1 to start server, 2 to show information about the creator of the program that is me. 3 for help and 4 to quit the program.** 
On selecting option 1, i.e. starting the server, there is a prompt to enter the server’s ip address and port, through which it can be accessed by the clients. In this case I am running it on 127.0.0.1 , as I have server and client n  the same machine.
On pressing enter the server boots up, one can see the progress. Press any key to continue.
Now the server is running, one can see the clients connected, their **ID’s** and the clients that have disconnected.
One can see that a message is displayed when a client is connected, when the client will send the server its **ID** and the **ID** of the other client to chat with.
The clients id and the id of client with which it wants to chat is shown. When a client disconnects a message is shown.
To shutdown the server, type **quit** directly in the terminal, and press enter.

**Client Application**:
For this to work, first of all the server must be running, start the server, following the instructions above.
Enter the ip address of the chat server and the port on which it is accessible, and then press enter. After that you will get the prompt to enter your ID and the ID with whom you want to chat.
Please note that the ID selected must be a number between 10-99, selecting any other number will result in undefined behaviour, and also make sure that the same ID is not used by any other client. I used 12 as my ID and I want to chat with client having ID 45.
Use any number between 10-99 and the enter it and press enter.
Now the client is setup and you can simply chat with another client, your messages are shown on left side and the other clients messages are shown on right side. If you want to stop the chat and exit type **EXIT**.
For more detailed instructions and screenshots see the user's guide.
