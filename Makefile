CC = g++
CFLAGS = -g -Wall -Werror -std=c++11

node.o: node.cpp
	$(CC) $(CFLAGS) -c node.cpp

host.o: host.cpp
	$(CC) $(CFLAGS) -c host.cpp

link.o: link.cpp
	$(CC) $(CFLAGS) -c link.cpp

link_installer.o: link_installer.cpp
	$(CC) $(CFLAGS) -c link_installer.cpp

router.o: router.cpp
	$(CC) $(CFLAGS) -c router.cpp

manual_router.o: manual_router.cpp
	$(CC) $(CFLAGS) -c manual_router.cpp

service.o: service.cpp
	$(CC) $(CFLAGS) -c service.cpp

service_installer.o: service_installer.cpp
	$(CC) $(CFLAGS) -c service_installer.cpp

message_service.o: message_service.cpp
	$(CC) $(CFLAGS) -c message_service.cpp

message_service_installer.o: message_service_installer.cpp
	$(CC) $(CFLAGS) -c message_service_installer.cpp

echo_service.o: echo_service.cpp
	$(CC) $(CFLAGS) -c echo_service.cpp

echo_service_installer.o: echo_service_installer.cpp
	$(CC) $(CFLAGS) -c echo_service_installer.cpp

all: first

first.o: scenarios/first.cpp
	$(CC) $(CFLAGS) -c scenarios/first.cpp

second.o: scenarios/second.cpp
	$(CC) $(CFLAGS) -c scenarios/second.cpp

first: first.o node.o host.o link.o link_installer.o router.o manual_router.o service.o service_installer.o message_service.o message_service_installer.o echo_service.o echo_service_installer.o
	$(CC) $(CFLAGS) -o first first.o node.o host.o link.o link_installer.o router.o manual_router.o service.o service_installer.o message_service.o message_service_installer.o echo_service.o echo_service_installer.o

second: second.o node.o host.o link.o link_installer.o router.o manual_router.o service.o service_installer.o message_service.o message_service_installer.o echo_service.o echo_service_installer.o
	$(CC) $(CFLAGS) -o second second.o node.o host.o link.o link_installer.o router.o manual_router.o service.o service_installer.o message_service.o message_service_installer.o echo_service.o echo_service_installer.o

clean:
	rm -f *.o first second