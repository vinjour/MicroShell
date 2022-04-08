#include "shell.h"

int main() 
{
	int fd = 1;
	char cmd[50] = {0};
	pid_t pid;
	ssize_t size;
	int status;
	int i = 0;
	char msg[20];
	
	write(fd,"$ ./enseash",12);
	write(fd, "\n Bienvenue dans le Shell ENSEA.", 33);
	write(fd, "\n Pour quitter, tapez 'exit'.\n", 32);
	write(fd,"enseash % ",10);
	
	while(1){
		size = read(fd, cmd, 50); // Ecoute d'une commande
		cmd[size-1] = '\0';  // Initialise la commande
		i++;
		
		if(strcmp(cmd,"exit") == 0){   // Compare la chaine "exit" avec la commande écrite
			write(fd, "Bye bye ... \n", 14);
			break;// Sort au cas où la commande exit a été entrée
		}
		
		else{
			pid = fork(); // Fork
			if (pid == -1){  // Gestion de l'erreur 
				perror("Fork impossible");
				exit(EXIT_FAILURE);
			}
			else if(pid == 0){ // Code du fils
				cmd[size-1] = '\0';  // Réinitialise la commande
				execlp(cmd, cmd, NULL); // Execute les commandes du shell grâce à
										// l'executable situé dans la variable 
										// d'environnement PATH
				
				if(strcmp(cmd,"fortune") == 0){  // Gestion de la commande fortune
				write(fd,"Today is what happened to yesterday.\n", 39);
				return 1;
				}	
			}
			else{    // Code du père
				wait(&status);   							// Attend que le fils ait fini son processus avant de commencer
				sprintf(msg,"enseash [%s:%d] % ", cmd, i); 	// Ecrit la commande précédente et le nombre de
				write(fd,msg,strlen(msg));					// commandes déjà éxécutées
			}
		}
	}
	return 0; 
}
