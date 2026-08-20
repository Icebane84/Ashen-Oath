// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenExpeditionLogViewModel.h"

UAshenExpeditionLogViewModel::UAshenExpeditionLogViewModel()
{
}

void UAshenExpeditionLogViewModel::UpdateHandwritingFromIntegrationDebt(float IntegrationDebt)
{
	HandwritingJaggedness = FMath::Clamp(IntegrationDebt, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenExpeditionLogViewModel: Updated handwriting jaggedness scalar to %f"), HandwritingJaggedness);
}
