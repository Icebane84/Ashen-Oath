// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenLivingCodexTypes.h"
#include "AshenLivingCodexMasterBridge.generated.h"

/**
 * UAshenLivingCodexMasterBridge
 * Master domain bridge broadcasting codex unlock events, semantic mentions, and psychological tone shifts across subsystems.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLivingCodexMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLivingCodexMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bCodexBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastCodexUnlocked(FName EntryID, ECodexFaction Faction);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastPsychologicalToneChanged(EPsychologicalTone NewTone);
};
