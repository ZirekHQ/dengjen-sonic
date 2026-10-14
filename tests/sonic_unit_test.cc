#include "testing/base/public/gunit.h"
#include "third_party/sonic/tests/tests.h"

namespace {

TEST(SonicUnitTests, ClampTest) {
  EXPECT_TRUE(sonicTestInputClamping());
  EXPECT_TRUE(sonicTestInputsDontCrash());
}

TEST(SonicUnitTests, ApiTest) {
  EXPECT_TRUE(sonicTestStreamCreation());
  EXPECT_TRUE(sonicTestParameters());
  EXPECT_TRUE(sonicTestFlush());
  EXPECT_TRUE(sonicTestSimpleProcessing());
}

TEST(SonicUnitTests, ChordPitchTest) {
  EXPECT_TRUE(sonicTestChordPitchChangesOutput());
  EXPECT_TRUE(sonicTestChordPitchExtremeRatioDoesNotOverflow());
  EXPECT_TRUE(sonicTestChordPitchPreservesConstantSignal());
  EXPECT_TRUE(sonicTestChordPitchAppliesRate());
  EXPECT_TRUE(sonicTestSetPitchRejectsNaN());
  EXPECT_TRUE(sonicTestChordPitchReturnToUnityDrainsBuffer());
}

TEST(SonicUnitTests, StreamStateTest) {
  EXPECT_TRUE(sonicTestRepeatedPitchChangesDontDesyncRatePosition());
  EXPECT_TRUE(sonicTestSlowdownFlushProducesExpectedDuration());
  EXPECT_TRUE(sonicTestSetSampleRateDropsBufferedSamples());
  EXPECT_TRUE(sonicTestExtremeRatiosTerminate());
}

}  // namespace
