// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenSoulStateVectorLegacyBridge.h"

FSoulStateVector UAshenSoulStateVectorLegacyBridge::ConvertLegacyMetersToCanonicalVector(float RawSanity, float RawCorruption, float RawDebt)
{
	FSoulStateVector State;
	State.Resolve = FMath::Clamp(RawSanity / 100.0f, 0.0f, 1.0f);
	State.Corruption = FMath::Clamp(RawCorruption / 100.0f, 0.0f, 1.0f);
	State.Isolation = FMath::Clamp(RawDebt / 100.0f, 0.0f, 1.0f);
	return State;
}
