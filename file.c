#include "file.h"

char* read_string(int fd, char end) {
    char* buffer = malloc(sizeof(char));
    int i = 0;

    while ((read(fd, &buffer[i], 1)) > 0 && buffer[i++] != end){
        buffer = (char *) realloc(buffer, i + 1);

    }
    return buffer;
}

ConfigLionel FILE_read_ConfigLionel(char *file_name) {
  ConfigLionel ConfigLionel;
  char* aux;


  //init ConfigLionel
  ConfigLionel.ip = "";
  ConfigLionel.port_McGruder = -1;
  ConfigLionel.port_McTavish = -1;
  ConfigLionel.temps_enviament_f3 = -1;


  //obro i llegeixo fitxer de text
  int fd = open(file_name, O_RDONLY);
  if (fd < 0) { //error a l'obrir el fitxer
  	write(2, ERR_MSG_OPEN, sizeof(ERR_MSG_OPEN));

  }else{
    //llegeixo ip
    ConfigLionel.ip = read_string(fd,'\n');
    //llegeixo port_McGruder (faig atoi)
    aux = read_string(fd, '\n');
    ConfigLionel.port_McGruder = atoi(aux);
    //llegeixo port_McTavish (faig atoi)
    aux = read_string(fd, '\n');
    ConfigLionel.port_McTavish = atoi(aux);
    //llegeixo temps_enviament_f3 (faig atoi)
    aux = read_string(fd, '\n');
    ConfigLionel.temps_enviament_f3 = atoi(aux);
    close(fd);
  }

  return ConfigLionel;

}
