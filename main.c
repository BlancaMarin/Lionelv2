/*
* Solucio P1_Lionel
* @author l.martin
* @author blanca.marin
*/


#include "file.h"
#include "types.h"
#include "server.h"

#define NUM_ARGS      2



//missatges d'error
#define MSG_ERR_NUM_ARGS        "Número d'arguments incorrecte.\n"
#define MSG_ERR_READ            "No s'ha trobat directori files.\n "
#define MSG_WAIT                "Waiting...\n"

//variables globals
int server_socket;
int fd_client;



int main(int argc, char *argv[]) {
  if (argc != NUM_ARGS){
        write(2, MSG_ERR_NUM_ARGS, sizeof(MSG_ERR_NUM_ARGS));
        return EXIT_FAILURE;
  }
  char* file_name = argv[NUM_ARGS-1]; //nom del fitxer "ConfigLionel"

  ConfigLionel configLionel = FILE_read_ConfigLionel(file_name);

  char aux[100];
  sprintf(aux, "Starting %s\n", argv[0]);
  write(1, aux, strlen(aux));
  write(1, MSG_WAIT, sizeof(MSG_WAIT));

  McGruder_Lionel mcGruder_Lionel;
  if(launch_server(configLionel.port_McGruder, configLionel.ip, &server_socket)){
    server_run(server_socket, mcGruder_Lionel);
	}

  return 0;
}
