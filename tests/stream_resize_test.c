/* Sonic library
   Copyright 2026
   Bill Cox
   This file is part of the Sonic Library.

   This file is licensed under the Apache 2.0 license.
*/

#include "sonic.h"

#include <stdio.h>

#define SAMPLES 4000

/* Changing the sample rate drops buffered samples.  Stale counters used to
   outlive the smaller reallocated buffers and overflow them on the next
   write. */
int sonicTestSetSampleRateDropsBufferedSamples(void) {
  short in[SAMPLES];
  short out[SAMPLES];
  int i;
  sonicStream stream = sonicCreateStream(44100, 1);

  if (stream == NULL) {
    return 0;
  }
  for (i = 0; i < SAMPLES; i++) {
    in[i] = (short)((i % 100) * 100);
  }
  sonicSetSpeed(stream, 1.5f);
  sonicWriteShortToStream(stream, in, 1300);
  sonicSetSampleRate(stream, 8000);
  if (sonicSamplesAvailable(stream) != 0) {
    fprintf(stderr, "Buffered samples survived sonicSetSampleRate\n");
    return 0;
  }
  sonicWriteShortToStream(stream, in, SAMPLES);
  sonicFlushStream(stream);
  sonicReadShortFromStream(stream, out, SAMPLES);
  sonicDestroyStream(stream);
  return 1;
}

/* Speed far from 1.0 yields zero-length pitch adjustments.  Processing must
   still consume input and terminate. */
int sonicTestExtremeRatiosTerminate(void) {
  short in[SAMPLES];
  short out[SAMPLES * 4];
  int i;
  float speeds[2] = {400.0f, 0.0025f};
  int s;

  for (i = 0; i < SAMPLES; i++) {
    in[i] = (short)((i % 100) * 100);
  }
  for (s = 0; s < 2; s++) {
    sonicStream stream = sonicCreateStream(44100, 1);
    if (stream == NULL) {
      return 0;
    }
    sonicSetSpeed(stream, speeds[s]);
    sonicWriteShortToStream(stream, in, SAMPLES);
    sonicFlushStream(stream);
    sonicReadShortFromStream(stream, out, SAMPLES * 4);
    sonicDestroyStream(stream);
  }
  return 1;
}
