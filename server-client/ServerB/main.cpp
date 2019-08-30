
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


/* porta local do servidor  */
#define PORT 4240



#define BUFFER_LENGTH 4096




int main(void) {

    /* Estrutura Client e Server socket */
    struct sockaddr_in client, server;

    /* Descritor de arquivo do client e server */
    int serverfd, clientfd;

    char buffer[BUFFER_LENGTH];

    fprintf(stdout, "Starting server\n");

    /* cria um socket IPv4  */
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverfd == -1) {
        perror("não foi possível criar o socket:");
        return EXIT_FAILURE;
    }
    fprintf(stdout, "Server socket criado com fd: %d\n", serverfd);


    /* Define as propriedades do socket */
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    memset(server.sin_zero, 0x0, 8);


    /* manipula o erro de porta em uso */
    int yes = 1;
    if(setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR,
                  &yes, sizeof(int)) == -1) {
        perror("A porta selecionada não está disponível:");
        return EXIT_FAILURE;
    }


    /* associa o socket a porta */
    if(bind(serverfd, (struct sockaddr*)&server, sizeof(server)) == -1 ) {
        perror("não foi possível fazer o bind entre o socket e a porta:");
        return EXIT_FAILURE;
    }


    /* inicia o listener para clients */
    if(listen(serverfd, 1) == -1) {
        perror("Listen error:");
        return EXIT_FAILURE;
    }
    fprintf(stdout, "Listening on port %d\n", PORT);

    socklen_t client_len = sizeof(client);
    if ((clientfd=accept(serverfd,
        (struct sockaddr *) &client, &client_len )) == -1) {
        perror("Accept error:");
        return EXIT_FAILURE;
    }

    strcpy(buffer, "Hello, client!\n\0");


    /*envia a mensagem para o cliente */
    if (send(clientfd, buffer, strlen(buffer), 0)) {
        fprintf(stdout, "Cliente conectado.\nAguardando por mensagem do cliente ...\n");

       
        do {

    
            memset(buffer, 0x0, BUFFER_LENGTH);

            /* recebe mensagem do cliente */
            int message_len;
            if((message_len = recv(clientfd, buffer, BUFFER_LENGTH, 0)) > 0) {
                buffer[message_len - 1] = '\0';
                printf("Client diz: %s\n", buffer);
            }


            /* 'bye' finaliza a conexão */
            if(strcmp(buffer, "bye") == 0) {
                send(clientfd, "bye", 3, 0);
            } else {
                send(clientfd, "yep\n", 4, 0);
            }

        } while(strcmp(buffer, "bye"));
    }

    /* Fecha a conexão com o cliente */
    close(clientfd);

    /* fecha o socket local */
    close(serverfd);

    printf("Connection closed\n\n");

    return EXIT_SUCCESS;
}
