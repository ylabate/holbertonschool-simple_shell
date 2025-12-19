# **holbertonschool-simple_shell**

## **Description**

This repository contains the simple-shell project that was given to us to do in pairs by Holberton School as part of our learning program.

The goal of this project was:

- To train ourselves to work as a team
- To design a simple and valid flowchart
- To work while respecting the contrainst imposed by the checker
- To translate a diagram into working a C code
- To write clean, readable, and maintainable code.

This repository provides:

- A complete and validated flowchart
- The corresponding C implementation
- The compiler corresponding to the simple-shell project

Here is the list of allowed functions and system calls+:

- all functions from string.h
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- printf (man 3 printf)
- fprintf (man 3 fprintf)
- vfprintf (man 3 vfprintf)
- sprintf (man 3 sprintf)
- putchar (man 3 putchar)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

It's one possible solution among others, but here's the one we came up with by creating our flowchart.


**Ajouter Flowchart**

## **Objectives**

At the end of the simple-shell project, we should be able to explain to anyone, without the help of google:

- Work collaboratively within a group of peers
- How our flowchart works and how we translated it into C code
- To be able to explain all the steps of all our codes
- Explain clearly how program work
- Read and design a flowchart describing program logic

## **Requierement**

The program for our simple-shell project will be compiled using:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
- The code should use the Betty style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl)
- No more than 5 function per file
- All our header files should be include guarded
- The prototypes of all our functions are included in our header file called "main.h".

## **Tech Stack**

- **Language:** C
- **Compiler:** GCC
- **IDE / Editor:** VS Code
- **Operating System:** Linux / Windows / Docker

## **File Description**

| **File** | **Description** |
|------------|-----------------------------------------------------------------------------|
| README.md | Project documentation: Explain the purpose, installation steps, usage, project structure and the technologies used |
| man_1_simple_shell | Shell manual describing its usage and commands |
| main.c | Contains the main function of the program and starts its execution |
| main.h | Program header file. It contains the prototypes of the functions and the structures used |
| prompt.c | Contains the function that displays the prompt and reads the user's command |
| built_in_command.c | Contains the function that checks and executes the shell's built-in commands |
| env.c | Contains the function that displays the environment variables |
| search_path.c | Contains the function that searches for the location of a command in the PATH |
| shell_env.c | Contains the function that displays the shell environment |
| signal.c | Contains the functions that handle the program's signals |
| split_arg.c | Contains the function that splits a command into arguments |
| exec_subprocess.c | Contains the function that executes shell commands in subprocesses |
| start_subprocess | Handles execution of commands in subprocesses |
| exit.c | Contains the function that exits the shell |

## **Installation and Usage**

### **Installation**

1 - Clone this repository

- Open your terminal
- Navigate to the repository where you want to clone the repository
- Run the following command:
```
git clone https://github.com/ylabate/holbertonschool-simple_shell.git
```

2 - Open the cloned repository

3 - Compile the program

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
Then type this command to be in the correct directory

```
cd holbertonschool-simple_shell
```
### **Usage**

1 - Run the program with the main test file

```
./hsh
```
With the main test file included, you should to run the command.

When you run the command ls, you should obtain this following output:

```
AUTHORS  README.md  a.out  build_in_command.c  env.c  main.c  main.h  prog  prompt.c  search_path.c  shell_env.c  signal.c  split_arg.c  subprocess.c
```
When you run the command env, you should obtain this following output:

```
SHELL=/bin/bash
COLORTERM=truecolor
WSL2_GUI_APPS_ENABLED=1
TERM_PROGRAM_VERSION=1.107.0
WSL_DISTRO_NAME=Ubuntu
NAME=LAPTOP-LKQES678
PWD=/home/caule/holbertonschool-simple_shell
LOGNAME=caule
VSCODE_GIT_ASKPASS_NODE=/home/caule/.vscode-server/bin/618725e67565b290ba4da6fe2d29f8fa1d4e3622/node
HOME=/home/caule
LANG=C.UTF-8
WSL_INTEROP=/run/WSL/444_interop
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=00:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.avif=01;35:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:*~=00;90:*#=00;90:*.bak=00;90:*.crdownload=00;90:*.dpkg-dist=00;90:*.dpkg-new=00;90:*.dpkg-old=00;90:*.dpkg-tmp=00;90:*.old=00;90:*.orig=00;90:*.part=00;90:*.rej=00;90:*.rpmnew=00;90:*.rpmorig=00;90:*.rpmsave=00;90:*.swp=00;90:*.tmp=00;90:*.ucf-dist=00;90:*.ucf-new=00;90:*.ucf-old=00;90:
WAYLAND_DISPLAY=wayland-0
GIT_ASKPASS=/home/caule/.vscode-server/bin/618725e67565b290ba4da6fe2d29f8fa1d4e3622/extensions/git/dist/askpass.sh
VSCODE_GIT_ASKPASS_EXTRA_ARGS=
VSCODE_PYTHON_AUTOACTIVATE_GUARD=1
LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm-256color
LESSOPEN=| /usr/bin/lesspipe %s
USER=caule
VSCODE_GIT_IPC_HANDLE=/run/user/1000/vscode-git-5962e5b94d.sock
DISPLAY=:0
SHLVL=1
XDG_RUNTIME_DIR=/run/user/1000/
DEBUGINFOD_URLS=https://debuginfod.ubuntu.com 
WSLENV=VSCODE_WSL_EXT_LOCATION/up
VSCODE_GIT_ASKPASS_MAIN=/home/caule/.vscode-server/bin/618725e67565b290ba4da6fe2d29f8fa1d4e3622/extensions/git/dist/askpass-main.js
XDG_DATA_DIRS=/usr/local/share:/usr/share:/var/lib/snapd/desktop
PATH=/home/caule/.vscode-server/data/User/globalStorage/github.copilot-chat/debugCommand:/home/caule/.vscode-server/data/User/globalStorage/github.copilot-chat/copilotCli:/home/caule/.vscode-server/bin/618725e67565b290ba4da6fe2d29f8fa1d4e3622/bin/remote-cli:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/usr/lib/wsl/lib:/mnt/c/Program Files (x86)/NVIDIA Corporation/PhysX/Common:/mnt/c/WINDOWS/system32:/mnt/c/WINDOWS:/mnt/c/WINDOWS/System32/Wbem:/mnt/c/WINDOWS/System32/WindowsPowerShell/v1.0/:/mnt/c/WINDOWS/System32/OpenSSH/:/mnt/c/Program Files (x86)/Windows Kits/8.1/Windows Performance Toolkit/:/mnt/c/Program Files/Git/cmd:/mnt/c/Users/caule/AppData/Local/Microsoft/WindowsApps:/mnt/c/Users/caule/AppData/Local/Programs/Microsoft VS Code/bin:/snap/bin
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
HOSTTYPE=x86_64
PULSE_SERVER=unix:/mnt/wslg/PulseServer
TERM_PROGRAM=vscode
VSCODE_IPC_HOOK_CLI=/run/user/1000/vscode-ipc-cda5c768-5e8a-41e3-85ae-93ae5c14d913.sock
_=./a.out
```
And when you run the command exit, the program is closing.

## **Thanks**

We thank Holberton school for this simple-shell project and for allowing us to work in pairs

## **Authors**

### **Ylan Labare Bekate**

```
Github: https://github.com/ylabate
```

### **Théo Caulet**

```
Github: https://github.com/theocaulet
```





