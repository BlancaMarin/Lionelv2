#ifndef _SERVER_H_
#define _SERVER_H_

#include "types.h"

#define LISTEN_BACKLOG		64

#define MSG_ERROR			"Error creando el socket.\n"

#define MSG_ERR_ARGS        "Numero de argumentos incorrecto.\n"
#define MSG_ERR_SOCKET      "Error durante la creacion del socket.\n"
#define MSG_ERR_BIND        "Error durante el bind del puerto.\n"
#define MSG_ERR_LAUNCH      "Error en la creacion del servidor.\n"
#define MSG_ERR_COM         "Error en la comunicacion. Enlace interrumpido con cliente.\n"
#define MSG_ERR_OPTION		"Mensaje no reconocido.\n"
#define MSG_WAIT_CONN       "[Esperando conexiones]\n"
#define MSG_SERVER_INIT     "[Servidor en funcionamiento]\n"
#define MSG_NEW_CONN        "[Conexion establecida]\n"
#define MSG_NEW_REQ         "[Peticion recibida]\n"
#define MSG_NEW_RESP        "[Peticion procesada]\n"
#define MSG_CLOSE			"[Cerrando servidor]\n"


int launch_server(int port, char *ip, int *socket_fd);
void server_run(int server_socket, McGruder_Lionel mcGruder_Lionel);

#endif
