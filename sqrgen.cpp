#include <unistd.h>

#include <iostream>
#include <memory>

#include "sndfile.hh"

using namespace std;

constexpr auto sampleRate = 44100;
constexpr auto nChannels = 1;

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
  const size_t outputSamplesCount = duration * sampleRate;

  // Buffer to store samples to be written to output file
  float buffer[outputSamplesCount * nChannels];

  // Open a sound file to store audio
  auto outputFile =
      SndfileHandle("square.wav", SFM_WRITE, (SF_FORMAT_WAV | SF_FORMAT_FLOAT),
                    nChannels, sampleRate);

  // Generate a square wave
  size_t wavePeriod = sampleRate / freq; // wave period in samples
  for (size_t i = 0; i < outputSamplesCount; i++)
  {
    buffer[i] = ((i % wavePeriod) < (wavePeriod / 2)) ? -1.0 : 1.0;
  }

  // Write buffer to output file
  outputFile.write(buffer, outputSamplesCount);

  return EXIT_SUCCESS;
}
