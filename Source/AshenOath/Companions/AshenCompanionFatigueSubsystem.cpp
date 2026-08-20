// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenCompanionFatigueSubsystem.h"

void UAshenCompanionFatigueSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	GarrettFatigue = 0.0f;
	SerafinaFatigue = 0.0f;
	KaelenFatigue = 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionFatigueSubsystem: Companion Fatigue Subsystem initialized."));
}
void UAshenCompanionFatigueSubsystem::Deinitialize() { Super::Deinitialize(); }

void UAshenCompanionFatigueSubsystem::AccumulateFatigue(FName CompanionID, float Delta)
{
	if (CompanionID == FName(TEXT("Garrett")))
	{
		GarrettFatigue = FMath::Clamp(GarrettFatigue + Delta, 0.0f, 1.0f);
	}
	else if (CompanionID == FName(TEXT("Serafina")))
	{
		SerafinaFatigue = FMath::Clamp(SerafinaFatigue + Delta, 0.0f, 1.0f);
	}
	else if (CompanionID == FName(TEXT("Kaelen")))
	{
		KaelenFatigue = FMath::Clamp(KaelenFatigue + Delta, 0.0f, 1.0f);
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionFatigueSubsystem: Fatigue updated for %s (+%.2f) -> Garrett: %.2f, Serafina: %.2f, Kaelen: %.2f"),
		*CompanionID.ToString(), Delta, GarrettFatigue, SerafinaFatigue, KaelenFatigue);
}

void UAshenCompanionFatigueSubsystem::RecoverFatigue(float DeltaSeconds)
{
	const float RecoveryRate = 0.015f * DeltaSeconds;
	GarrettFatigue = FMath::Max(0.0f, GarrettFatigue - RecoveryRate);
	SerafinaFatigue = FMath::Max(0.0f, SerafinaFatigue - RecoveryRate);
	KaelenFatigue = FMath::Max(0.0f, KaelenFatigue - RecoveryRate);
}

bool UAshenCompanionFatigueSubsystem::IsCompanionVulnerable(FName CompanionID) const
{
	if (CompanionID == FName(TEXT("Garrett"))) return GarrettFatigue >= 0.70f;
	if (CompanionID == FName(TEXT("Serafina"))) return SerafinaFatigue >= 0.70f;
	if (CompanionID == FName(TEXT("Kaelen"))) return KaelenFatigue >= 0.70f;
	return false;
}
