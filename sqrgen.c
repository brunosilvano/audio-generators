#include <stdio.h>
#include <stdlib.h>

#include <sndfile.h>

#define SRATE (44100)
#define NCHANNELS (1)

int main(int argc, char const *argv[]) {
  double dur = 1.0; // duration of sound in seconds
  double freq = 440.0;
  size_t output_samples_count = dur * SRATE; // number of output samples

  // Buffer to store samples to be written to output file
  float *buffer = malloc(sizeof(float) * output_samples_count * NCHANNELS);
  if (buffer == NULL) {
    printf("Malloc for buffer failed.\n");
    return EXIT_FAILURE;
  }

  // Output file settings
  SF_INFO sfinfo = {
      .frames = output_samples_count * NCHANNELS,
      .samplerate = SRATE,
      .channels = NCHANNELS,
      .format = (SF_FORMAT_WAV | SF_FORMAT_FLOAT),
  };

  SNDFILE *output_file = sf_open("square.wav", SFM_WRITE, &sfinfo);

  // Generate a square wave
  size_t wave_period = SRATE / freq; // wave period in samples
  for (size_t i = 0; i < output_samples_count; i++) {
    buffer[i] = (i % wave_period < wave_period / 2) ? 0.0 : 0.8;
  }

  sf_write_float(output_file, buffer, output_samples_count);
  sf_close(output_file);

  return EXIT_SUCCESS;
}
