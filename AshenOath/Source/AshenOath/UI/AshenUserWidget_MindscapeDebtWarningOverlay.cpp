// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_MindscapeDebtWarningOverlay.h"

void UAshenUserWidget_MindscapeDebtWarningOverlay::OnSoulStateInvalidated(const FSoulStateVector& StateVector)
{
	VignetteDistortionOpacity = FMath::Clamp((StateVector.IntegrationDebt - 0.5f) * 2.0f, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_MindscapeDebtWarningOverlay: Vignette distortion opacity updated to %.2f (IntegrationDebt: %.2f)"),
		VignetteDistortionOpacity, StateVector.IntegrationDebt);
}
