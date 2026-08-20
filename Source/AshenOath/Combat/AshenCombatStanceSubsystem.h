// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Combat/AshenCombatStanceTypes.h"
#include "AshenCombatStanceSubsystem.generated.h"

/**
 * UAshenCombatStanceSubsystem
 * GameInstance Subsystem managing active combat stances (Flow, Aegis, Berserk), stance transitions, and stance cooldown timers.
 */
UCLASS()
class ASHENOATH_API UAshenCombatStanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Combat")
	ECombatStance ActiveStance = ECombatStance::Flow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float StanceSwitchCooldown = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool SwitchStance(ECombatStance NewStance);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	ECombatStance GetActiveStance() const { return ActiveStance; }
};
