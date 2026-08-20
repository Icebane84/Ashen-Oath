// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenCombatStanceTypes.h"
#include "AshenCombatStanceMasterBridge.generated.h"

/**
 * UAshenCombatStanceMasterBridge
 * Master domain bridge broadcasting stance switches, flank executions, and perfect parry events across domain subsystems.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCombatStanceMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCombatStanceMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bCombatBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastStanceChanged(ECombatStance NewStance);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastFlankExecuted(float FlankDamage, float AngleDegrees);
};
