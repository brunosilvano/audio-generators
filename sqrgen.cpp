#include <unistd.h>

#include <iostream>
#include <memory>

#include "sndfile.hh"

using namespace std;

#define SAMPLERATE (44100)
#define NCHANNELS (1)

int main(int argc, char* argv[])
{
  double duration = 1.0; // duration of sound (seconds)
  double freq = 440.0;   // frequency of wave (Hertz)

  // Parse optional args
  int opt;
  while ((opt = getopt(argc, argv, "d:f:")) != -1)
  {
    switch (opt)
    {
    case 'd':
      duration = atof(optarg);
      break;
    case 'f':
      freq = atof(optarg);
      break;
    }
  }

  // Number of output samples
  size_t output_samples_count = duration * SAMPLERATE;

  // Buffer to store samples to be written to output file
  float buffer[output_samples_count * NCHANNELS];

  // Open a sound file to store audio
  SndfileHandle output_file =
      SndfileHandle("square.wav", SFM_WRITE, (SF_FORMAT_WAV | SF_FORMAT_FLOAT),
                    NCHANNELS, SAMPLERATE);

  // Generate a square wave and write to target file
  size_t wave_period = SAMPLERATE / freq; // wave period in samples
  for (size_t i = 0; i < output_samples_count; i++)
  {
    buffer[i] = ((i % wave_period) < (wave_period / 2)) ? -1.0 : 1.0;
  }
  output_file.write(buffer, output_samples_count);

  return EXIT_SUCCESS;
}
