#include <stdlib.h>
#include <string.h>

#include <sndfile.h>

#define BUFFER_SIZE (1024)

int main(int argc, char const *argv[]) {
  SNDFILE *input_sf = NULL;
  SNDFILE *output_sf = NULL;

  SF_INFO input_sf_info;
  SF_INFO output_sf_info;

  double *buffer = NULL;

  char *input_filename = "square.wav";
  char *output_filename = "square(processed).wav";

  // Initialize input_sf_info with all values set to 0
  memset(&input_sf_info, 0, sizeof(input_sf_info));

  // Open input file
  input_sf = sf_open(input_filename, SFM_READ, &input_sf_info);
  if (!input_sf) {
    printf("Unable to open input file \"%s\":\n\t%s\n", input_filename,
           sf_strerror(input_sf));
    goto cleanup;
  }

  output_sf_info = input_sf_info;

  // Open output file
  output_sf = sf_open(output_filename, SFM_WRITE, &output_sf_info);
  if (!output_sf) {
    printf("Unable to open output file \"%s\":\n\t%s\n", output_filename,
           sf_strerror(output_sf));
    goto cleanup;
  }

  // Allocate a buffer for temporary storage of audio data
  buffer = malloc(sizeof *buffer * BUFFER_SIZE);
  if (buffer == NULL) {
    printf("Unable to malloc for buffer\n");
    goto cleanup;
  }

  // Read input file frames
  sf_count_t read_count = 0;
  while ((read_count = sf_read_double(input_sf, buffer, BUFFER_SIZE))) {

    // Do any audio processing here...

    sf_write_double(output_sf, buffer, read_count);
  }

cleanup:
  if (input_sf)
    sf_close(input_sf);
  if (output_sf)
    sf_close(output_sf);
  free(buffer);

  return EXIT_SUCCESS;
}
