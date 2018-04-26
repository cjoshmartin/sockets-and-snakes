# ECE 282 Final Project

## Authors:
* Nathaniel Cantwell ( http://www.github.com/natador)

* Josh Martin (http://www.cjoshmartin.com)



## Server

Server need to be running before clients can do anything.

```bash 
# To run the server:
cd server/ # from the root of project directory
make 
./server
```

## Client 

The game will not start until two clients have connected to the server.

```bash
#To run the client:
cd client/ # from the root of project directory
make
./client localhost # localhost is the hostname, 
                   # and should be changed what the host of your server is.
```

---
**Note:** if you cannot run your server because of problems with the port. the port can be changed in `include/Port.h`

**Note:** Ideal, the clients and server should be running on ths same computer.  
