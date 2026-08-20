// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenCombatEcosystemTypes.h"
#include "AshenEcosystemMasterBridge.generated.h"

/**
 * UAshenEcosystemMasterBridge
 * Master domain bridge linking TAM-001 Symbiotic Resonance with boss phase transitions and UI-less HUD suppression.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEcosystemMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEcosystemMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bEcosystemBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastResonanceUnlocked();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastBossPhaseAdvanced(EBossPuzzlePhase NextPhase);
};
