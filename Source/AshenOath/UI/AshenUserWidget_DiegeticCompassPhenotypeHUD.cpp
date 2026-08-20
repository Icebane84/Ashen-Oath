// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_DiegeticCompassPhenotypeHUD.h"

void UAshenUserWidget_DiegeticCompassPhenotypeHUD::OnSoulStateInvalidated(const FSoulStateVector& StateVector)
{
	CompassNeedleJitterAngleOffset = (StateVector.Isolation * 15.0f) * (FMath::RandBool() ? 1.0f : -1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_DiegeticCompassPhenotypeHUD: Compass needle jitter angle offset set to %.2f deg"), CompassNeedleJitterAngleOffset);
}
