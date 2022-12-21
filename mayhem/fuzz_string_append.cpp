#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include "string.h"
#include <fuzzer/FuzzedDataProvider.h>

typedef struct
{
	char* str;
	char* end;
	size_t size;
} string;

extern "C" string* string_new();

extern "C" void string_append(string* ss, char* suffix);

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
{
	FuzzedDataProvider provider(data, size);
    std::string str = provider.ConsumeRandomLengthString();
	string* ss = string_new();
	char* suffix = strdup(str.c_str());

	string_append(ss, suffix);

	free(ss);
	free(suffix);

	return 0;
}