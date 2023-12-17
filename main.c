#include "monty.h"
#include <stdio.h>
/* Global state variable */
state_t state = {NULL, NULL, NULL, 0};

/**
 * main - Entry point for Monty interpreter
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Description: Monty interpreter entry point that reads Monty bytecode
 * from a file and executes it line by line.
 * Return: Always 0 on success
 */
int main(int argc, char *argv[]) {
    char *line_buffer; /* Buffer to store each line of the file */
    FILE *file_descriptor; /* File descriptor */
    size_t buffer_size = 0; /* Size of the buffer for getline */
    ssize_t bytes_read = 1; /* Number of bytes read by getline */
    data_t *stack = NULL; /* Stack to perform operations */
    unsigned int line_number = 0; /* Line number tracker */

    /* Verify correct number of arguments */
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open the file provided as argument */
    file_descriptor = fopen(argv[1], "r");
    state.file_descriptor = file_descriptor;
    if (!file_descriptor) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Read lines from the file and execute operations */
    while (bytes_read > 0) {
        line_buffer = NULL; /* Reset line buffer */
        bytes_read = getline(&line_buffer, &buffer_size, file_descriptor);
        state.line_buffer = line_buffer;
        line_number++;

        if (bytes_read > 0) {
            /* Perform operation based on the line content */
            perform_operation(line_buffer, &stack, line_number, file_descriptor); // Change to execute function
        }
        free(line_buffer); /* Free allocated memory for line buffer */
    }

    /* Free all allocated memory and close file */
    free_all_nodes(stack); // Change to free_stack function
    fclose(file_descriptor);

    return (0);
}
