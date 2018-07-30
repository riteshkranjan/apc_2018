#include <string.h>

int base64encode(const char *data, int dataLength, char *result) {
  const char base64chars[] =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  int resultIndex = 0;
  int x;
  int padCount = dataLength % 3;
  int n0, n1, n2, n3;
  for (x = 0; x < dataLength;) {
    int n = x < dataLength ? data[x++] << 16 : 0;
    n += x < dataLength ? data[x++] << 8 : 0;
    n += x < dataLength ? data[x++] : 0;
    n0 = (n >> 18) & 63;
    n1 = (n >> 12) & 63;
    n2 = (n >> 6) & 63;
    n3 = n & 63;

    result[resultIndex++] = base64chars[n0];
    result[resultIndex++] = base64chars[n1];
    result[resultIndex++] = base64chars[n2];
    result[resultIndex++] = base64chars[n3];
  }

  result[resultIndex] = 0;

  if (padCount > 0) {
    for (; padCount < 3; padCount++) {
      result[--resultIndex] = '=';
    }
  }
  return 0;
}

char *encode(char *input) {

  int input_size = strlen(input);
  int output_size = 4 * ((input_size + 2) / 3);
  char *result = malloc(output_size);
  base64encode(input, input_size, result);
  return result;
}
