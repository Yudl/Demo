// JSON condenser example

// This example parses JSON text from stdin with validation, 
// and re-output the JSON content to stdout without whitespace.

#include "F:/GitHub/rapidjson/include/rapidjson/reader.h"
#include "F:/GitHub/rapidjson/include/rapidjson/writer.h"
#include "F:/GitHub/rapidjson/include/rapidjson/filereadstream.h"
#include "F:/GitHub/rapidjson/include/rapidjson/filewritestream.h"
#include "F:/GitHub/rapidjson/include/rapidjson/error/en.h"

using namespace rapidjson;

int main2(int, char*[]) {
    // Prepare JSON reader and input stream.
    Reader reader;
    char readBuffer[65536];
    FileReadStream is(stdin, readBuffer, sizeof(readBuffer));

    // Prepare JSON writer and output stream.
    char writeBuffer[65536];
    FileWriteStream os(stdout, writeBuffer, sizeof(writeBuffer));
    Writer<FileWriteStream> writer(os);

    // JSON reader parse from the input stream and let writer generate the output.
    if (!reader.Parse(is, writer)) {
        fprintf(stderr, "\nError(%u): %s\n", static_cast<unsigned>(reader.GetErrorOffset()), GetParseError_En(reader.GetParseErrorCode()));
        return 1;
    }

    return 0;
}