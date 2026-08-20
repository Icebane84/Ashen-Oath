// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenLivingJournalConsequenceTypes.h"
#include "AshenLivingJournalMasterBridge.generated.h"

/**
 * UAshenLivingJournalMasterBridge
 * Master domain bridge broadcasting somatic resolution entries, tactical frame perk unlocks, and constellation map updates across subsystems.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLivingJournalMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLivingJournalMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bJournalBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastResolutionRecorded(FName MonsterID, EJournalPerspectiveType Perspective);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastConstellationSectorUpdated(FName SectorID, EConstellationNodeVisual VisualState);
};
