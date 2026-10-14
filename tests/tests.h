/* Sonic library
   Copyright 2025
   Bill Cox
   This file is part of the Sonic Library.

   This file is licensed under the Apache 2.0 license.
*/

#ifdef __cplusplus
extern "C" {
#endif

int sonicTestInputClamping(void);
int sonicTestInputClamping(void);
int sonicTestInputsDontCrash(void);
int sonicTestStreamCreation(void);
int sonicTestParameters(void);
int sonicTestFlush(void);
int sonicTestSimpleProcessing(void);
int sonicTestWaveRejectsZeroChannels(void);
int sonicTestChordPitchChangesOutput(void);
int sonicTestChordPitchExtremeRatioDoesNotOverflow(void);
int sonicTestRepeatedPitchChangesDontDesyncRatePosition(void);
int sonicTestSlowdownFlushProducesExpectedDuration(void);
int sonicTestChordPitchPreservesConstantSignal(void);
int sonicTestChordPitchAppliesRate(void);
int sonicTestSetPitchRejectsNaN(void);
int sonicTestChordPitchReturnToUnityDrainsBuffer(void);
int sonicTestSetSampleRateDropsBufferedSamples(void);
int sonicTestExtremeRatiosTerminate(void);

#ifdef __cplusplus
}
#endif
