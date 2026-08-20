// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWayfarerJournalSaveGameAdapter.generated.h"

/**
 * UAshenWayfarerJournalSaveGameAdapter
 * Serializes discovered entries, unlocked marginalia, and ink-bleed states to disk.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWayfarerJournalSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWayfarerJournalSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeJournalStateToSave(int32 DiscoveredEntryCount);
};
