// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenMemoryPalaceSanctuaryAltarActor.generated.h"

/**
 * AAshenMemoryPalaceSanctuaryAltarActor
 * Central sanctuary altar anchoring Kaelen's Mindscape memory topology and unsealing Lorekeeper records.
 */
UCLASS()
class ASHENOATH_API AAshenMemoryPalaceSanctuaryAltarActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenMemoryPalaceSanctuaryAltarActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Memory")
	bool bIsSanctuaryActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	bool ConsecrateSanctuaryAltar(AActor* InteractingPlayer);
};
