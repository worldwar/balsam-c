Balsam is an service for crawl books from websites when received message from rabbitmq.

## installation

### install rabbitmq c client

this service requires rabbitmq c client installed on computer:

* download rabbitmq source code from [github](https://github.com/alanxz/rabbitmq-c)

* go to root directory of rabbitmq c client source code and run command `mkdir build & cd build`
* run command `cmake ..`, this command will generate Makefile, then run command `make & make install`

Now, rabbitmq c client has been already installed on your computer. You can install balsam now.


### install balsam

Because balsam also uses `cmake` as build tool, the steps of installing balsam are very like what in installing rabbitmq c client. 

* download or git clone balsam latest code
* go to root directory of balsam source code and execute command `mkdir build & cd build`
* run command `cmake ..`, this command will generate Makefile, then run command `make`

Now, run `./balsam` and you can see balsam running now.
