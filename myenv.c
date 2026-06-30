/*
 *  myenv.c : env コマンドのクローン
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "myputenv.h"

extern char **environ;

int main(int argc, char *argv[]){
    int i;

    for (i = 1; i < argc && strchr(argv[i], '='); i++)
        if (putenv(argv[i]) < 0)
            perror(argv[i]);

    if (i == argc)
        while (*environ)
            puts(*environ++);

    else {
        execvp(argv[i], &argv[i]);
        perror(argv[i]);
    }

    return EXIT_SUCCESS;
}

/* 実行例

$ ./myenv
sakochihiro@chr1007 kadai09-i23sako % ./myenv             
TMPDIR=/var/folders/ln/bc703cz95njc60gq4j6v4ry00000gn/T/
__CFBundleIdentifier=com.apple.Terminal
XPC_FLAGS=0x0
TERM=xterm-256color
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.erE6MYsql9/Listeners
XPC_SERVICE_NAME=0
TERM_PROGRAM=Apple_Terminal
TERM_PROGRAM_VERSION=454.1
TERM_SESSION_ID=963E8D9A-788C-4184-A9BC-B5BE8ED0A7EF
SHELL=/bin/zsh
HOME=/Users/sakochihiro
LOGNAME=sakochihiro
USER=sakochihiro
PATH=/opt/homebrew/opt/openjdk/bin:/opt/homebrew/opt/openjdk/bin:/opt/homebrew/bin:/opt/homebrew/sbin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin
SHLVL=1
PWD=/Users/sakochihiro/kadai09-i23sako
OLDPWD=/Users/sakochihiro
HOMEBREW_PREFIX=/opt/homebrew
HOMEBREW_CELLAR=/opt/homebrew/Cellar
HOMEBREW_REPOSITORY=/opt/homebrew
INFOPATH=/opt/homebrew/share/info:
CPPFLAGS=-I/opt/homebrew/opt/openjdk/include
LANG=ja_JP.UTF-8
_=/Users/sakochihiro/kadai09-i23sako/./myenv

sakochihiro@chr1007 kadai09-i23sako % ./myenv TEST=123 printenv TEST
123
sakochihiro@chr1007 kadai09-i23sako % ./myenv A=1 B=2 env
A=1
B=2
sakochihiro@chr1007 kadai09-i23sako % ./myenv ls -l
total 384
-rw-r--r--  1 sakochihiro  staff     132  6 30 11:40 Makefile
-rw-r--r--  1 sakochihiro  staff    1268  6 30 11:40 README.md
-rw-r--r--  1 sakochihiro  staff  139098  6 30 11:40 README.pdf
-rwxr-xr-x  1 sakochihiro  staff   33736  6 30 11:49 myenv
-rw-r--r--  1 sakochihiro  staff     927  6 30 11:45 myenv.c
-rwxr-xr-x  1 sakochihiro  staff     216  6 30 11:40 myputenv.c
-rw-r--r--  1 sakochihiro  staff      93  6 30 11:40 myputenv.h
sakochihiro@chr1007 kadai09-i23sako % ./myenv abc
abc: No such file or directory


*/