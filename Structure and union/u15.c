#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a command and its associated parameters
struct Command {
    char name[50];    // Command name (e.g., JUMP)
    int param;        // Command parameter (e.g., 20)
};

// Function to parse a string command into the Command structure
void parseCommand(const char *str, struct Command *cmd) {
    // Create a non-constant copy of the input string
    char *strCopy = strdup(str);

    // Tokenize the copied string based on spaces
    char *token = strtok(strCopy, " ");

    // First token is the command name
    if (token != NULL) {
        strcpy(cmd->name, token);
    } else {
        // Handle error if no command name is found
        strcpy(cmd->name, "UNKNOWN");
        cmd->param = 0;
        free(strCopy); // Free the copied string
        return;
    }

    // Second token is the command parameter (if available)
    token = strtok(NULL, " ");
    if (token != NULL) {
        cmd->param = atoi(token); // Convert parameter to an integer
    } else {
        cmd->param = 0; // Default parameter value if not provided
    }

    free(strCopy); // Free the copied string
}

int main() {
    const char *input = "JUMP 20";
    struct Command cmd;

    // Parse the input string into the Command structure
    parseCommand(input, &cmd);

    // Print the parsed command and parameter
    printf("Command: %s, Param: %d\n", cmd.name, cmd.param);

    return 0;
}
