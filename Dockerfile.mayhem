FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential

COPY . /repo
WORKDIR /repo/src/parser/lexer
RUN gcc -I/repo/src -o lexer *.c /repo/src/builtins/*.c
FROM ubuntu:22.04 as package
COPY --from=builder /repo/src/parser/lexer/lexer /
