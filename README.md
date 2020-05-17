# Producer–consumer problem

## Environment

For best visual effect, use it in a terminal.

It can be compiled under WSL, using gcc 7.5.0.

* I think a real Linux should also do the trick.
* You can also use Mingw-w64.
* In Releases tab, I provided a GUI shell for Windows. It needs a .Net Framework 4.7.2.

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
cd src && gcc producer-consumer-problem.c buffer.c consumers.c producers.c utils.c -Wall -pthread -g -std=c11 -o producer-consumer-problem
```

or

```bash
cd src && make
```

## Run

```bash
cd src && ./producer-consumer-problem
```
