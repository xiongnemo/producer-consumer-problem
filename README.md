# Producer–consumer problem

Course project #1 of Operating System, May 2020

## Environment

For best visual effect, use it in a terminal.

It can be compiled under WSL, using gcc 7.5.0.

* I think a real Linux should also do the trick.

```text
            .-/+oossssoo+/-.
        `:+ssssssssssssssssss+:`           nemo@marshmallow-laptop
      -+ssssssssssssssssssyyssss+-         -----------------------
    .ossssssssssssssssssdMMMNysssso.       OS: Ubuntu 18.04.4 LTS on Windows 10 x86_64
   /ssssssssssshdmmNNmmyNMMMMhssssss/      Kernel: 4.4.0-18362-Microsoft
  +ssssssssshmydMMMMMMMNddddyssssssss+     Uptime: 4 days, 5 hours, 32 mins
 /sssssssshNMMMyhhyyyyhmNMMMNhssssssss/    Packages: 854
.ssssssssdMMMNhsssssssssshNMMMdssssssss.   Shell: zsh 5.4.2
+sssshhhyNMMNyssssssssssssyNMMMysssssss+   Terminal: vscode
ossyNMMMNyMMhsssssssssssssshmmmhssssssso   CPU: Intel i5-8300H (8) @ 2.304GHz
ossyNMMMNyMMhsssssssssssssshmmmhssssssso   Memory: 12806MiB / 16240MiB
+sssshhhyNMMNyssssssssssssyNMMMysssssss+
.ssssssssdMMMNhsssssssssshNMMMdssssssss.
 /sssssssshNMMMyhhyyyyhdNMMMNhssssssss/
  +sssssssssdmydMMMMMMMMddddyssssssss+
   /ssssssssssshdmNNNNmyNMMMMhssssss/
    .ossssssssssssssssssdMMMNysssso.
      -+sssssssssssssssssyyyssss+-
        `:+ssssssssssssssssss+:`
            .-/+oossssoo+/-.
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
