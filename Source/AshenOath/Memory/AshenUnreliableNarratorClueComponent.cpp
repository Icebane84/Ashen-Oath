// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Memory/AshenUnreliableNarratorClueComponent.h"

UAshenUnreliableNarratorClueComponent::UAshenUnreliableNarratorClueComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenUnreliableNarratorClueComponent::BeginPlay() { Super::BeginPlay(); }

FText UAshenUnreliableNarratorClueComponent::ScrambleLoreInscription(FText OriginalText, float SanityLevel)
{
	if (SanityLevel < 0.30f)
	{
		bCurrentClueDeceptive = true;
		FText Scrambled = FText::FromString(TEXT("[...THE ASHES BLEED REVERSED WHISPERS...] ") + OriginalText.ToString());
		UE_LOG(LogTemp, Warning, TEXT("UAshenUnreliableNarratorClueComponent: Lore inscription scrambled by hallucinatory perception!"));
		return Scrambled;
	}
	bCurrentClueDeceptive = false;
	return OriginalText;
}

bool UAshenUnreliableNarratorClueComponent::EvaluateClueDeception(FName ClueID, float CorruptionPercentage)
{
	bCurrentClueDeceptive = (CorruptionPercentage >= 50.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUnreliableNarratorClueComponent: Clue %s evaluated for deception at corruption %.1f%% -> %s"),
		*ClueID.ToString(), CorruptionPercentage, bCurrentClueDeceptive ? TEXT("DECEPTIVE") : TEXT("GENUINE"));
	return bCurrentClueDeceptive;
}
