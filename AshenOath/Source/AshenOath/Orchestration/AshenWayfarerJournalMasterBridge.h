// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWayfarerJournalMasterBridge.generated.h"

/**
 * UAshenWayfarerJournalMasterBridge
 * Master bridge broadcasting page turns, marginalia unlocks, and psychological state shifts across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWayfarerJournalMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWayfarerJournalMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bJournalBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastJournalPulse(FName EntryID, bool bGuardedFriction);
};
