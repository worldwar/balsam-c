#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <amqp_tcp_socket.h>
#include <amqp.h>
#include <amqp_framing.h>

#include "balsam/message.h"
#include "balsam/util.h"

void start() {
    printf("blablah\n");
    char * hostname = "white-swan.rmq.cloudamqp.com";
    amqp_connection_state_t conn = amqp_new_connection();

    printf("start socket\n");
    amqp_socket_t *socket = amqp_tcp_socket_new(conn);

    printf("open socket\n");
    int status = amqp_socket_open(socket, hostname, 5672);
    printf("start login\n");
    die_on_amqp_error(amqp_login(conn, "nndnyskp", 200, 131072, 0, AMQP_SASL_METHOD_PLAIN, "nndnyskp", "5XbTiDjKSbmQ1fHGg4KUUQhIh-BLz9hL"), "login on");

    printf("start open channel\n");
    amqp_channel_open(conn, 1);
    die_on_amqp_error(amqp_get_rpc_reply(conn), "Consuming");

    printf("start consume\n");
    amqp_basic_consume(conn, 1, amqp_cstring_bytes("add-book"), amqp_empty_bytes, 0, 1, 0, amqp_empty_table);
    die_on_amqp_error(amqp_get_rpc_reply(conn), "Consuming");

    while (1) {
        amqp_envelope_t envelope;
        amqp_maybe_release_buffers(conn);
        printf("start wait\n");
        amqp_consume_message(conn, &envelope, NULL, 0);
        amqp_dump(envelope.message.body.bytes, envelope.message.body.len);
        printf("arrived\n");
        printf("%s\n", envelope.message.body.bytes);
    }
}
