#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sndfile.h>

#define SRATE (44100)
#define NCHANNELS (1)

int main(int argc, char const *argv[]) {

  double dur = 1.0;    // duration of sound (seconds)
  double freq = 440.0; // frequency of wave (Herz)

  // Parse optional args
  int opt;
  while ((opt = getopt(argc, argv, "d:f:")) != -1) {
    switch (opt) {
    case 'd':
      dur = atof(optarg);
      break;
    case 'f':
      freq = atof(optarg);
      break;
    }
  }

  size_t output_samples_count = dur * SRATE; // number of output samples

  // Buffer to store samples to be written to output file
  float *buffer = malloc(sizeof *buffer * output_samples_count * NCHANNELS);
  if (buffer == NULL) {
    printf("Malloc for buffer failed.\n");
    return EXIT_FAILURE;
  }

  // Output file settings
  SF_INFO sfinfo = {
      .samplerate = SRATE,
      .channels = NCHANNELS,
      .format = (SF_FORMAT_WAV | SF_FORMAT_FLOAT),
  };

  SNDFILE *output_file = sf_open("sine.wav", SFM_WRITE, &sfinfo);
  // TODO: handle error when unable to open file

  // Generate a square wave
  size_t wave_period = SRATE / freq; // wave period in samples
  for (size_t i = 0; i < output_samples_count; i++) {
    buffer[i] = sin(i * 2 * M_PI / wave_period);
  }
  sf_write_float(output_file, buffer, output_samples_count);
  // TODO: handle sample count when 1 < NCHANNELS

  // Exit routine - free allocated memory and close open files
  sf_close(output_file);
  free(buffer);

  return EXIT_SUCCESS;
}
