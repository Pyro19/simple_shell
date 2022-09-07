#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void dec();
void cisfun(void);
void handler(int _signal);
void _perror(void);
void free_if(char *buff,char **cmd);
void free_elif(char *buff,char **cmd);
unsigned int len_cmd(char *str);
char **_strtok(char *str);
void _execve(char **cmd, char *buff, char **env, char **av, int count);
char *_strcpy(char *s1, char *s2, int n);
char *_strcpyconst(char *s1, const char *s2, int n);
unsigned int _strconstlen(const char *s);
unsigned int _strlen(char *s);
int _strcmp(char *s1, char *s2);
unsigned int dir_num(char *path);
char **c_d_pointer(char *fcmd, char **environ);
char *_env(const char *name, char **environ);
char *append_cmd(char *s1, char *s2, char *cmd, int n, int c);
void print_env(char **environ);
void free_all(char **ptr);
void err_messenger(char **av, char *fcmd, int count);
int _puterror(char c);
void _eof(char *buff);
void _find(char **cmd, char *buff, char **env, char **av, int count);


#endif
