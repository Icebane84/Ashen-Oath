// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenLivingJournalConsequenceTypes.h"
#include "AshenLivingJournalSaveGameAdapter.generated.h"

/**
 * UAshenLivingJournalSaveGameAdapter
 * Serializes all authored multi-author journal pages, unlocked frame perks, and map constellation node states to save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLivingJournalSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLivingJournalSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveJournalProgress(int32 AuthoredPagesCount, int32 UnlockedPerksCount);
};
