#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define TRUE 1

void type_prompt() {
  printf("> ");
}

void read_command(char* command, char** parameters) {
  char full_command[100];
  fgets(full_command, sizeof(full_command), stdin);
  
  char* token = strtok(full_command, " ");
  strcpy(command, "/bin/");
  strcat(command, token);
  
  int p_index = 0;
  parameters[p_index++] = command;
  while (token != NULL) {
	token = strtok(NULL, " ");
	if (token != NULL) {
	  parameters[p_index++] = token;
	}
  }

  parameters[p_index-1][strlen(parameters[p_index-1])-1] = '\0';
  parameters[p_index] = NULL;
}

int main() {
  while (TRUE) {
	type_prompt();

	char command[50];
	char* parameters[10];
	read_command(command, parameters);

	if (fork() != 0) { // Fork off child process
	  // Parent code
	  int status;
	  waitpid(-1, &status, 0); // Wait for child process
	} else {
	  // Child code
	  execve(command, parameters, 0); // Execute command
	}
  }
  return 0;
}
