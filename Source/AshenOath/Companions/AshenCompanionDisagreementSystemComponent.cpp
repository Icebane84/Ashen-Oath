// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 434: Ashen Companion Disagreement System Component

#include "AshenCompanionDisagreementSystemComponent.h"

UAshenCompanionDisagreementSystemComponent::UAshenCompanionDisagreementSystemComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionDisagreementSystemComponent::EvaluateCompanionInterpretations(const FAshenSoulStateVector& SoulVector)
{
	// Garrett thinks: "He's losing himself" (Focuses on Integration Debt & Sanity)
	const float GarrettConcern = (SoulVector.IntegrationDebt * 0.6f) + ((100.0f - SoulVector.Sanity) * 0.4f);
	FString GarrettText = (GarrettConcern > 40.0f) ? TEXT("Garrett: 'Kaelen is losing control of the Oath...'") : TEXT("Garrett: 'He's holding... for now.'");
	OnCompanionInterpretation.Broadcast(FName(TEXT("Companion_Garrett")), GarrettText, GarrettConcern);

	// Serafina thinks: "He's suffering" (Focuses on Corruption & Health)
	const float SerafinaConcern = (SoulVector.CorruptionLevel * 0.7f) + ((100.0f - SoulVector.Health) * 0.3f);
	FString SerafinaText = (SerafinaConcern > 30.0f) ? TEXT("Serafina: 'His soul carries unbearable pain...'") : TEXT("Serafina: 'The light still burns within him.'");
	OnCompanionInterpretation.Broadcast(FName(TEXT("Companion_Serafina")), SerafinaText, SerafinaConcern);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCompanionDisagreementSystemComponent: COMPANION INTERPRETATIONS EVALUATED — Garrett Concern: %.1f | Serafina Concern: %.1f"),
		GarrettConcern, SerafinaConcern);
}


