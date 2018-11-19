#include "server.h"

int fd_client;
//quan haguem decidit lestructura del misstge entre McGruder i Lionel, tbe passarem per parametres el missatge per poderlo analitzar
void server_run(int server_socket, McGruder_Lionel mcGruder_Lionel) {
    struct sockaddr_in c_addr;
    socklen_t c_len = sizeof (c_addr);
    McGruder_Lionel current;

    write(1, MSG_SERVER_INIT, sizeof(MSG_SERVER_INIT));

    while (1) {

        write(1, MSG_WAIT_CONN, sizeof(MSG_WAIT_CONN));//esperando conexiones
        fd_client = accept(server_socket, (void *) &c_addr, &c_len);
        write(1, MSG_NEW_CONN, sizeof(MSG_NEW_CONN));

        //analitzo missatge
    }

	close(fd_client);
}


int launch_server(int port, char *ip, int *socket_fd) {
    struct sockaddr_in s_addr;

    *socket_fd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (*socket_fd < 0)
        write(1, MSG_ERR_SOCKET, sizeof(MSG_ERR_SOCKET));
    else {
        bzero (&s_addr, sizeof (s_addr));
        s_addr.sin_family = AF_INET;
        s_addr.sin_port = htons (port);
        s_addr.sin_addr.s_addr = inet_addr(ip);

        if (bind (*socket_fd, (void *) &s_addr, sizeof (s_addr)) < 0)
            write(1, MSG_ERR_BIND, sizeof(MSG_ERR_BIND));
        else {
         	listen(*socket_fd, LISTEN_BACKLOG);
            return 1;
        }
    }

    return 0;
}
