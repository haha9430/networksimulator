CC = g++
CFLAGS = -g -Wall -Werror -std=c++11

node.o: node.cpp
	$(CC) $(CFLAGS) -c node.cpp

object.o: object.cpp
	$(CC) $(CFLAGS) -c object.cpp

host.o: host.cpp
	$(CC) $(CFLAGS) -c host.cpp

simulator.o: simulator.cpp
	$(CC) $(CFLAGS) -c simulator.cpp

link.o: link.cpp
	$(CC) $(CFLAGS) -c link.cpp

link_installer.o: link_installer.cpp
	$(CC) $(CFLAGS) -c link_installer.cpp

router.o: router.cpp
	$(CC) $(CFLAGS) -c router.cpp

manual_router.o: manual_router.cpp
	$(CC) $(CFLAGS) -c manual_router.cpp

auto_router.o: auto_router.cpp
	$(CC) $(CFLAGS) -c auto_router.cpp

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

bulk_send_service.o: bulk_send_service.cpp
	$(CC) $(CFLAGS) -c bulk_send_service.cpp

bulk_send_service_installer.o: bulk_send_service_installer.cpp
	$(CC) $(CFLAGS) -c bulk_send_service_installer.cpp

packet_sink_service.o: packet_sink_service.cpp
	$(CC) $(CFLAGS) -c packet_sink_service.cpp

packet_sink_service_installer.o: packet_sink_service_installer.cpp
	$(CC) $(CFLAGS) -c packet_sink_service_installer.cpp

all: first

first.o: scenarios/first.cpp
	$(CC) $(CFLAGS) -c scenarios/first.cpp

second.o: scenarios/second.cpp
	$(CC) $(CFLAGS) -c scenarios/second.cpp

first: first.o node.o object.o host.o simulator.o link.o link_installer.o router.o manual_router.o auto_router.o service.o service_installer.o message_service.o message_service_installer.o echo_service.o echo_service_installer.o bulk_send_service.o bulk_send_service_installer.o packet_sink_service.o packet_sink_service_installer.o
	$(CC) $(CFLAGS) -o first first.o node.o object.o host.o simulator.o link.o link_installer.o router.o manual_router.o auto_router.o service.o service_installer.o message_service.o message_service_installer.o echo_service.o echo_service_installer.o bulk_send_service.o bulk_send_service_installer.o packet_sink_service.o packet_sink_service_installer.o

second: second.o node.o object.o host.o simulator.o link.o link_installer.o router.o manual_router.o auto_router.o service.o service_installer.o message_service.o message_service_installer.o echo_service.o echo_service_installer.o bulk_send_service.o bulk_send_service_installer.o packet_sink_service.o packet_sink_service_installer.o
	$(CC) $(CFLAGS) -o second second.o node.o object.o host.o simulator.o link.o link_installer.o router.o manual_router.o auto_router.o service.o service_installer.o message_service.o message_service_installer.o echo_service.o echo_service_installer.o bulk_send_service.o bulk_send_service_installer.o packet_sink_service.o packet_sink_service_installer.o

third: third.o node.o object.o host.o simulator.o link.o link_installer.o router.o manual_router.o auto_router.o service.o service_installer.o message_service.o message_service_installer.o echo_service.o echo_service_installer.o bulk_send_service.o bulk_send_service_installer.o packet_sink_service.o packet_sink_service_installer.o
	$(CC) $(CFLAGS) -o third third.o node.o object.o host.o simulator.o link.o link_installer.o router.o manual_router.o auto_router.o service.o service_installer.o message_service.o message_service_installer.o echo_service.o echo_service_installer.o bulk_send_service.o bulk_send_service_installer.o packet_sink_service.o packet_sink_service_installer.o

forth: forth.o node.o object.o host.o simulator.o link.o link_installer.o router.o manual_router.o auto_router.o service.o service_installer.o message_service.o message_service_installer.o echo_service.o echo_service_installer.o bulk_send_service.o bulk_send_service_installer.o packet_sink_service.o packet_sink_service_installer.o
	$(CC) $(CFLAGS) -o forth forth.o node.o object.o host.o simulator.o link.o link_installer.o router.o manual_router.o auto_router.o service.o service_installer.o message_service.o message_service_installer.o echo_service.o echo_service_installer.o bulk_send_service.o bulk_send_service_installer.o packet_sink_service.o packet_sink_service_installer.o

clean:
	rm -f *.o first second third forth