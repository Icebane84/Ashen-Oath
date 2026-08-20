// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenEpistemicConsequenceTypes.h"
#include "AshenEpistemicMasterBridge.generated.h"

/**
 * UAshenEpistemicMasterBridge
 * Master domain bridge routing canonical combat events through the 5-layer epistemic pipeline.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEpistemicMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEpistemicMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bEpistemicBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastEpistemicEventDispatched(const FCanonicalCombatEvent& Event);
};
