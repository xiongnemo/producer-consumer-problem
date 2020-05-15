# Producer–consumer problem

Course project #1 of Operating System, May 2020

## Environment

For best visual effect, use it in a terminal.

It can be compiled under WSL, using gcc 7.5.0.

* I think a real Linux should also do the trick.
* Use mingw-w64 under Windows.

```reStructuredText
nemo@marshmallow-laptop
-----------------------
OS: Ubuntu 18.04.4 LTS on Windows 10 x86_64
Kernel: 4.4.0-18362-Microsoft
Uptime: 4 days, 5 hours, 32 mins
Packages: 854
Shell: zsh 5.4.2
Terminal: vscode
CPU: Intel i5-8300H (8) @ 2.304GHz
Memory: 12806MiB / 16240MiB
```

## Compile

```bash
gcc producer-consumer-problem.c buffer.c consumers.c producers.c utils.c -Wall -pthread -g -std=c11 -o producer-consumer-problem
```

or

```bash
make
```

## Run

```bash
./producer-consumer-problem
```
