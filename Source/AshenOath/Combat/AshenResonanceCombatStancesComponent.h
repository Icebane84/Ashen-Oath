// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenResonanceCombatStancesComponent.generated.h"

UENUM(BlueprintType)
enum class EAshenCombatStance : uint8
{
	GuardianStance          UMETA(DisplayName = "Guardian Stance (Defensive / Guard Focus)"),
	ResonantShatterStance   UMETA(DisplayName = "Resonant Shatter Stance (Posture Break Focus)"),
	VoidVesselStance        UMETA(DisplayName = "Void Vessel Stance (High Aggro / Deception Focus)")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCombatStanceChangedSignature, EAshenCombatStance, NewStance, float, FrameSpeedMultiplier);

/**
 * UAshenResonanceCombatStancesComponent
 *
 * Dynamic combat stance component switching between Guardian, Resonant Shatter, and Void Vessel stances.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenResonanceCombatStancesComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenResonanceCombatStancesComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|CombatStance")
	void SwitchStance(EAshenCombatStance NewStance);

	UFUNCTION(BlueprintPure, Category = "AshenOath|CombatStance")
	EAshenCombatStance GetCurrentStance() const { return CurrentStance; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CombatStance|Events")
	FOnCombatStanceChangedSignature OnCombatStanceChanged;

private:
	EAshenCombatStance CurrentStance = EAshenCombatStance::GuardianStance;
};
