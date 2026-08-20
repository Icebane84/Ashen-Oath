// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenDialogueChoiceEvaluator.h"

UAshenDialogueChoiceEvaluator::UAshenDialogueChoiceEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentStance = ECompiledRelationalStance::WeaverStance;
}
void UAshenDialogueChoiceEvaluator::BeginPlay() { Super::BeginPlay(); }

void UAshenDialogueChoiceEvaluator::EvaluateTherapyChoice(EInterpretiveTherapyLens ChosenLens, float& OutBurnoutDecayModifier, float& OutTrustDelta)
{
	switch (ChosenLens)
	{
	case EInterpretiveTherapyLens::Accountability:
		CurrentStance = ECompiledRelationalStance::MartyrStance;
		OutBurnoutDecayModifier = 1.0f;
		OutTrustDelta = -0.15f;
		CurrentTrustVector.KaelenToSerafinaTrust = FMath::Clamp(CurrentTrustVector.KaelenToSerafinaTrust + OutTrustDelta, 0.0f, 1.0f);
		UE_LOG(LogTemp, Warning, TEXT("UAshenDialogueChoiceEvaluator: Lens of Accountability -> Martyr Stance (+10%% Solo Parry, Trust: %.2f)"),
			CurrentTrustVector.KaelenToSerafinaTrust);
		break;

	case EInterpretiveTherapyLens::Grace:
		CurrentStance = ECompiledRelationalStance::WeaverStance;
		OutBurnoutDecayModifier = 1.25f; // +25% Burnout decay
		OutTrustDelta = 0.25f;
		CurrentTrustVector.KaelenToSerafinaTrust = FMath::Clamp(CurrentTrustVector.KaelenToSerafinaTrust + OutTrustDelta, 0.0f, 1.0f);
		UE_LOG(LogTemp, Warning, TEXT("UAshenDialogueChoiceEvaluator: Lens of Grace -> Weaver Stance (+25%% Burnout Decay, Trust: %.2f)"),
			CurrentTrustVector.KaelenToSerafinaTrust);
		break;

	case EInterpretiveTherapyLens::Utility:
		CurrentStance = ECompiledRelationalStance::PredatorStance;
		OutBurnoutDecayModifier = 0.90f;
		OutTrustDelta = -0.05f;
		CurrentTrustVector.KaelenToSerafinaTrust = FMath::Clamp(CurrentTrustVector.KaelenToSerafinaTrust + OutTrustDelta, 0.0f, 1.0f);
		UE_LOG(LogTemp, Warning, TEXT("UAshenDialogueChoiceEvaluator: Lens of Utility -> Predator Stance (+15%% Dark Power, Trust: %.2f)"),
			CurrentTrustVector.KaelenToSerafinaTrust);
		break;
	}
}
