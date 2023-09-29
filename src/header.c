#include "render.h"

#include <stdio.h>
#include <time.h>
#include <unistd.h>

void printHeader(void) {
  clearscr();
  fflush(stdout);
  usleep(1000000);
  printf("\n\n");

  printDelay("\t ██████╗ █████╗ ████████╗████████╗██╗     ███████╗███████╗██╗  ██╗██╗██████╗  \n", 50);
  printDelay("\t██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██║     ██╔════╝██╔════╝██║  ██║██║██╔══██╗ \n", 50);
  printDelay("\t██████╔╝███████║   ██║      ██║   ██║     █████╗  ███████╗███████║██║██████╔╝ \n", 50);
  printDelay("\t██╔══██╗██╔══██║   ██║      ██║   ██║     ██╔══╝  ╚════██║██╔══██║██║██╔═══╝  \n", 50);
  printDelay("\t██████╔╝██║  ██║   ██║      ██║   ███████╗███████╗███████║██║  ██║██║██║      \n", 50);
  printDelay("\t╚═════╝ ╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝╚═╝      \n", 50);

  printf("\n\n");
  printTypeWriter("\tBem vindo ao jogo!!!\n");
  usleep(500000);                                               
}

void printWin(void) {
  clearscr();

  printf("\x1b[33m");
  printTypeWriter("\t\tParabéns!!!\n\n\n");

  printDelay("\t▄██   ▄    ▄██████▄  ███    █▄        ▄█     █▄   ▄██████▄  ███▄▄▄▄   \n", 50);
  printDelay("\t███   ██▄ ███    ███ ███    ███      ███     ███ ███    ███ ███▀▀▀██▄ \n", 50);
  printDelay("\t███▄▄▄███ ███    ███ ███    ███      ███     ███ ███    ███ ███   ███ \n", 50);
  printDelay("\t▀▀▀▀▀▀███ ███    ███ ███    ███      ███     ███ ███    ███ ███   ███ \n", 50);
  printDelay("\t▄██   ███ ███    ███ ███    ███      ███     ███ ███    ███ ███   ███ \n", 50);
  printDelay("\t███   ███ ███    ███ ███    ███      ███     ███ ███    ███ ███   ███ \n", 50);
  printDelay("\t███   ███ ███    ███ ███    ███      ███ ▄█▄ ███ ███    ███ ███   ███ \n", 50);
  printDelay("\t ▀█████▀   ▀██████▀  ████████▀        ▀███▀███▀   ▀██████▀   ▀█   █▀  \x1b[m\n", 50);
                                                                      
}

void printLost(void) {
  clearscr();

  printf("\x1b[31m");
  printTypeWriter("\t\tQue pena :,(\n\n\n");

  printDelay("\t▓██   ██▓ ▒█████   █    ██     ██▓     ▒█████    ██████ ▄▄▄█████▓\n", 50);
  printDelay("\t ▒██  ██▒▒██▒  ██▒ ██  ▓██▒   ▓██▒    ▒██▒  ██▒▒██    ▒ ▓  ██▒ ▓▒\n", 50);
  printDelay("\t  ▒██ ██░▒██░  ██▒▓██  ▒██░   ▒██░    ▒██░  ██▒░ ▓██▄   ▒ ▓██░ ▒░\n", 50);
  printDelay("\t  ░ ▐██▓░▒██   ██░▓▓█  ░██░   ▒██░    ▒██   ██░  ▒   ██▒░ ▓██▓ ░ \n", 50);
  printDelay("\t  ░ ██▒▓░░ ████▓▒░▒▒█████▓    ░██████▒░ ████▓▒░▒██████▒▒  ▒██▒ ░ \n", 50);
  printDelay("\t   ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒    ░ ▒░▓  ░░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░  ▒ ░░   \n", 50);
  printDelay("\t ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░    ░ ░ ▒  ░  ░ ▒ ▒░ ░ ░▒  ░ ░    ░    \n", 50);
  printDelay("\t ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░      ░ ░   ░ ░ ░ ▒  ░  ░  ░    ░      \n", 50);
  printDelay("\t ░ ░         ░ ░     ░            ░  ░    ░ ░        ░           \n", 50);
  printDelay("\t ░ ░ \x1b[m\n\n", 50);                                                            
}
