# Simple Shell

## Introduction

This is a Holberton School project that consists of making our own simple shell with a limited amount of functions from the standard library.

### List of allowed functions and system calls
* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* getpid (man 2 getpid)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)

## Usage

To use this program:

Clone the repo

    git clone https://github.com/Nachop51/simple_shell

Compile it with

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

### How to use it

In order to use this shell, in a terminal, first run the program:

`prompt$ ./hsh`

It will then display a simple prompt and wait for commands.

`$`

A command will be of the type `$ command`
This shell can handle two types of commands: builtins and normal program.

### List of built-ins
* exit  
    Exits the shell
* env  
    Prints the current environment
* setenv  
    Initialize a new environment variable, or modify an existing one
* unsetenv  
    Remove an environment variable
* cd [directory]  
    Changes the current directory of the process
* help  
    Display all the enviroment variables
* history  
    Displays the history list

### Command

Basicly Every Program in $PATH It Support Single Word like ls

It Handle Path ls /tmp

it Handle Options Like ls -l

it Handle All Three Togther Like ls -l /var

it Handle Command Path Also Like /bin/ls And All The Option And Path Like /bin/ls -l /var

it Handle Comments #

## Examples Command

### Example 1
    username@prompt:~$ ./hsh
    $ pwd
    /home/simple_shell/
    $ ^D
    username@prompt:~$

### Example 2
    username@prompt:~$ ./hsh
    $ ls -l /tmp
    total 0
    drwx------ 2 root  root  22 Dec 20 11:41 tmpa2zvokgp
    drwx------ 2 mysql mysql  6 Dec 20 11:54 tmp.GMWnSs1EVB
    drwx------ 2 mysql mysql  6 Dec 20 11:37 tmp.ugKboEbH00

## Examples Builtin

### Case env

    username@prompt:~$ ./hsh
    $ env
    HOSTNAME=11548ecbb7ce
    LANGUAGE=en_US:en
    PWD=/home/simple_shell/k
    TZ=America/Los_Angeles
    HOME=/root
    LANG=en_US.UTF-8
    LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
    LESSCLOSE=/usr/bin/lesspipe %s %s
    TERM=xterm
    LESSOPEN=| /usr/bin/lesspipe %s
    SHLVL=1
    LC_ALL=en_US.UTF-8
    PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
    OLDPWD=/home
    _=./a.out

### Case exit status

    username@prompt:~$ ./hsh
    $ exit 98
    username@prompt:~$ echo $?
    98
    username@prompt:~$

## Also
* Handle Ctrl+C: The shell will not close when the user enters ^D
* If no argument is given to cd the command must be interpreted like cd $HOME
* Handle the command cd -
* Handle the $? variable

## Custom Function (Recreation of Standard Function in C)
_strncpy
_strlen
_putchar
_atoi
_strcmp
str_concat
_strcpy
_strncmp
_strdup
_getenv
_strtok

For More Info About It Check The Man Page by:

    username@prompt:~$ man ./man_1_simple_shell

## Authors
Nacho Peralta & Kevin Fundora
