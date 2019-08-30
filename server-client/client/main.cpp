#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>



/* Define a porta do proxy */
#define PORT 4243

#define LEN 4096

/* Endereço do proxy */
#define SERVER_ADDR "127.0.0.1"


int main(int argc, char *argv[]) {

    /* Proxy socket */
    struct sockaddr_in server;
    /* descritor de arquivo */
    int sockfd;

    int len = sizeof(server);
    int slen;

    /* buffer */
    char buffer_in[LEN];
    /* envio buffer */
    char buffer_out[LEN];


    fprintf(stdout, "Starting Client ...\n");


    /*
     * cria o socket para o cliente
     */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Erro na criação do socket:");
        return EXIT_FAILURE;
    }
    fprintf(stdout, "socket do cliente criado em fd: %d\n", sockfd);


    /* Define as propriedades do socket */
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    memset(server.sin_zero, 0x0, 8);


    /* tenta cnectar ao server */
    if (connect(sockfd, (struct sockaddr*) &server, len) == -1) {
        perror("falha ao conectar com o server");
        return EXIT_FAILURE;
    }


    /* recebe a mensagem de inicialização do servidor server */
    if ((slen = recv(sockfd, buffer_in, LEN, 0)) > 0) {
        buffer_in[slen + 1] = '\0';
        fprintf(stdout, "Server says: %s\n", buffer_in);
    }


    /*
     * cominuca com o servidor até que a mensagem de saída chegue
     */
    while (true) {

      
        memset(buffer_in, 0x0, LEN);
        memset(buffer_out, 0x0, LEN);

        fprintf(stdout, "diga algo ao servidor: ");
        fgets(buffer_out, LEN, stdin);

        /* envia uma mensagem ao servidor via socket */
        send(sockfd, buffer_out, strlen(buffer_out), 0);

        /* recebe uma resposta do servidor */
        slen = recv(sockfd, buffer_in, LEN, 0);
        printf("Server answer: %s\n", buffer_in);

        /* finaliza a conexão */
        if(strcmp(buffer_in, "bye") == 0)
            break;
    }


    /* fecha a conexao com o server */
    close(sockfd);

    fprintf(stdout, "\nConexão fechada\n\n");

    return EXIT_SUCCESS;
}
