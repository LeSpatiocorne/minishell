#!/bin/bash

if [ ! -f ./minishell ]; then
    make
else
    make re
fi

valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --suppressions=./temp_valgrind.supp ./minishell