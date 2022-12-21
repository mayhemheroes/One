FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential clang

COPY . /repo
WORKDIR /repo/src/parser/lexer
RUN gcc -I/repo/src -o lexer *.c /repo/src/builtins/*.c
RUN clang /repo/mayhem/fuzz_string_append.cpp /repo/src/builtins/string.c -fsanitize=fuzzer,address -o /fuzz 

FROM ubuntu:22.04 as package
COPY --from=builder /repo/src/parser/lexer/lexer /
COPY --from=builder /fuzz/ /fuzz_string_append
