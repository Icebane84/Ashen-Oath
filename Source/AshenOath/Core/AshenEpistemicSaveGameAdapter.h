// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenEpistemicConsequenceTypes.h"
#include "AshenEpistemicSaveGameAdapter.generated.h"

/**
 * UAshenEpistemicSaveGameAdapter
 * Serializes the immutable Layer 0 canonical history log and consequence profile records to save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEpistemicSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEpistemicSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveEpistemicHistory(int32 TotalEventsCount, int32 MilestoneEventsCount);
};
