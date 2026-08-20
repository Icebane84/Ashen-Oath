// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenUnreliableNarratorClueComponent.generated.h"

/**
 * UAshenUnreliableNarratorClueComponent
 * Scrambles world lore inscriptions and journal clues when Kaelen's sanity is compromised.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenUnreliableNarratorClueComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenUnreliableNarratorClueComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Narrative")
	bool bCurrentClueDeceptive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	FText ScrambleLoreInscription(FText OriginalText, float SanityLevel);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	bool EvaluateClueDeception(FName ClueID, float CorruptionPercentage);
};
