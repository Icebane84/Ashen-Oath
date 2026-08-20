// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenBossInquisitionCompanionReactivityAdapter.generated.h"

/**
 * UAshenBossInquisitionCompanionReactivityAdapter
 * Companions coordinate focus fire and yell tactical warnings during boss phase shifts.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossInquisitionCompanionReactivityAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBossInquisitionCompanionReactivityAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerCompanionBossReaction(FName CompanionID, uint8 BossPhaseIndex);
};
