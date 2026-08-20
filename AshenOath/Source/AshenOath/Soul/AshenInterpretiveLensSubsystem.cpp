// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenInterpretiveLensSubsystem.h"

void UAshenInterpretiveLensSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveLens = EInterpretiveLens::Grace;
	UE_LOG(LogTemp, Log, TEXT("UAshenInterpretiveLensSubsystem: Interpretive Lens Subsystem initialized (Default: Grace)."));
}
void UAshenInterpretiveLensSubsystem::Deinitialize() { Super::Deinitialize(); }

void UAshenInterpretiveLensSubsystem::SetActiveLens(EInterpretiveLens InLens)
{
	ActiveLens = InLens;
	FString LensName = TEXT("Grace");
	if (ActiveLens == EInterpretiveLens::Accountability) LensName = TEXT("Accountability");
	else if (ActiveLens == EInterpretiveLens::Utility) LensName = TEXT("Utility");

	UE_LOG(LogTemp, Warning, TEXT("UAshenInterpretiveLensSubsystem: Active Interpretive Lens set to '%s'."), *LensName);
}

void UAshenInterpretiveLensSubsystem::ApplyInterpretiveFilter(float& InOutGarrettWeight, float& InOutSerafinaWeight)
{
	switch (ActiveLens)
	{
	case EInterpretiveLens::Accountability:
		InOutGarrettWeight *= 1.15f; // +15% Garrett Trust bias
		InOutSerafinaWeight *= 0.95f;
		break;
	case EInterpretiveLens::Grace:
		InOutSerafinaWeight *= 1.15f; // +15% Serafina Trust bias
		InOutGarrettWeight *= 0.95f;
		break;
	case EInterpretiveLens::Utility:
		InOutGarrettWeight *= 1.05f;
		InOutSerafinaWeight *= 1.05f;
		break;
	default:
		break;
	}
}
